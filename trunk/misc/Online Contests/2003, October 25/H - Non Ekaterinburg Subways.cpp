/*
 *  ACM Timus Online
 *  Non Ekaterinburg Subways - Problem 1272
 *
 *  solutie: muchiile pod au costul 1, restul 0. Facem APM cu Kruskal(MlogM) si afisam costul lui...
 *  muchiile sunt deja sortate din input... deci vine O(Mlog*M)
 */

#include <stdio.h>

#define NODS 10100

int n, pod, tun, apm = 0, r[NODS], t[NODS];
struct edge
{
	int n1, n2, c;
} e[NODS * 2];


void readdata()
{
	int i;
	scanf("%d %d %d",  &n, &tun, &pod);
	for (i = 0; i < tun; i++)
		scanf("%d %d", &e[i].n1, &e[i].n2), e[i].c = 0;
	for (i = tun; i < tun + pod; i++)
		scanf("%d %d", &e[i].n1, &e[i].n2), e[i].c = 1;
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

void solve()
{
	int i, n1, n2;

	for (i = 1; i <= n; i++)
		r[i] = 0, t[i] = i;

	for (i = 0; i < tun + pod; i++)
	{
		n1 = e[i].n1; n2 = e[i].n2; 
		if (find(n1) != find(n2))
			apm += e[i].c, join(find(n1), find(n2));
	}

	printf("%d\n", apm);
}

int main()
{
	readdata();
	solve();
	return 0;
}
