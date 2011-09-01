/*
 *  ACM Online
 *  Pinocchio - Problem 1053
 *
 *  Œmp†rtim pƒn† nu se mai poate
 */


#include <stdio.h>

long n, s, a, b, t;


int main ()
{
	long i;
	scanf ("%ld %ld", &n, &s);
	for (i = 1; i < n; i++)
	{
		a = s;
		scanf("%ld", &b);
		while (a % b > 0)
			a = a % b, t = a, a = b, b = t;
		s = b;
	}
	printf("%ld\n", s);
    return 0;
}
