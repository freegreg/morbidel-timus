/*
 *  ACM Timus Online
 *  Something easier - Problem 1356
 */

#include <stdio.h>

#define MAXN 100000

int T, N;
int Ciur[MAXN + 1], Tp;



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

void Decompose(long n, int &p1, int &p2, int &p3)
{
	int i, j, nn = n;

	p1 = p2 = p3 = 0;

	for (i = 0; i <= Tp; i++)
		for (j = 0; j <= 1000; j++)
		{
			n = nn;

			p1 = Ciur[i];
			n -= p1;

			if (n == 0)
				return;

			if (n > 0)
			{
				p2 = Ciur[j];
				n -= p2;

				if (n == 0)
					return;

				if (n > 0 && prime(n))
				{
					p3 = n;
					return;
				}
			}
		}
}

int main()
{
	int i, j, p1, p2, p3;

	N = MAXN;

	for (i = 2; i <= N; i++)
		if (!Ciur[i])
			for (j = 2; i * j <= N; j++)
				Ciur[i * j] = 1;

	for (i = 2; i <= N; i++)
		if (!Ciur[i])
			Ciur[++Ciur[0]] = i;

	Tp = Ciur[0];
	Ciur[0] = 0;


	for (scanf("%d", &T); T--; )
	{
		scanf("%d", &N);

		Decompose(N, p1, p2, p3);

		if (p1 > 0)
			printf("%d ", p1);
		if (p2 > 0)
			printf("%d ", p2);
		if (p3 > 0)
			printf("%d ", p3);
		printf("\n");
	}

	return 0;
}
