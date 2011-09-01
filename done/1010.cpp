/*
 *  ACM Online
 *  Discrete Function - Problem 1010
 *  cele 2 cu panta cea mai mare...
 */


#include <stdio.h>
#include <math.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

double a, b, dif = - 1;
long n, poz, i;

int main()
{
	scanf("%ld %lf", &n, &a);
	for (i = 2; i <= n; i++)
    {
		scanf("%lf", &b);
		if (abs(b - a) > dif)
			dif = abs(b - a), poz = i;
		a = b;
	}
	printf("%ld %ld\n", poz - 1, poz);
	return 0;
}
