/*
 *  ACM Timus Online
 *  Bald spot revisited - Problem 1355
 */

#include <stdio.h>

long T, A, B, N, Sol;


long cmmdc(long a, long b)
{
	return !b ? a : cmmdc(b, a % b);
}

int prime(long n)
{
	int i;

	if (n == 1)
		return 0;

	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;

	return 1;
}

int main()
{
	long d;

	// 999999937

	for (scanf("%ld", &T); T--; )
	{
		Sol = 0;
		scanf("%ld %ld", &A, &B);

		if (A > B || cmmdc(A, B) != A)
			printf("0\n");
		else
		{
			N = B / A;

			if (prime(N)) Sol = 1;
			else
			for (d = 2; d * d <= N, N > 1; d++)
				while (N % d == 0)
					Sol++, N /= d;

			printf("%ld\n", Sol + 1);
		}
	}

	return 0;
}
