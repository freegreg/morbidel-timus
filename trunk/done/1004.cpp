/*
 *  ACM Online
 *  Sightseeing trip - Problem 1004
 *
 *  solutie: N Dijkstra-uri...
 */

#include <stdio.h>

#define NODS 110
#define INF 2e+9L

int N, M, ns, src, n1, n2;
long a[NODS][NODS], d[NODS], s[NODS];
long t[NODS], d1[NODS], d2[NODS], r[NODS], min;


void check()
{
	int i, j;
	for (i = 1; i < N; i++)
		for (j = i + 1; j <= N; j++)
			if (a[i][j] != INF)
				if (t[i] != j && t[j] != i && d[i] != INF && d[j] != INF)
					if (a[i][j] + d[i] + d[j] < min)
					{
						min = a[i][j] + d[i] + d[j];
						ns = src; n1 = i; n2 = j;
					}
}

void dijkstra()
{
	long i, j, k, mini;
	for (i = 1; i <= N; i++)
	{
		d[i] = a[src][i];
		t[i] = (d[i] != INF) ? src : 0;
		s[i] = 0;
	}
	s[src] = 1;
	for (i = 1; i < N; i++)
	{
		mini = INF;
		for (j = 1; j <= N; j++)
			if (!s[j] && d[j] < mini)
				mini = d[j], k = j;
		if (mini == INF) continue;
		s[k] = 1;
		for (j = 1; j <= N; j++)
			if (!s[j] && a[k][j] != INF && mini + a[k][j] < d[j])
				d[j] = mini + a[k][j], t[j] = k;
	}
	t[src] = 0;
}

void solve()
{
	min = INF;
	for (src = 1; src <= N; src++)
	{
		dijkstra();
		check();
	}
}

void road()
{
	src = ns;
	dijkstra();

	for (; n1 != src; n1 = t[n1])
		printf("%d ", n1);
	printf("%d ", src);

	for (r[0] = 0; n2 != src; n2 = t[n2])
		r[++r[0]] = n2;

	for (src = r[0]; src; src--)
		printf("%ld ", r[src]);
	printf("\n");
}

int main()
{
	int i, j, k, cost;
	do
	{
		scanf("%d %d", &N, &M);
		if (N == -1) break;
		for (i = 0; i <= N; i++)
			for (j = i; j <= N; j++)
				a[i][j] = a[j][i] = INF;
		for (k = 0; k < M; k++)
		{
			scanf("%d %d %d", &i, &j, &cost);
			if (cost < a[i][j]) a[i][j] = a[j][i] = cost;
		}
		solve();
		if (min == INF)
			printf("No solution.\n");
		else road();
	}
	while (1);

	return 0;
}
