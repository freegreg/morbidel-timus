/*	
 *  ACM Online
 *  Hyperchannels - Problem 1176
 *
 *  solutie: ciclu eulerian din A pe negativul matricii de adiacenta
 *  (lucru bizar: asta o facusem de cateva luni dar dadea WA. Am trimis-o acum asa intr-o doara si a luat ACC!)
 */

#include <stdio.h>
#include <string.h>

#define NODS 1001
#define EDGES 32010

int how[NODS], poz[NODS], g[NODS];
int c[EDGES], cn[EDGES];
int n, m = 0, node, a[EDGES];


void readdata()
{
	int i, j, x;

	scanf("%d %d", &n, &node); 
	for (node--, i = 0; i < n; i++)
	{
		poz[i] = i ? poz[i - 1] + how[i - 1] : 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &x);
			x = 1 - x;
			if (i == j) x = 0;
			if (x) 
				a[poz[i] + how[i]++] = j, m++, g[i]++;
		}
	}
}

void cycle(int nodd)
{
	int j, nod = nodd, ok;

	memset(cn, 0, sizeof(cn));
	do
	{
		cn[++cn[0]] = nod;
		ok = 0;
		for (j = 0; j < how[nod]; j++)
			if (a[poz[nod] + j] >= 0)
				ok = 1, j = how[nod];
		if (!ok) return;
		ok = a[poz[nod] + j];
		a[poz[nod] + j] = -1; g[nod]--;
		if (ok == nodd) break;
		nod = ok;
	}
	while (1);
	cn[++cn[0]] = nodd;
}

void baga(int pos)
{
	int i, j, d = cn[0] - 1;

	for (i = c[0]; i >= pos + 1; i--)
		c[i + d] = c[i];
	c[0] += d;
	for (i = 1; i <= cn[0]; i++)
		c[pos + i - 1] = cn[i];
}

void solve()
{
	int i;

	c[++c[0]] = node;
	for (i = 1; i <= c[0]; i++)
	{
		cycle(c[i]);
		if (cn[0] > 1) 
			baga(i);
		if (c[0] == m + 1) 
			break; 
	}
	for (i = 1; i < c[0]; i++)
		printf("%d %d\n", c[i] + 1, c[i + 1] + 1);
}

int main()
{
	readdata();
	solve();
	return 0;
}
