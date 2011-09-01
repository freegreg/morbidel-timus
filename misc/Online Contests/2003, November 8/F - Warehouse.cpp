/*
 *  ACM Timus Online Contest, 8 November 2003
 *  Problem 6 -> Warehouse
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 50010L

int n, m, k, a[MAXLEN], s[MAXLEN], sol;


int cmp(const void *arg1, const void *arg2)
{
   return *((int*)arg1) - *((int*)arg2);
}

int main()
{
	int i, j, p = 1, num, lim;

	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", &num);
			a[p++] = num;
		}
	n = n * m;
	qsort(a, n + 1, sizeof(int), cmp);

	s[0] = 0; s[1] = a[2] - a[1]; 
	for (i = 2; i < n; i++)
		s[i] = s[i - 1] + i * (a[i + 1] - a[i]);
	s[n] = 1e9L;
	
	for (i = 1; i <= n + 1; i++)
		if (k < s[i]) 
			lim = i, i = n;

	k -= s[lim - 1]; 
	sol = a[lim] + k / lim;
	printf("%d\n", sol);

	return 0;
}
