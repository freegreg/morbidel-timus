/*
 *  ACM Online
 *  Ship Routes - Problem 1172
 */


#include <stdio.h>
#include <string.h>

#define input "1172.in"


FILE *f;
int n, a[100][100], road[100], was[100], gr[100];
long double sol = 0;


void readdata()
{
	int i, j;
	f = fopen(input, "r");
	fscanf(f, "%d", &n);
	while(fscanf(f, "%d %d", &i, &j) == 2)
		a[i][j] = a[j][i] = 1;
	fclose(f);
}

void back(int lev)
{
	int i;
	if (lev == n + 1 && !a[road[n]][1])
	{
		for (i = 1; i <= n; printf("%d ", road[i++]));
		printf("\n");
		sol++;
	}
	else
	for (i = 1; i <= n; i++)
		if (!was[i] && a[road[lev - 1]][i])
		{
			was[i] = 1;
			road[lev] = i;
			back(lev + 1);
			was[i] = 0;
		}
}

void solve()
{
	road[1] = 1; was[1] = 1;
	back(2);
	if (n == 3) sol = 1;
	printf("%d -> %.0Lf\n", n / 3, sol * n / 3);
}

void write_edges()
{
	int i, h = 1;
	for (i = 1; i <= n; i++)
	{
		gr[i] = h;
		if (i % (n / 3) == 0) h++;
	}

	f = fopen(input, "w");
	fprintf(f, "%d\n", n);
	for (i = 1; i <= n; i++)
		for (h = (n / 3) * gr[i] + 1; h <= n; h++)
			fprintf(f, "%d %d\n", i, h);
	fclose(f);
}

int main()
{
	scanf("%d", &n);
	n *= 3;
	write_edges();
	readdata();
	solve();
	return 0;
}
