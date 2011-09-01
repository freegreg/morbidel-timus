/*
 *  ACM Timus Online
 *  Pool
 */

#include <stdio.h>
#include <math.h>

double W, D, X0, Y0, X1, Y1, Dist;


int main()
{
	char ch;


	scanf ("%lf %lf %lf %lf %lf %lf", &W, &D, &X0, &Y0, &X1, &Y1);

	while (scanf("%c", &ch) == 1)
	{
		if (ch == 'F')
			Y0 = -Y0;
		if (ch == 'B')
			Y0 = 2 * D - Y0;
		if (ch == 'L')
			X0 = -X0;
		if (ch == 'R')
			X0 = 2 * W - X0;
	}

	Dist = sqrtl((X0 - X1) * (X0 - X1) + (Y0 - Y1) * (Y0 - Y1));

	printf("%.4lf\n", Dist);

	
	return 0;
}

