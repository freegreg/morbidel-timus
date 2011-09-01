/*
 *  ACM Online
 *  Meeting - Problem 1085
 *
 *  solutie: lu†m pe rƒnd toate orasele si calcul†m suma aia...
 */

#include <stdio.h>
#include <string.h>

#define NODS 101

FILE *f;
int n, m, nd, x, y, place = -1, q[1000], flag[NODS], lines[NODS];
long c[NODS], tmin = 1e9L;
char line[NODS][NODS];
struct dort
{
	int money, start, ab;
} d[NODS];


void readdata()
{
	int i, j, nod;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &line[i][0]);
		for (j = 1; j <= line[i][0]; j++)
		{
			scanf("%d ", &nod);
			line[i][nod] = 1;
		}
	}
	scanf("%d", &nd);
	for (i = 1; i <= nd; i++)
		scanf("%d %d %d", &d[i].money, &d[i].start, &d[i].ab);
}

void bf()
{
	int i, j, k, ll, lev, lmax, how;

	lev = ll = c[x] = 0;
	q[0] = x; flag[x] = lmax = how = 1;
	do
	{
		lev = ll; ll = lmax;
		if (lev >= ll || how == n || c[y] < 1e7L) break;
		for (k = lev; k < ll; k++)
			for (i = 0; i < m; i++)
				if (line[i][q[k]] && !lines[i])
					for (j = 1; j <= n; j++)
						if (j != q[k] && !flag[j] && line[i][j])
						{
							q[lmax++] = j;
							flag[j] = lines[i] = 1; how++;
							if (c[q[k]] + 1 < c[j])
								c[j] = c[q[k]] + 4;
						}
	}
	while (1);
}

long trip(int source, int dest)
{
	int i;
	x = source; y = dest;
	for (i = 0; i <= 100; i++)
		flag[i] = lines[i] = 0, c[i] = 1e7L;
	bf();
	return c[y];
}

void solve()
{
	long i, j, timp, how;

	for (i = 1; i <= n; i++)    /*  ne Œntƒlnim Œn i  */
	{
		timp = 0;
		for (j = 1; j <= nd; j++)
		{
			if (d[j].ab) continue;
			how = trip(d[j].start, i);
			if (how > d[j].money)
				timp = 1e9L, j = nd;
			timp += how;
		}
		if (timp < tmin)
			tmin = timp, place = i;
	}
	if (place == -1) printf("0\n"); else
	printf("%d %ld\n", place, tmin);
}


int main()
{
	readdata();
	solve();
	return 0;
}
