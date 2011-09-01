/*
 *  ACM Online
 *  Garland - Problem 1066
 *
 *  solutie: a[k] = ((n - k)A + (k - 1)B) / (n - 1) - (k - 1)(n - k) si scoatem
 *  b-ul minim de aici baleind toate k-urile...
 */

#include <stdio.h>

long double a, b, sol = 1e10;
int n;


int check()
{
	int k;
	long double ak;
	for (k = 1; k <= n; k++)
	{
		ak = (a * (n - k) + b * (k - 1)) / (n - 1) - (n - k) * (k - 1);
		if (ak < -0.001) return 0;
	}
	return 1;
}

int main()
{
	int k;

	scanf("%d %Lf", &n, &a);
	for (k = 2; k <= n; k++)
	{
		b = ((double)(n - k) * (n - 1) * (k - 1) - a * (n - k)) / (k - 1);
		if (b < sol && check())
			sol = b;
	}
	printf("%.2Lf\n", sol);

	return 0;
}
