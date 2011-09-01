/*
 *  ACM Timus Online Contest 27 March 2004
 *  B - Cube in Labyrinth 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXL 11

int L, C, lv, ml, sl, sc, fl, fc, mcubs[MAXL][MAXL], is[MAXL][MAXL], map[MAXL][MAXL][MAXL][MAXL];
typedef int cube[7];
struct table
{
	cube c;
	long sum;
	int nc, tl, tc;
} a[MAXL][MAXL][30];
struct queue
{
	int l, c;
} q[5000];

					/*  rotate back, left, front, right  */
int rot[4][7] = {{0, 5, 3, 1, 4, 2, 6}, {0, 1, 2, 4, 5, 6, 3},
				 {0, 3, 5, 2, 4, 1, 6}, {0, 1, 2, 6, 3, 4, 5}};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int roots[2][4] = {{2, 0, 1, 3}, {0, 2, 3, 1}};



void readdata()
{
	char ch[2], s1[10], s2[10];
	int i, j;

	freopen("file.in", "r", stdin);

	scanf("%d %d %d %d %d %d", &L, &C, &sl, &sc, &fl, &fc);


	mcubs[sl][sc] = 1;
	for (ch[0] = 1; ch[0] <= 6; ch[0]++)
		a[sl][sc][0].c[ch[0]] = 1;
	scanf("%s", &s1);
	if (!strcmp(s1, "h"))
	{
		while (1)
		{
			scanf("%s", &s1);
			if (!strcmp(s1, "v")) break;
			scanf("%s", &s2);
			i = atoi(s1); j = atoi(s2);
			map[i][j][i + 1][j] = map[i + 1][j][i][j] = 1;
		}

	}
}

int same(cube c1, cube c2)
{
	int i;
	for (i = 1; i <= 6; i++)
		if (c1[i] != c2[i]) return 0;
	return 1;
}
/*  face 0, 1, 2, 3 -> rotate back, left, front, right  */
void rotate(int face, cube &c)
{
	int i;
	cube a;
	memcpy(a, c, sizeof(cube));
	for (i = 1; i <= 6; i++)
		c[i] = a[rot[face][i]];
}
/*  Œntoarce true dac† s-a mai minimizat si deci expand†m din nou...  */
int baga_mare(int nl, int nc, int l, int c, int ncub, cube s)
{
	int i, ok = 0;
	long nsum = a[l][c][ncub].sum + s[5];

	if (nl < 1 || nl > 8 || nc < 1 || nc > 8) return 0;
	for (i = 0; i < mcubs[nl][nc]; i++)
		if (same(a[nl][nc][i].c, s))
		{
			ok = 1;
			if (nsum < a[nl][nc][i].sum)
			{
				a[nl][nc][i].sum = nsum;
				a[nl][nc][i].tl = l; a[nl][nc][i].tc = c;
				a[nl][nc][i].nc = ncub;
				return 1;
			}
			return 0;
		}
	if (!ok)
	{
		a[nl][nc][mcubs[nl][nc]].nc = ncub;
		ncub = mcubs[nl][nc];
		a[nl][nc][ncub].sum = nsum;
		a[nl][nc][ncub].tl = l; a[nl][nc][ncub].tc = c;
		memcpy(a[nl][nc][ncub].c, s, sizeof(cube));
		mcubs[nl][nc]++;
	}
	return 1 - ok;
}

void expand(int l, int c)
{
	cube s;
	int i, ok, ncub, nl, nc;

	for (lv = 0; lv < ml; lv++)
	{
		l = q[lv].l; c = q[lv].c;
		is[l][c] = 0;
		for (ncub = 0; ncub < mcubs[l][c]; ncub++)
		{
			for (i = 1; i <= 6; i++)
				s[i] = a[l][c][ncub].c[i];
			for (i = 0; i < 4; i++)
			{
				rotate(roots[0][i], s);
				nl = l + dir[i][0]; nc = c + dir[i][1];
				ok = baga_mare(nl, nc, l, c, ncub, s);
				if (ok && !is[nl][nc])
					is[nl][nc] = 1, q[ml].l = nl, q[ml++].c = nc;
				rotate(roots[1][i], s);
			}
		}
	}
}

void write_sol(int l, int c, int ncub)
{
	int tl = a[l][c][ncub].tl, tc = a[l][c][ncub].tc;

	if (!tl && !tc) return;
	ncub = a[l][c][ncub].nc;
	write_sol(tl, tc, ncub);
	printf(" %c%d", c + 96, l);
}

void solve()
{
	long i, j, k;

	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			for (k = 0; k < 24; k++)
				a[i][j][k].sum = 1e5L;
	a[sl][sc][0].sum = a[sl][sc][0].c[5];

	lv = 0; ml = 1;
	q[0].l = sl; q[0].c = sc;
	expand(sl, sc);

	k = 1e9L;
	for (i = 0; i < mcubs[fl][fc]; i++)
		if (a[fl][fc][i].sum < k)
			k = a[fl][fc][i].sum, j = i;

	printf("%ld %c%d", k, sc + 96, sl);
	write_sol(fl, fc, j);
	printf("\n");
}

int main()
{
	readdata();
	solve();
	return 0;
}

/*
 *  Apar de pe t†rƒmul negru cu stilul meu bolnav...
 */
