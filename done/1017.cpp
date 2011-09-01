/*
 *  ACM Online
 *  The Staircases - Problem 1017
 *
 *  dupa 1h de calcule am gasit: Fie P(n, k) numarul de k-descompuneri ale lui
 *  n; P(n, k) = sum† cu i de la 1 la max(n, k) din P(n - k * i, k - 1)
 *  in final se aduna toate P(n, 2..maxk(n))  (marf† nu?)
 *  se cer doar cele cu >= 2 trepte...
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

long n, k;
__int64 rez = 0, memo[501][32];


long maxk(long n)
{
	return (sqrtl(8 * n + 1) - 1) / 2;
}

long max(long n, long k)
{
	return (2 * n - k * (k - 1)) / (2 * k);
}

__int64 p(long n, long k)
{
	int i;
	__int64 tot = 0;
	if (k == 1) return 1;
	else
	for (i = 1; i <= max(n, k); i++)
	{
		if (!memo[n - k * i][k - 1])
			memo[n - k * i][k - 1] = p(n - k * i, k - 1);
		tot += memo[n - k * i][k - 1];
	}
	return tot;
}

int main()
{
	memset(memo, 0, sizeof(memo));
	scanf("%ld", &n);

	for (k = 2; k <= maxk(n); k++)
		rez += p(n, k);
	printf("%I64d\n", rez);

	return 0;
}
