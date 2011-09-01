/*
 * ACM Timus Online
 * Problem 1001 - Reverse root
 */


#include <cstdio>
#include <cmath>
#include <iostream>

int Len, N;
char Raw[270000];
double V[131072];


double sqrt2(double n)
{
	double l, r, x, sq;

	l = 0;
	r = n;
	while (r - l > 0.000001)
	{
		x = (l + r) / 2;
		sq = x * x;

		if (sq > n)
			r = x;
		else
			l = x;
	}

	return (l + r) / 2;
}

void ProcessInput()
{
	bool number;
	double x = 0;
	int i;

	number = false;
	for (i = 0; i < Len; i++)
	{
		char ch = Raw[i];

		if (ch >= '0' && ch <= '9')
		{
			if (!number)
			{
				number = true;
				x = ch - '0';
			}
			else
			{
				x = x * 10 + ch - '0';
			}
		}
		else if (number)
		{
			number = false;
			V[N++] = x;
		}
	}

	if (number)
		V[N++] = x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	N = 0;
	//Len = fread(Raw, sizeof(char), 262144, stdin);
	//ProcessInput();

	int i;
	double x;

	while (scanf("%lf", &x) == 1)
	{
		V[N++] = x;
	}

	for (i = N - 1; i >= 0; i--)
		printf("%.4lf\n", sqrt(V[i]));

	return 0;
}
