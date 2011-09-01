/*
 *  ACM Timus Online
 *  Domino Dots - Problem 1502
 */

#include <stdio.h>

#define S(n) ((n) * (n + 1) / 2)

int N;
__int64 Sol = 0;


int main()
{
	int i;


	scanf("%d", &N);

	Sol = S(N);

	for (i = 1; i <= N; i++)
		Sol += (S(N) - S(i - 1)) + i * (N + 1 - i);

	printf("%I64d\n", Sol);


	return 0;
}
