// ACM Online
// Sum - Problem 1068

#include <stdio.h>

long n, sum;

void main()
{
	scanf("%ld", &n);
	if (n < 0)
		n = -n, sum = n * (n + 1) / 2 - 1, sum *= -1;
	else
		sum = n * (n + 1) / 2;
	if (!n) sum = 1;
	printf("%ld", sum);
}
