/*
 *  ACM Online
 *  A simple game on a grid - Problem 1051
 *
 *  solutie: N mod 3 sau M mod 3 = 0 -> 2 altfel 1
 *  exceptie M sau N = 1 -> cel†lalt div 2...
 */

#include <stdio.h>

long m, n, sol;


int main()
{
	scanf("%ld %ld", &m, &n);
	if (m > n) sol = m, m = n, n = sol;
	if (m == 1) sol = (n + 1) / 2;
	else
	if (m % 3 == 0 || n % 3 == 0) sol = 2;
	else sol = 1;
	printf("%ld\n", sol);
	return 0;
}
