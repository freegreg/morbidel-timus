/*
 *  ACM Timus Online
 *  Devil's Sequence - Problem 1605
 */

#include <stdio.h>

int N;


int main()
{
	int i;
	long double x0 = 0, x1 = 1, xn;

	scanf("%d", &N);

	printf("x[ 0] = %.20Lf\n", x0);
	printf("x[ 1] = %.20Lf\n", x1);
	for (i = 2; i <= N; i++)
	{
		xn = (x1 + x0) / 2;
		printf("x[%2.d] = %.20Lf\n", i, xn);

		x0 = x1;
		x1 = xn;
	}



	return 0;
}
