/*
 *  ACM Timus Online
 *  Chernobyl' Eagle on a Roof - Problem 1223
 *
 *  dinamica: a[i][j] -> i etaje, j oua. a[i][j] = 1 + a[i / 2][j]
 */

#include <stdio.h>

int Et, OO, Sol = 0, a[1001][1001];


int main()
{
	int i, j, k, min;

	Et = 100; OO = 3;

	for (i = 1; i <= Et; i++)
		for (j = 1; j <= OO; j++)
		{
			min = 1e9L;
			if (i == 1 || j == 1) 
			{
				a[i][j] = (i == 1) ? 1 : i;
				continue;
			}
			for (k = 1; k <= i / 2; k++)
				if (1 + a[k][j] + a[i - k][j] < min)
					min = 1 + a[k][j] + a[i - k][j];

			a[i][j] = min;
		}

	for (i = 1; i <= Et; i++)
		for (j = 1; j <= OO; j++)
			printf("(%d,%d) -> %d\n", i, j, a[i][j]);

	return 0;
}
