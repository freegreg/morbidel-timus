/*
 *  ACM Timus Online
 *  Minimal coverage - Problem 1303
 */

#include <stdio.h>
#include <stdlib.h>

#define input "file.in"
#define output "file.out"
#define MAXN 100

int M, N = 0, HN, T[101];
struct set
{
	long l, r;
} S[MAXN];


void readdata()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%ld", &M);

	while (scanf("%d %d", &S[N].l, &S[N].r) == 2)
	{
		if (S[N].r <= 0 && S[N].l + S[N].r != 0) 
			N--;
		N++;
	}
	N--;
}

int cmp (const void *a, const void *b)
{
	#define p(a) ((set *)a)

	return (p(a) -> l < p(b) -> l || p(a) -> l == p(b) -> l && p(a) -> r < p(b) -> r) ? -1 : 1;
}

void solve()
{
	#ifndef ONLINE_JUDGE
	freopen(output, "w", stdout);
	#endif

	
	qsort( S, N, sizeof( set), cmp);

	for ( int i = 0; i <= 101; i++)
		T[i] = 100000;


	T[S[0].r] = 1;
	for ( i = 1; i < N; i++)
	{
		if ( S[i].l > S[i - 1].r)
		{
			printf("No solution\n");
			return;
		}

		if (T[S[i].r] > T[S[i - 1].r] + 1)
			T[S[i].r] = T[S[i - 1].r] + 1;


	}
}

int main()
{
	readdata();
	solve();

	return 0;
}
