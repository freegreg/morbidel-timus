/*
 *  ACM Timus Contest, 13 Aprilie 2004
 *  Problem G - Some words about sport
 */

#include <stdio.h>

int N, A[101][101];



void readdata()
{
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &A[i][j]);
}

void solve()
{
	int i, j, k;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= i; j++)
			printf("%d ", A[i - j + 1][j]);
	for (i = 2; i <= N; i++)
		for (j = N, k = i; j > 0 && k <= N; j--, k++)
			printf("%d ", A[j][k]);
}

int main()
{
	readdata();
	solve();

	return 0;
}
