/*
 *  ACM Online
 *  Team them up! - Problem 1182
 *
 *  solutie: cea de la 1156...
 */

#include <stdio.h>
#include <string.h>

#define NODS 110

int n, tc = 0, a[NODS][NODS], flag[NODS], g1[NODS], g2[NODS];
struct pack
{
	int from, side;
} box[NODS][NODS];
struct solu
{
	int r[2][NODS];
} s[NODS];


void readdata()
{
	int i, nod;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		do
		{
			scanf("%d", &nod);
			if (!nod) break;
			a[i][nod] = 1;
		}
		while (1);
}

void df(int nod, int parity)
{
	int i;
	flag[nod] = 1;
	if (parity)
		s[tc].r[0][++s[tc].r[0][0]] = nod;
	else
		s[tc].r[1][++s[tc].r[1][0]] = nod;
	for (i = 1; i <= n; i++)
		if (!flag[i] && a[nod][i])
			df(i, 1 - parity);
}

int good(int id)
{
	int i, j;
	for (i = 1; i <= s[id].r[0][0]; i++)
		for (j = i + 1; j <= s[id].r[0][0]; j++)
			if (a[s[id].r[0][i]][s[id].r[0][j]]) return 0;
	for (i = 1; i <= s[id].r[1][0]; i++)
		for (j = i + 1; j <= s[id].r[1][0]; j++)
			if (a[s[id].r[1][i]][s[id].r[1][j]]) return 0;
	return 1;
}

void solve()
{
	int i, j, k, bad = 0, d, l, side, from, i1, i2;

	/*  facem graful cu incompatibilit†ti  */
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (a[i][j] && a[j][i])
				a[i][j] = a[j][i] = 0;
			else a[i][j] = a[j][i] = 1;


	for (i = 1; i <= n; i++)
		if (!flag[i])
		{
			df(i, 0);
			if (!good(tc++)) bad = 1, i = n;
		}

	if (bad)
		printf("No solution\n");
	else  /*  acum echilibr†m grupele  */
	{
		memset(box, -1, sizeof(box));
		box[s[0].r[0][0]][s[0].r[1][0]].from = 0;
		box[s[0].r[0][0]][s[0].r[1][0]].side = 0;
		box[s[0].r[1][0]][s[0].r[0][0]].from = 0;
		box[s[0].r[1][0]][s[0].r[0][0]].side = 1;
		for (k = 1; k < tc; k++)
			for (i = n; i >= 0; i--)
				for (j = n; j >= 0; j--)
					if (box[i][j].from != -1)
					{
						d = i + s[k].r[0][0]; l = j + s[k].r[1][0];
						if (d <= n && l <= n)
						if (box[d][l].from == -1)
							box[d][l].from = k, box[d][l].side = 0;
						d = i + s[k].r[1][0]; l = j + s[k].r[0][0];
						if (d > n || l > n) continue;
						if (box[d][l].from == -1)
							box[d][l].from = k, box[d][l].side = 1;
					}
		i1 = i2 = n / 2;
		if (n & 1) i2++;
		for (; box[i1][i2].from == -1; i1--, i2++);

		do
		{
			if ((i1 <= 0 && i2 <= 0) || box[i1][i2].from == -1) break;
			from = box[i1][i2].from; side = box[i1][i2].side;
			l = s[from].r[side][0]; i1 -= l;
			for (i = 1; i <= l; i++)
				g1[++g1[0]] = s[from].r[side][i];
			l = s[from].r[1 - side][0]; i2 -= l;
			for (i = 1; i <= l; i++)
				g2[++g2[0]] = s[from].r[1 - side][i];
		}
		while (1);

		for (i = 0; i <= g1[0]; i++)
			printf("%d ", g1[i]);
		printf("\n");
		for (i = 0; i <= g2[0]; i++)
			printf("%d ", g2[i]);
		printf("\n");
	}
}

int main()
{
	readdata();
	solve();
	return 0;
}
