/*
 *  ACM Timus Online
 *  How to become a star? - Problem 1259
 *
 *  solutie: x, x prim cu n, x < (n + 1) / 2
 */

#include <stdio.h>

long n, sol;


long cmmdc(long a, long b)
{
	return b ? cmmdc(b, a % b) : a;
}

int main()
{
	int i;

	scanf("%ld", &n);

	for (sol = 1, i = 2; 2 * i < n + 1; i++)
		sol += (cmmdc(n, i) == 1);

	printf("%ld\n", sol);

	return 0;
}
