/*
 *  ACM Timus Online
 *  Mars satellites - Problem 1294
 *
 *  solutie: ungiurile DAC si DBC sunt egale si e usor...
 */

#include <stdio.h>
#include <math.h>

int A, B, C, D;
double Cos, Dist;


int main()
{
	scanf("%d %d %d %d", &A, &B, &C, &D);

	if (A * B == C * D)
	{
		printf("Impossible.\n");
		return 0;
	}

	Cos = A * A + B * B - C * C - D * D;
	Cos /= 2 * (A * B - C * D);
	Dist = sqrtl(A * A + B * B - 2 * A * B * Cos) * 1000;

	printf("Distance is %.0lf km.\n", Dist);

	return 0;
}
