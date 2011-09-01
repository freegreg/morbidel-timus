/*
 *  ACM Timus Online
 *  Hyperjump - Problem 1296
 *
 *  solutie: subsecventa de suma maxima
 */

#include <stdio.h>

__int64 N, X, Smax, Scur;



int main()
{
	long i;

	scanf("%I64d %I64d", &N, &X);

	Scur = Smax = X;

	for (i = 2; i <= N; i++)
	{
		scanf("%I64d", &X);

		if (Scur < 0)
			Scur = X;
		else
			Scur += X;
		if (Scur > Smax)
			Smax = Scur;
	}

	if (Smax < 0) Smax = 0;

	printf("%I64d\n", Smax);

	return 0;
}
