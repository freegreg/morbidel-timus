/*
 *  ACM Online
 *  Square Frames - Problem 1006
 *
 *  solutie: am luat-o de pe forum, problem† de c†cat...
 *  cred c† ia frame-urile complete si golul Œl las† pt. a pune orice...
 */

#include <stdio.h>
#include <string.h>

unsigned char a[21][51];
int b[2001][4];
int s = 0;


int in(int ch, int c1, int c2)
{
	return (ch == c1 || ch == c2);
}

void p(int i, int j, int k, int &l)
{
	int x, y;
	if (!in(a[i][j], 1, 218)) return;
	if (!in(a[i + k][j], 1, 192)) return;
	if (!in(a[i][j + k], 1, 191)) return;
	if (!in(a[i + k][j + k], 1, 217)) return;

	for (y = j + 1; y <= j + k - 1; y++)
		if (!in(a[i][y], 1, 196) || !in(a[i + k][y], 1, 196)) return;
	for (x = i + 1; x <= i + k - 1; x++)
		if (!in(a[x][j], 1, 179) || !in(a[x][j + k], 1, 179)) return;

	l = 0;
	for (y = j; y <= j + k; y++)
		if (a[i][y] != 1 || a[i + k][y] != 1)
			l = 1;
	if (!l)
		for (x = i; x <= i + k; x++)
			if (a[x][j] != 1 || a[x][j + k] != 1)
				l = 1;
	if (!l) return;
	b[++s][1] = i; b[s][2] = j; b[s][3] = k + 1; l = 1;
	for (y = j; y <= j + k; y++)
		a[i][y] = a[i + k][y] = 1;
	for (x = i; x <= i + k; x++)
		a[x][j] = a[x][j + k] = 1;
}

int main()
{
	int i, j, k, h, l, m;

	for (i = 0; i < 20; i++)
		scanf("%s", a + i);

	for (h = 1; h <= 2000; h++)
	{
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 50; j++)
				if (a[i][j] != '.')
				{
					if (19 - i > 49 - j) k = 49 - j;
					else k = 19 - i;
					for (m = 1; m <= k; m++)
					{
						l = 0;
						p(i, j, m, l);
						if (l == 1) break;
					}
				}
			if (l == 1) break;
		}
		if (l == 1) break;
	}
	printf("%d\n", s);
	for (i = s; i; i--)
		printf("%d %d %d\n", b[i][2], b[i][1], b[i][3]);

	return 0;
}
