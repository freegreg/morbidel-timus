/*
 * ACM Timus Online Judge Contest 15 October 2011
 * Problem C - Get-Together at Den's
 */

#include <cstdio>

int N;
double A[100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int i;
	double sum, med = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &A[i]);
		med += A[i];
	}

	med /= (double) (N + 1);

	for (i = 0; i < N; i++)
	{
		A[i] -= med;
	};

	sum = 0;
	for (i = 0; i < N; i++)
		if (A[i] > 0)
		{
			sum += A[i];
		}

	for (i = 0; i < N; i++)
		if (A[i] > 0)
		{
			printf("%d ", (int)(A[i] * 100 / sum));
		}
		else
		{
			printf("0 ");
		}

	return 0;
}