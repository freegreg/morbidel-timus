/*
 *  ACM Timus Online
 *  Idempotents - Problem 1204
 *
 *  solutie: din x(x-1) div cu n si n = p*q -> x div cu p si x-1 div cu q sau invers. Dar ele difera prin 1
 *  si din def Euclid(p, q) => 1 = xp + yq, xp e o solutie daca e > 0 sau 1-xp daca e < 0. 
 *  A doua solutie e n + 1 - prima...
 */

#include <stdio.h>

long n, p, q, k, x1, x2, x, y;
int ciur[32000L]; /*  ciur  */


void euclid(long a, long b)
{
	long bakx;

	if (!b) 
		x = 1, y = 0;
	else
	{
		euclid(b, a % b);
		bakx = x; 
		x = y;
		y = bakx - (long)(a / b) * y;
	}
}

int main()
{
	/*  ciur pana la 32000  */
	for (x = 2; x <= 16000; x++)
		for (y = 2; x * y <= 32000; y++)
			ciur[x * y] = 1;
	for (x = 2; x <= 32000; x++)
		if (!ciur[x])
			ciur[++ciur[0]] = x;

	scanf("%ld", &k);

	for (; k--; )
	{
		scanf("%ld", &n);
		for (x = 1; x <= ciur[0]; x++)
			if (n % ciur[x] == 0)
				p = ciur[x], x = ciur[0];
		q = n / p;
		euclid(p, q);
		x1 = (p * x < 0) ? 1 - p * x : p * x;
		x2 = n + 1 - x1;
		if (x1 > x2) 
			x = x1, x1 = x2, x2 = x;
		printf("0 1 %ld %ld\n", x1, x2);
	}

	return 0;
}
