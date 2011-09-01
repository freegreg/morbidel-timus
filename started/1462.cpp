/*
 *  ACM Timus Online
 *  Uncle Scrooge's Gold - Problem 1462
 *  
 *  Solution: We need the trunc(F[2n] / F[n]) where F[n] are the Fibonacci numbers
 *				From the formula F[n] = F[k]*F[n-k+1] + F[k-1]*F[n-k] we get the solution (for n = 2n and k = n) F[n-1] + F[n+1]
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define	BASE	10000

long N;
typedef long BIGNUM[4096];
BIGNUM t2, t1, t;


void BigAdd(BIGNUM &a, BIGNUM b)
{
	int i, k = 0;

	if (b[0] > a[0])
		a[0] = b[0];

	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / BASE, a[i] %= BASE;
	if (k)
		a[++a[0]] = k;
}

int main()
{
	int i;


	t2[0] = t1[0] = 1;
	t2[1] = 0;
	t1[1] = 1;
	scanf("%d", &N);

	clock_t start = clock();
	for (i = 2; i <= N + 1; i++)
	{
		memset(t, 0, sizeof(t));
		t[0] = 1; t[1] = 0;
		BigAdd(t, t1);
		BigAdd(t, t2);

		if (i != N + 1)
		{
			memcpy(t2, t1, sizeof(t1));
			memcpy(t1, t, sizeof(t));
		}
	}
	BigAdd(t, t2); // t = t(f[n+1]) + t2(f[n-1])
	clock_t end = clock();

	printf("Time elapsed: %.4lf\n", (double)(end - start) / CLK_TCK);
	/*printf("The %dth Fibonacci number is: \n", N);*/
	printf("%d", t[t[0]]);
	for (i = t[0] - 1; i > 0; i--)
		printf("%04ld", t[i]);
	printf("\n");


	return 0;
}
