// ACM Online
// Handhakes - Problem 1194

#include <stdio.h>

long n, k;

void main()
{
	scanf("%ld %ld", &n, &k);
	printf("%ld", (n - 1) * n / 2 - k);
}