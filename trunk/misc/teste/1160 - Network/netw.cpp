/*
 *  ACM Timus Online
 *  Network - Problem 1160
 *
 *  solutie: APM cu Kruskal (e clar ca minimizeaza muchia maxima...)
 */

#include <stdio.h>
#include <stdlib.h>

#define NODS 1010
#define input "netw.in"
#define output "netw.out"

FILE *f;
long max = 0;
int n, m, r[NODS], t[NODS];
typedef struct edge
{
	int n1, n2;
	long c;
} edge;
edge e[15010];


void readdata()
{
	int i;

	f = fopen(input, "r");
	fscanf(f, "%d %d",  &n, &m);
	for (i = 0; i < m; i++)
		fscanf(f, "%d %d %ld", &e[i].n1, &e[i].n2, &e[i].c);
	fclose(f);
}

int find(int x)
{
	if (x != t[x]) t[x] = find(t[x]);
	return t[x];
}

void join(int x, int y)
{
	if (r[x] > r[y]) t[y] = x;
	else
	{
		t[x] = y;
		if (r[x] == r[y]) r[y]++;
	}
}

int cmp(const void *a, const void *b)
{
    return ((edge *) a) -> c - ((edge *) b) -> c;
}

void solve()
{
	int i, n1, n2;

    qsort(e, m, sizeof(edge), cmp);

	for (i = 1; i <= n; i++)
		r[i] = 0, t[i] = i;

	for (i = 0; i < m; i++)
	{
		n1 = e[i].n1; n2 = e[i].n2; 
		if (find(n1) != find(n2))
		{
			if (e[i].c > max) 
				max = e[i].c;
			e[i].c *= -1;
			join(find(n1), find(n2));
		}
	}

	f = fopen(output, "w");
	fprintf(f, "%d\n%d\n", max, n - 1);	

	for (i = m - 1; i >= 0; i--)
		if (e[i].c < 0)
			fprintf(f, "%d %d\n", e[i].n1, e[i].n2);
	fclose(f);
}

int main()
{
	readdata();
	solve();
	return 0;
}
