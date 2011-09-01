// Problem 1209: 1, 10, 100, 100
// ACM Online -> acm@timus.ru

#include <stdio.h>
#include <math.h>

long nteste, digit;


int good(long digit)
{
	long double p = sqrtl(8 * (double)digit - 7);
	return (p == (long)p) ? 1 : 0;
}
int main()
{
	scanf("%d", &nteste);
	for (; nteste--; )
	{
		scanf("%ld", &digit);
		if (good(digit)) printf("1 ");
			else printf("0 ");
	}
	return 0;
}
