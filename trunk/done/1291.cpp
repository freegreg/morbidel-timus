/*
 *  ACM Timus Online
 *  Gear Wheels - Problem 1291
 *
 *  solutie: BF
 */

#include <stdio.h>

#define MAXN 1001
#define abs(x) ((x) > 0 ? (x) : -(x))

short int N, one, Q[MAXN], Flag[MAXN], A[MAXN][MAXN];
struct wheel
{
	int sgn, gears;
	__int64 V1, V2;
} W[MAXN];



void readdata()
{
	int i, nod;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &W[i].gears);
		while (1)
		{
			scanf("%d", &nod);
			if (!nod) break;
			A[i][nod] = A[nod][i] = 1;
		}
	}
	scanf("%d %d", &one, &nod);

	W[one].V1 = abs(nod); W[one].V2 = 1;
	W[one].sgn = (nod > 0) ? 1 : -1;
}

__int64 cmmdc(__int64 a, __int64 b)
{
	return !b ? a : cmmdc(b, a % b);
}

void solve()
{
	__int64 d;
	int i, nod, l, ml;
	
	Flag[one] = 1;
	for (Q[ml = l = 0] = one; l <= ml; l++)
		for (nod = Q[l], i = 1; i <= N; i++)
			if (A[nod][i] && !Flag[i])
			{
				Q[++ml] = i;
				Flag[i] = 1;
				W[i].sgn = -W[nod].sgn;
				W[i].V1 = W[nod].V1 * W[nod].gears;
				W[i].V2 = W[nod].V2 * W[i].gears;
				d = cmmdc(W[i].V1, W[i].V2);
				W[i].V1 /= d; W[i].V2 /= d;
			}

	for (i = 1; i <= N; i++)
	{
		W[i].V1 *= (__int64)W[i].sgn;
		if (W[i].V1)
			printf("%I64d/%I64d\n", W[i].V1, W[i].V2);
		else
			printf("0/1\n");
	}
}

int main()
{
	readdata();
	solve();
	return 0;
}
