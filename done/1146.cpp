/*
 *  ACM Online
 *  Maximum Sum - Problem 1146
 *
 *  sume partiale...
 */

#include <stdio.h>

#define MAXN 101

long n, suma, summax, a[MAXN][MAXN];


void readdata()
{
	int i, j;
	scanf("%ld", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%ld", &a[i][j]);
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
}

long sum(int l1, int c1, int l2, int c2)
{
	return (a[l2][c2] - a[l2][c1 - 1] - a[l1 - 1][c2] + a[l1 - 1][c1 - 1]);
}

void solve()
{
	int l1, c1, l2, c2;

	summax = -1e7;
	for (l1 = 1; l1 <= n; l1++)
		for (c1 = 1; c1 <= n; c1++)
			for (l2 = l1; l2 <= n; l2++)
				for (c2 = c1; c2 <= n; c2++)
				{
					suma = sum(l1, c1, l2, c2);
					if (suma > summax) summax = suma;
				}

	printf("%ld\n", summax);
}

int main()
{
	readdata();
	solve();
	return 0;
}
