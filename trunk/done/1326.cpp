/*
 *  ACM Timus Online
 *  Bottle taps
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define input	"file.in"
#define MAXN	1024
#define INF		32767
#define min(a, b) ((a) > (b) ? (b) : (a))

short A[MAXN * MAXN];
int M, N;
int Cost[128];
long Offerts[128], Goal, Costmin;



void Readdata()
{
	int i, j, val;


	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif


	scanf("%d", &N);
	for (i = 0; i < N; i++)
		Offerts[i] = (long)1 << i, scanf("%d", Cost + i);

	scanf("%d", &M);
	for (i = N; i < N + M; i++)
		for (Offerts[i] = 0, scanf("%d %d", Cost + i, &j); j--; )
			scanf("%d", &val), Offerts[i] += (long)1 << (val - 1);
	
	for (scanf("%d", &j), Goal = i = 0; i < j; i++)
		scanf("%d", &val), Goal += (long)1 << (val - 1);

	M += N;
}

void Solve()
{
	int i, j;


	for (i = 0; i < (long)1 << 20; i++)
		A[i] = INF;

	for (i = 0; i < M; i++)
		if (A[Offerts[i]] > Cost[i])
			A[Offerts[i]] = Cost[i];


	for (i = 0; i < M; i++)
		for (j = MAXN * MAXN - 1; j >= 0; j--)
			if (A[j] != INF)
				A[j | Offerts[i]] = min(A[j | Offerts[i]], A[j] + Cost[i]);


	for (Costmin = INF, i = MAXN * MAXN - 1; i >= 0; i--)
		if ((i & Goal) == Goal && A[i] < Costmin)
			Costmin = A[i];

	printf("%d\n", Costmin);
}

int main()
{
	Readdata();
	Solve();

	return 0;
}
