// ACM Online
// Episode N-th: The Jedi Tournament - Problem 1218

#include <stdio.h>

#define NMAX 1501

int n, hn, gri[NMAX], flag[NMAX + 1], who;
char a[NMAX][NMAX];

struct creep
{
	char name[41];
	long v1, v2, v3;
} p[NMAX];


void readdata()
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s %ld %ld %ld", &p[i].name, &p[i].v1, &p[i].v2, &p[i].v3);
}

void buildgraf()
{
	int i, j, sum;

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			sum = 0;
			sum += (p[i].v1 > p[j].v1) ? 1 : -1;
			sum += (p[i].v2 > p[j].v2) ? 1 : -1;
			sum += (p[i].v3 > p[j].v3) ? 1 : -1;
			if (sum > 0) gri[j]++; else gri[i]++;
			a[i][j] = a[j][i] = 1;
		}
}

void solve()
{
	int i, j = -1, what;

	buildgraf();
	for (i = 0; i < n; i++)
		if (!gri[i])
			j = i, flag[i] = 1, i = n;
	hn = n;
	if (j >= 0)
	{
		printf("%s\n", p[j].name);
		return;
	}
	else
	do
	{
		who = -1; hn--;
		for (i = 0; i < n; i++)
			if (gri[i] == hn)
				who = i, flag[i] = 1, i = n;
		for (i = 0; i < n; i++)
			a[who][i] = a[i][who] = 0;
	}
	while (who >= 0);

	for (i = 0; i < n; i++)
		if (!flag[i])
			printf("%s\n", p[i].name);
}

int main()
{
	readdata();
	solve();
	return 0;
}
