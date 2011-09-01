/*
 * ACM Timus Online
 * Dill - Problem 1731
 *
 * solution: caca
 */ 

#include <cstdio>

int M, N;

int main()
{
	int i;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= M; i++)
		printf("%d ", 1 + i * N);

	return 0;
}
