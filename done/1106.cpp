/*
 * ACM Online
 * Problem 1106 - Two Teams
 *
*/

#include <stdio.h>

#define NODS 101

int n, p, grad[NODS], a[NODS][NODS], was[NODS], t1[NODS];

void readdata()
{
	int i, num;

	for (i = 1; i < 101; grad[i++] = 0);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		while (1)
		{
			scanf("%d", &num);
			if (!num) break;
			a[i][num] = a[num][i] = 1;
			grad[i]++; grad[num]++;
		}
}

void solve()
{
	int i, j;
	for (p = 0, i = 1; i <= n; i++)
	{
		if (was[i]) continue;
		p++; t1[i] = was[i] = 1;
		for (j = 1; j <= n; j++)
			if (!was[j] && a[i][j])
				was[j] = 1;
	}
	printf("%d\n", p);
	for (i = 1; i <= 101; i++)
		if (t1[i])
			printf("%d ", i);
	printf("\n");
}

int main()
{
	readdata();
	solve();
	return 0;
}
