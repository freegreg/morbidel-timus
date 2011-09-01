/*
 *  ACM Timus Online
 *  Nikifor-2 - Problem 1071
 */

#include <stdio.h>

long x, y, l1, l2, sx[50], sy[50];


int main()
{
	long b, ox, oy;

	scanf("%ld %ld", &x, &y);

	for (b = 2; b <= 1000000L; b++)
	{
		ox = x; oy = y;
		sx[0] = sy[0] = 0;

		do
			sx[++sx[0]] = ox % b, ox /= b;
		while (ox > 1);
		if (ox)
			sx[++sx[0]] = ox;
		
		do
			sy[++sy[0]] = oy % b, oy /= b;
		while (oy > 1);
		if (oy)
			sy[++sy[0]] = oy;

		ox = sx[0]; oy = sy[0];

		while (ox)
		{
			if (sx[ox] == sy[oy])
				oy--;
			ox--;
			if (!oy) break;
		}
		if (!oy) break;
	}

	if (b == 1000001L)
		printf("No solution\n");
	else
		printf("%ld\n", b);

	return 0;
}
