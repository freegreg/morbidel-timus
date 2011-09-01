/*
 *  ACM Timus Online
 *  Problem of Ben Betsalel - Problem 1336
 *
 *  solutie: K = fact primi ai lui N cu exponent impar la a treia
 */

#include <stdio.h>

#define BASE 1000000

typedef __int64 HUGE[200];
struct set
{
	int nf;
	__int64 Exp[10], Prime[10];
} MM, NN, KK;

HUGE M, K;
__int64 N;


void PrintHuge(HUGE a)
{
	printf("%I64d", a[a[0]]);
	
	for (__int64 i = a[0] - 1; i; i--)
		printf("%06d", a[i]);
	printf("\n");
}

void Imul(HUGE &a, __int64 x)
{
	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / BASE, a[i] %= BASE;

	while (k)
		a[++a[0]] = k % BASE, k /= BASE;
}

void Prime(__int64 &n, __int64 first, __int64 &fp, __int64 &exp)
{
	for (__int64 i = first; i * i <= n; i++)
		if (n % i == 0)
		{
			fp = i; exp = 0;
			while (n % i == 0)
				n /= i, exp++;

			return;
		}

	fp = n;
	exp = n = 1;

	return;
}

__int64 main()
{
	int i, j;


	scanf("%I64d", &N);

	for (i = 0; N > 1; i++)
		Prime(N, (i == 0 ? 2 : NN.Prime[i - 1] + 1), NN.Prime[i], NN.Exp[i]);

	NN.nf = MM.nf = KK.nf = i + 1;
	K[0] = K[1] = M[0] = M[1] = 1;

	for (i = 0; i < NN.nf; i++)
	{
		MM.Prime[i] = NN.Prime[i];
		MM.Exp[i] = NN.Exp[i];

		if (NN.Exp[i] & 1)
		{
			KK.Prime[i] = NN.Prime[i];
			MM.Exp[i] = (KK.Exp[i] = 3) + NN.Exp[i];
			Imul(K, KK.Prime[i]);
		}

		for (j = 0; j < MM.Exp[i] / 2; j++)
			Imul(M, MM.Prime[i]);
	}

	PrintHuge(M);
	PrintHuge(K);


	return 0;
}
