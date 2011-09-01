// ACM Online
// Genealogical Tree - Problem 1022

// solutie: sortare topologica

#include <stdio.h>

int n, a[100][100], flag[100];

void readdata()
{
	int i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		do
		{
			scanf("%d", &x);
			if (!x) break;
			a[x - 1][i] = 1;
		} while (1);
	}
}

void df(int nod)
{
	int i;
	flag[nod] = 1;
	for (i = 0; i < n; i++)
		if (a[nod][i] && !flag[i]) df(i);
	printf("%d ", nod + 1);
}

void solve()
{
	int i;
	for (i = 0; i < n; i++)
		if (!flag[i]) df(i);
}

void main()
{
	readdata();
	solve();
}