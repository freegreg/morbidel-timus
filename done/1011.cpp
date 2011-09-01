/*
 *  ACM Online
 *  Conductors - Problem 1011
 */

#include <stdio.h>

#define EPS		1e-9

double P, Q;
int N;


double abs(double x)
{
	return (x > 0) ? x : -(x);
}

int main()
{
	int ip, iq;
	double rp, rq;

	scanf("%lf %lf", &P, &Q);
	for (N = 1; N <= 100000; N++)
	{
		ip = P * 0.01 * (double)N;
		iq = Q * 0.01 * (double)N;

		rp = P * 0.01 * (double)N;
		rq = Q * 0.01 * (double)N;

		if (iq - ip > EPS && abs(rp - (double)ip) > EPS && abs(rq - (double)iq) > EPS)
			break;
	}

	printf("%d\n", N);

	return 0;
}
