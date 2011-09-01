/*
 * ACM Timus
 * Uncle Scrooge's Gold
 */


#include <stdio.h>
#include <string.h>
#include <time.h>

#define BASE	1000000
#define	FMT		"%06I64d"
#define HASH	2048

__int64 N;
typedef __int64 BIGNUM[4096];
BIGNUM Table[HASH];
BIGNUM rez1, rez2;

void BigAdd(BIGNUM &a, BIGNUM b)
{
	__int64 i, k = 0;

	if (a[0] < b[0])
		a[0] = b[0];

	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / BASE, a[i] %= BASE;

	if (k)
		a[++a[0]] = k;
}

void BigMul(BIGNUM &a, BIGNUM b, BIGNUM c)
{
	BIGNUM rez;
	__int64 i, j, k;

	memset(rez, 0, sizeof(rez));

	rez[0] = b[0] + c[0] - 1;
	for (i = 1; i <= b[0]; i++)
		for (j = 1; j <= c[0]; j++)
			rez[i + j - 1] += b[i] * c[j];
	for (i = 1; i <= rez[0]; i++)
		k = rez[i] / BASE, rez[i] %= BASE, rez[i + 1] += k;
	if (k)
		rez[++rez[0]] = k;
	memcpy(a, rez, sizeof(rez));
}


void BuildTable(int n)
{
	int i;

	Table[0][0] = Table[1][0] = 1;
	Table[0][1] = 0;
	Table[1][1] = 1;

	for (i = 2; i <= n; i++)
	{
		BigAdd(Table[i], Table[i - 1]);
		BigAdd(Table[i], Table[i - 2]);
	}
}

void Fibonacci(__int64 n, BIGNUM &rez)
{
	BIGNUM f1, f2;
	if (n < HASH)
		memcpy(rez, Table[n], sizeof(Table[n]));
	else
	{
		memset(rez, 0, sizeof(rez));

		if (n & 1)	// f[2n-1] = f^2[n] + f^2[n-1]
		{
			Fibonacci((n + 1) / 2, f1);
			Fibonacci(n / 2, f2);

			BigMul(rez, f1, f1);
			memset(f1, 0, sizeof(f1));
			BigMul(f1, f2, f2);
			BigAdd(rez, f1);
		} else		// f[2n] = f[n]*(f[n-1] + f[n+1])
		{
			Fibonacci(n / 2 - 1, f1);
			Fibonacci(n / 2 + 1, f2);
			BigAdd(rez, f1);
			BigAdd(rez, f2);
			Fibonacci(n / 2, f1);
			BigMul(rez, rez, f1);
		}
	}
}

int main()
{
	scanf("%d", &N);

	//clock_t start = clock();
	BuildTable(HASH - 1);

	Fibonacci(N - 1, rez1);
	Fibonacci(N + 1, rez2);
	BigAdd(rez1, rez2);

	printf("%d", rez1[rez1[0]]);
	for (int i = rez1[0] - 1; i > 0; i--)
		printf(FMT, rez1[i]);
	printf("\n");

	//clock_t end = clock();

	//printf("Time = %.4lf\n", (double)(end - start)/CLK_TCK);

	return 0;
}
