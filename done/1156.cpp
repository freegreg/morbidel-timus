/*
 *  ACM Online
 *  Two Days - Problem 1156
 *
 *  solutie: facem graful cu incompatibilit†ti si apoi facem un DF din 2 Œn 2.
 *  Asta pt. o component† conex†. Acum, dup† ce o verific†m c† e bun†, trecem
 *  la urm†toarea. Acum avem un vector cu 2 numere, lungimile secventelor opuse
 *  din fiecare c. conex† si sumele lor trebuie s† fie egale cu N / 2. Facem
 *  un rucsac dubios Œn plan...
 */

#include <stdio.h>
#include <string.h>

#define NODS 110

int n, m, tc = 0, a[NODS][NODS], flag[NODS], con[NODS];
int g1[NODS], g2[NODS];
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
	int i, j;
	scanf("%d %d", &n, &m); n *= 2;
	for (; m--; )
	{
		scanf("%d %d", &i, &j);
		a[i][j] = a[j][i] = 1;
	}
}

void df(int nod, int parity)
{
	int i;
	flag[nod] = 1; con[++con[0]] = nod;
	if (parity)
		s[tc].r[0][++s[tc].r[0][0]] = nod, flag[nod] = 2;
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
	for (i = 1; i <= n; i++)
		if (!flag[i])
		{
			memset(con, 0, sizeof(con));
			df(i, 0);
			for (j = 1; j <= con[0]; j++)
				if (flag[con[j]] == 1)
					s[tc].r[1][++s[tc].r[1][0]] = con[j];
			if (!good(tc++)) bad = 1, i = n;
		}

	if (bad) printf("IMPOSSIBLE\n");
	else  /*  acum echilibr†m grupele  */
	{
		memset(box, -1, sizeof(box));
		bad = n / 2;
		box[s[0].r[0][0]][s[0].r[1][0]].from = 0;
		box[s[0].r[0][0]][s[0].r[1][0]].side = 0;
		box[s[0].r[1][0]][s[0].r[0][0]].from = 0;
		box[s[0].r[1][0]][s[0].r[0][0]].side = 1;
		for (k = 1; k < tc; k++)
			for (i = bad; i; i--)
				for (j = bad; j; j--)
					if (box[i][j].from != -1)
					{
						d = i + s[k].r[0][0]; l = j + s[k].r[1][0];
						if (d <= bad && l <= bad)
						if (box[d][l].from == -1)
							box[d][l].from = k, box[d][l].side = 0;
						d = i + s[k].r[1][0]; l = j + s[k].r[0][0];
						if (d > bad || l > bad) continue;
						if (box[d][l].from == -1)
							box[d][l].from = k, box[d][l].side = 1;
					}
		i1 = bad; i2 = bad;
		do
		{
			if (i1 <= 0 || i2 <= 0 || box[i1][i2].from == -1) break;
			from = box[i1][i2].from; side = box[i1][i2].side;
			l = s[from].r[side][0]; i1 -= l;
			for (i = 1; i <= l; i++)
				g1[++g1[0]] = s[from].r[side][i];
			l = s[from].r[1 - side][0]; i2 -= l;
			for (i = 1; i <= l; i++)
				g2[++g2[0]] = s[from].r[1 - side][i];
		}
		while (1);

		/*  le sort†m  */
		for (i = 1; i <= g1[0]; i++)
			for (j = i + 1; j <= g1[0]; j++)
				if (g1[i] > g1[j])
					bad = g1[i], g1[i] = g1[j], g1[j] = bad;
		for (i = 1; i <= g2[0]; i++)
			for (j = i + 1; j <= g2[0]; j++)
				if (g2[i] > g2[j])
					bad = g2[i], g2[i] = g2[j], g2[j] = bad;


		/*  posibil dar nu avem grupe egale  */
		if (box[n / 2][n / 2].from == -1)
			printf("IMPOSSIBLE\n");
		else
		if (g1[1] < g2[1])
		{
			for (i = 1; i <= g1[0]; i++) printf("%d ", g1[i]);
			printf("\n");
			for (i = 1; i <= g2[0]; i++) printf("%d ", g2[i]);
			printf("\n");
		} else
		{
			for (i = 1; i <= g2[0]; i++) printf("%d ", g2[i]);
			printf("\n");
			for (i = 1; i <= g1[0]; i++) printf("%d ", g1[i]);
			printf("\n");
		}
	}
}

int main()
{
	readdata();
	solve();
	return 0;
}

/*
	Am interes Œn a m† face cunoscut de multime, tot mai des aud: "Zi-le frate
	c† le zici bine, zi-le cƒt te tine..."
	Reactii chimice motivate de sinapsarea microfonului cu propriile-mi
	terminatii dendritice...
	Morbiditatea creste la indice
*/
