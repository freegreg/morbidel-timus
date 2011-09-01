/*
 *  ACM Timus Online
 *  Coupons - Problem 1480
 */

#include <stdio.h>

#define MAXN	51
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int N;
int A[MAXN][MAXN];


int main()
{
	scanf("%d", &N);

	int i, j;
	int c1 = 1, c2 = N * N, max = 0;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			A[i][j] = ((i + j) & 1) ? c1++ : c2--;
		}

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			max = MAX(max, A[i - 1][j] + A[i][j]);
			max = MAX(max, A[i + 1][j] + A[i][j]);
			max = MAX(max, A[i][j - 1] + A[i][j]);
			max = MAX(max, A[i][j + 1] + A[i][j]);
		}

	printf("%d\n", max);

	for (i = 1; i <= N; i++, printf("\n"))
		for (j = 1; j <= N; j++)
			printf("%d ", A[i][j]);

	return 0;
}
