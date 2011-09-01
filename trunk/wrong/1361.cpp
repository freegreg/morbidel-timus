/*
 *  ACM Timus Online
 *  Spaceology vs. Chronistics
 */

#include <stdio.h>

#define MAXN 131072
#define input "input.txt"
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

int N, A, B, Da, Db, LenA, LenB;
int Flag[MAXN], Edge[MAXN][2], Cycle[2][MAXN], CycleB[MAXN], S[MAXN], PosA[MAXN], PosB[MAXN];
long long Total;



void Readdata()
{
	int i, x;


	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d", &N);
	
	for (i = 1; i <= N; i++)
		while (1)
		{
			scanf("%d", &x);
			if (!x) break;

			if (!Edge[i][0])
				Edge[i][0] = x;
			Edge[i][1] = x;
		}
	scanf("%d %d", &A, &B);
}


void FindCycle(int pos, int &len, int &depl, int *cycle, int way)
{
	int i, nod = pos, d = 0;


	cycle[0] = 0;
	for (nod = pos; ; nod = Edge[nod][way])
		if (!Flag[nod] && (nod != pos || (nod == pos && d == 0)))
			Flag[nod] = d++, cycle[++cycle[0]] = nod;
		else break;
	depl = Flag[nod];
	len = cycle[0] - depl;

	for (i = 1; i <= N; i++)
		Flag[i] = 0;
}

int GetPosition(int way, int time, int len, int depl)
{
	if (time < depl)
		return Cycle[way][time + 1];
	else
		return Cycle[way][depl + 1 + (time - depl) % len];
}

long long Euclid(long long a, long long b, long long &x, long long &y)
{
	long long aux, d;

	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	else
	{
		d = Euclid(b, a % b, x, y);
		aux = y;
		y = x - y * (a / b);
		x = aux;
		return d;
	}
}

long long GetSolution(long long a, long long b, long long n) // ax + b = 0 (mod n)
{
	long long u, v, d, x;
	
	while (a < 0) a += n;
	while (b < 0) b += n;
	a %= n; b %= n;

	d = Euclid(a, n, u, v);


	if (b % d != 0)
		return -1;

	b /= d; a /= d; n /= d;

	x = -u * b;

	while (x < 0)
		x += n;

	return x;
}

void brute()
{
	int i, p1, p2;


	for (i = 0; i <= 1000000; i++)
	{
		p1 = GetPosition(0, i, LenA, Da);
		p2 = GetPosition(1, i, LenB, Db);

		if (p1 == p2)
		{
			printf("%d\n", i);
			return;
		}
	}

	printf("-1\n");
}

void Solve()
{
	int i, p1, p2;


	FindCycle(A, LenA, Da, Cycle[0], 0);
	FindCycle(B, LenB, Db, Cycle[1], 1);

	//brute();

	for (i = 0; i <= 5000000; i++)
	{
		p1 = GetPosition(0, i, LenA, Da);
		p2 = GetPosition(1, i, LenB, Db);

		if (p1 == p2)
		{
			printf("%d\n", i);
			return;
		}
	}

	S[0] = 0;

	for (i = Da + 1; i <= Cycle[0][0]; i++)
		Flag[Cycle[0][i]] = 1, PosA[Cycle[0][i]] = i - 1;

	for (i = Db + 1; i <= Cycle[1][0]; i++)
	{
		if (Flag[Cycle[1][i]])
			S[++S[0]] = Cycle[1][i];
		PosB[Cycle[1][i]] = i - 1;
	}

	long long sol, pa, pb;
	Total = (long long)1 << 62;
	for (i = 1; i <= S[0]; i++)
	{
		pa = PosA[S[i]];
		pb = PosB[S[i]];
		sol = GetSolution(LenB, pb - pa, LenA);
		if (sol != -1)
			Total = min(Total, sol * LenB + pb);
	}

	if (Total == (long long)1 << 62)
		Total = -1;
	printf("%lld\n", Total);
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
