/*
 * ACM Timus Online Judge Contest 15 October 2011
 * Problem I - Zinium 2
 *
 * Solution: If N = 3 + 6x or N even -> No solution.
 *			 Otherwise 2 4 6...1 3 5... is a solution.
 */

#include <cstdio>
#include <cstring>

#define MAXN		1024

int N, A[MAXN][MAXN], M[MAXN][MAXN];


void mark(int l, int c, int val)
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			M[i][j] = 0;
	// row and column
	for (i = 0; i < N; i++)
	{
		M[l][i] = 1;
		M[i][c] = 1;
	}

	// diagonals
	for (i = 0; i < N; i++)
	{
		M[(l + i) % N][(c + i) % N] = 1;
		M[(l + i) % N][(c - i + N) % N] = 1;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (M[i][j] == 1)
			{
				A[i][j] += val;
			}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int i;


	scanf("%d", &N);

	if ((N & 1) && (N % 6 != 3))
	{
		// generate solution: 2 4 6...1 3 5...
		printf("Yes\n");
		for (i = 2; i <= N; i += 2)
			printf("%d ", i);
		for (i = 1; i <= N; i += 2)
			printf("%d ", i);
	}
	else
	{
		printf("No\n");
	}
	
	return 0;
}