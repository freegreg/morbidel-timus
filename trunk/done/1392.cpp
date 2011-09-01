/*
 *  ACM Timus Online
 *  Dreaming of stars - Problem 1392
 */

#include <stdio.h>
#include <math.h>

#define input	"file.in"
#define MAXN	1024
#define SQR(x)	((x) * (x))

int N;
int Tata[MAXN], Rang[MAXN];
struct Star
{
	int x, y, z, r;
} S[MAXN];


void Readdata()
{
	int i;

	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d %d %d", &S[i].x, &S[i].y, &S[i].z, &S[i].r);
}

int find(int x)
{
	if (x != Tata[x])
		Tata[x] = find(Tata[x]);
	return Tata[x];
}

void join(int x, int y)
{
	if (Rang[x] > Rang[y])
		Tata[y] = x;
	else
	{
		if (Rang[x] == Rang[y]) Rang[y]++;
		Tata[x] = y;
	}
}

int Intersect(int i, int j)
{
	double dist = sqrtl(SQR(S[i].x - S[j].x) + SQR(S[i].y - S[j].y) + SQR(S[i].z - S[j].z));

	return (dist < S[i].r + S[j].r);
}

void Solve()
{
	int i, j;

	for (i = 0; i < N; i++)
		Tata[i] = i, Rang[i] = 0;

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (Intersect(i, j) && i != j)
				join(find(i), find(j));

	for (i = 0; i < N; i++)
		find(i), Rang[i] = 0;

	int k;

	for (i = 0; i < N; i++)
		if (!Rang[i])
		{
			Rang[i] = 1;
			printf("%d", i);
			k = find(i);
			for (j = 0; j < N; j++)
				if (j != i && k == find(j))
					printf(", %d", j), Rang[j] = 1;
			printf("\n");
		}
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
