/*
 *  ACM Timus Contest, 15 Aprilie 2004
 *  Problem C - The Hotel
 */

#include <stdio.h>

int N, X, A[101][101];


void diag(int l, int c)
{
	for (; l <= N && c <= N; l++, c++)
		A[l][c] = X++;
}

int main()
{
	int i, j;

	scanf("%d", &N);

	X = 1;

	for (i = N; i; i--)
		diag(1, i);
	for (i = 2; i <= N; i++)
		diag(i, 1);

	for (i = 1; i <= N; i++, printf("\n"))
		for (j = 1; j <= N; j++)
			printf("%d ", A[i][j]);

	return 0;
}
