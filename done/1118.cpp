/*
 *  ACM Online
 *  Nontrivial Numbers - Problem 1118
 *
 *  solutie: cel mai mare num†r prim e solutie (deci Œi lu†m descr.). Dac† nu
 *  exist† un num†r prim Œn interval atunci el nu e prea mare (intervalul) si
 *  calcul†m manual...
 */

#include <stdio.h>

long l1, l2, one = -1;
long double triv, tmin = 1e7;


int prim(long x)
{
	long i;
	for (i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

long trivy(long x)
{
	long j;
	triv = 1;
	for (j = 2; j * j <= x; j++)
		if (x % j == 0)
			triv += j + x / j;
	triv /= x;
	return triv;
}

int main()
{
	long i;

	scanf("%ld %ld", &l1, &l2);

	for (i = l2; i >= l1; i--)
		if (prim(i))
			one = i, i = l1;

	if (one == -1)
		for (i = l2; i >= l1; i--)
			if ((triv = trivy(i)) < tmin)
				tmin = triv, one = i;

	if (l1 == 1) one = 1;
	printf("%ld\n", one);

	return 0;
}
