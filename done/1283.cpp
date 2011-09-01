/*
 *  ACM Timus Online
 *  Dwarfs - Problem 1283
 *
 *  solutie: caut acel X maxim cu S * (1 - P)^X >= Smin
 */

#include <stdio.h>

long X, S, Smin;
long double rez, P;


int main()
{
	scanf("%ld %ld %lf", &S, &Smin, &P);

	P = 1 - P / 100;
	rez = S;

	for (X = 0; X <= 1e9L; X++)
	{
		if (rez <= Smin) break;
		rez *= P;
	}

	printf("%ld\n", X);

	return 0;
}
