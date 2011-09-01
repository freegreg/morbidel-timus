/*
 *  ACM Online
 *  Bicoloured Horses - Problem 1167
 *
 *  solutie: a[i][j] = coef. asezarii primilor i cai in primele j grajduri.
 *  a[i][j] = min(a[i - k][j - 1] + cost secventa(1 - k + 1, i)),
 *  cu k = 1..i - j + 1
 */

#include <stdio.h>
#include <string.h>

#define MAXN 501

int n, g, h[MAXN], a[2][MAXN];


void readdata()
{
	int i;

	//freopen("file.in", "r", stdin);
	scanf("%d %d", &n, &g);
	for (i = 1; i <= n; scanf("%d", h + i++));
}

void solve()
{
	int i, j, k, n0, n1, now;

	long iter = 0;

	for (n1 = n0 = 0, i = 1; i <= n; i++)
	{
		if (h[i]) n1++; else n0++;
		a[0][i] = n1 * n0;
	}
	for (i = 2; i <= g; i++)
	{
		for (j = i; j <= n; j++)
			for (a[1][j] = 1000000000L, n1 = n0 = 0, k = 1; k <= j - i + 1; k++)
			{
				if (h[j - k + 1]) n1++; else n0++;
				now = a[0][j - k] + n1 * n0;
				if (now < a[1][j]) 
					a[1][j] = now;
			}
		memcpy(a[0], a[1], sizeof(a[1]));
	}

	printf("%d\n", a[0][n]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
