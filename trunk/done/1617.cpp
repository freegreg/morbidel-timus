/*
 * ACM Timus Online
 * Flat Spots - Problem 1617
 *
 * solution: sum all counts/4
 */

#include <cstdio>
#include <string.h>

int N, C[1024];


int main()
{
	int i, x;


	memset(C, 0, sizeof(C));

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);
		C[x]++;
	}

	int sum = 0;

	for (i = 600; i <= 700; i++)
		sum += C[i] / 4;

	printf("%d", sum);

	return 0;
}
