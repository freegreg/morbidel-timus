// ACM Online
// Airline Company - Problem 1040

// solutie: daca sunt noduri cu gradul impar atunci sunt in numar par. Creem
// un nod nou si-l legam cu ele astfel avem un graf Eulerian. Facem parcurgerea
// Euler si numerotam muchiile consecutive cu numere de la 1..m dar fara noile
// muchii (cele cu nodul nou). In final verificam solutia. Marfa, nu?
// am luat-o de la IMO 1991 (interu' de mate!)

#include <stdio.h>
#include <string.h>

int n, m, a[51][51], c[1500], cn[1500], flag[51], g[51];
struct mu
{
	int n1, n2;       // lista initiala, ne trebuie...
} mm[1500];

void readdata()
{
	int i, j, k;
	scanf("%d %d", &n, &m);
	for (k = 0; k < m; k++)
	{
		scanf("%d %d", &i, &j);
		i--; j--;
		g[i]++; g[j]++;
		a[i][j] = a[j][i] = 1;
		mm[k].n1 = i; mm[k].n2 = j;
	}
}

void cycle(int node)
{
	int j, nod = node, ok;
	memset(cn, 0, sizeof(cn));
	do
	{
		flag[nod] = 1;
		cn[++cn[0]] = nod;
		ok = 0;
		for (j = 0; j < n; j++)
			if (a[nod][j])
			{ ok = 1; break; }
		if (!ok) return;
		a[nod][j] = a[j][nod] = 0;
		g[j]--; g[nod]--;
		if (j == node) break;
		nod = j;
	}
	while (1);
	cn[++cn[0]] = node;
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

int cmmdc(int a, int b)
{
	if (!b) return a;
	else return cmmdc(b, a % b);
}

int check()
{
	int i, j, tc, n1, n2;
	for (i = 0; i < n; i++)
	{
		tc = n1 = n2 = 0;
		for (j = 0; j < n; j++)
			if (a[i][j] > 0)
			{
				if (!n1) n1 = a[i][j]; else
				if (n1 && !n2) n2 = a[i][j], tc = cmmdc(n1, n2); else
				tc = cmmdc(tc, a[i][j]);
			}
		if (!n2) tc = 1;
		if (!n1 || tc != 1) return 0;
	}
	return 1;
}

void solve()
{
	int i, j, gi = 0, k;
	for (i = 0; i < n; i++)
		if (g[i] & 1)     // grad impar
		{
			gi = 1;
			a[n][i] = a[i][n] = 1;
			g[i]++; g[n]++;
		}
	if (gi) n++;
	for (k = i = 0; i < n; i++)
		if (!flag[i])
		{
			memset(c, 0, sizeof(c));
			c[++c[0]] = i;
			for (j = 1; j <= c[0]; j++)
			{
				cycle(c[j]);
				if (cn[0] > 1) baga(j);
			}
			for (j = 1; j < c[0]; j++)
            {
				if (gi && (c[j] == n - 1 || c[j + 1] == n - 1)) continue;
				a[c[j]][c[j + 1]] = a[c[j + 1]][c[j]] = ++k;
			}
		}
	if (gi) n--;
	if (!check()) printf("NO"); else
	{
		printf("YES\n");
		for (i = 0; i < m; i++)
			printf("%d ", a[mm[i].n1][mm[i].n2]);
	}
}

void main()
{
	readdata();
	solve();
}