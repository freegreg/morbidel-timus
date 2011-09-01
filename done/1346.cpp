/*
 *  ACM Timus Online
 *  Intervals of monotonicity
 */

#include <stdio.h>

long A, B, C = 1;


int main()
{
	long i, x, oldx, way = -1;

	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	scanf("%d %d %d", &A, &B, &oldx);


	for (i = A + 1; i <= B; i++)
	{
		scanf("%d", &x);

		if (way == -1 && x > oldx)
			way = 0;
		if (way == -1 && x < oldx)
			way = 1;

		if (way == 0 && x < oldx)
			C++, way = -1;
		else
		if (way == 1 && x > oldx)
			C++, way = -1;

		oldx = x;
	}


	printf("%d\n", C);


	return 0;
}
