/*
 *  ACM Timus Online
 *  Bill Clevers - Problem 1375
 */

#include <stdio.h>

long long P, K, X, Y;


long long SquareRoot(long long a, long long n)
{
	long long i;

	for (i = 0; 2 * i < n; i++)
		if ((i * i) % n == a)
			return i;
	return -1;
}

int main()
{
	scanf("%lld %lld", &K, &P);

	/* sweep all X */
	for (X = 0; X < P; X++)
	{
		/* x * x + y * y = k (mod p) */

		/* find y so that y * y = k - x*x (mod p) */
		/* Practically we have to solve 1132 now */
		long long a = K - X * X;

		while (a < 0)
			a += P;
		a %= P;
		Y = SquareRoot(a, P);

		if (Y != -1)
		{
			printf("%lld %lld\n", X, Y);
			return 0;
		}
	}

	printf("NO SOLUTION\n");

	return 0;
}

