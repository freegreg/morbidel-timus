/*
 *  ACM Timus Online
 *  Elections - Problem 1263
 *
 */

#include <stdio.h>
#include <string.h>

long m, n, flag[10010];


int main()
{
	long i, x;


	scanf("%ld %ld", &n, &m);

	memset(flag, 0, sizeof(flag));
	for (i = 0; i < m; i++)
	{
		scanf("%ld", &x);
		flag[x]++;
	}
	for (i = 1; i <= n; i++)
		printf("%.2lf%%\n", (double)flag[i] / m * 100);

	return 0;
}
