/*
 *  ACM Timus Online
 *  Taxi - Problem 1607
 */

#include <stdio.h>

int A, B, C, D;


int main()
{
	scanf("%d %d %d %d", &A, &B, &C, &D);

	while (A < C)
	{
		if (A + B > C)
		{
			A = C;
			break;
		}
		A += B;
		if (C - D < A) break;
		C -= D;
	}

	printf("%d\n", A);

	return 0;
}
