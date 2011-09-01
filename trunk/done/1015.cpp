/*
 *  ACM Online
 *  Test the Difference - Problem 1015
 *  ai niste zaruri (10^5) si trebuie s† le g†sesti pe cele cu aceeasi cfg. dar
 *  sunt si d-alea rotite...
 *
 *  solutie: sunt doar 720 de perm. si 30 de grupe. Deci initial le proces†m
 *  si le distribuim pe grupe. Apoi baleiem zarurile si le g†sim grupele...
 *  O(720 * N) -> O(N)
 */

#include <stdio.h>

typedef int dice[7];
dice zar;
int n, hn, tsol = 1, maxg = 0, tg = 0;
int flag[50], one[10], how[50], gr[10010], ord[50];
struct perm
{
	int gr;
	dice x;
} p[721];

/*  stƒnga, fat†, lateral  */
int rot[3][7] = {{0, 3, 5, 2, 4, 1, 6}, {0, 1, 2, 6, 3, 4, 5}, {0, 6, 4, 3, 1, 5, 2}};


void rotate(dice &a, int face)
{
	int i;
	dice b;
	for (i = 1; i <= 6; i++) b[i] = a[i];
	for (i = 1; i <= 6; i++) a[i] = b[rot[face][i]];
}

int same(dice a, dice b) /*  Œl rotim pe a pƒn† devine b (dac† devine...)  */
/*  le aducem la aceeasi baz† si aceeasi fat† stƒng†  */
{
	int i;
	dice c;
	for (i = 0; i <= 6; i++) c[i] = a[i];
	for (i = 0; i < 4; i++)
		if (c[5] != b[5]) rotate(c, 0);
	for (i = 0; i < 4; i++)
		if (c[5] != b[5]) rotate(c, 1);
	/*  are acelasi fund  */

	for (i = 0; i < 4; i++)
		if (c[1] != b[1]) rotate(c, 2);
	/*  are aceeasi fat† stƒng†  */

	for (i = 1; i <= 6; i++)
		if (c[i] != b[i]) return 0;
	return 1;
}

void back(int lev)
{
	int i, ok;
	if (lev == 6)
	{
		for (i = 1; i <= 6; i++)
			p[tsol].x[i] = one[i - 1];
		ok = 0;
		for (i = 1; i < tsol; i++)
			if (same(p[i].x, p[tsol].x))
			{
				p[tsol].gr = p[i].gr;
				ok = 1; i = tsol;
			}
		if (!ok)
			p[tsol].gr = ++maxg;
		tsol++;
	} else
	for (i = 1; i <= 6; i++)
		if (!flag[i])
		{
			flag[i] = 1; one[lev] = i;
			back(lev + 1);
			flag[i] = 0;
		}
}

int main()
{
	int i, j, k, ok;
	/*  process all 720 6 permutations  */
	back(0);

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= 6; j++)
			scanf("%d", zar + j);
		for (j = 1; j <= tsol; j++)
		{
			ok = 0;
			for (k = 1; k <= 6; k++)
				if (p[j].x[k] != zar[k]) ok = 1, k = 6;
			if (!ok)
			{
				if (!how[p[j].gr]) tg++;
				how[p[j].gr]++;
				gr[i] = p[j].gr;
				j = tsol;
			}
		}
	}

	for (i = k = 0; i < n; i++)
		if (!flag[gr[i]])
			flag[gr[i]] = 1, ord[k++] = gr[i];

	printf("%d\n", tg);
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n; j++)
			if (gr[j] == ord[i])
				printf("%d ", j + 1);
		printf("\n");
	}
	return 0;
}

/*
 *  Hei, he, hei, vino sus, s† ne-ascundem Œn nori
 *  Hei, he, hei, hai Œnvat† s† zbori
 */
