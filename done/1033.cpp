/*
 *  ACM Online
 *  Labyrinth - Problem 1033
 *
 *  facem FILL din colturi si num†ram peretii cu 0 din jurul celor bifati
 *  (si cei dinafar†). E logic, deoarece †stia sunt cei vizibili...
 *  In final Œnmultim cu 9 deoarece asta e aria peretelui...
 */

#include <stdio.h>

int n, m[35][35];
long sol = 0;


void readdata()
{
	char ch;
	int i, j = 0;

	scanf("%d\n", &n);
	for (i = 0; i < n; i++, scanf("\n"))
		for (j = 0; j < n; j++)
		{
			scanf("%c", &ch);
			m[i][j] = (ch == '.') ? 0 : 2;
		}
}

#define inside(l, c) (l >= 0 && l < n && c >= 0 && c < n)

void fill(int l, int c)
{
	if (m[l][c] != 0 || !inside(l, c)) return;
	m[l][c] = 1;
	if (!m[l + 1][c]) fill(l + 1, c);
	if (!m[l - 1][c]) fill(l - 1, c);
	if (!m[l][c + 1]) fill(l, c + 1);
	if (!m[l][c - 1]) fill(l, c - 1);
}

void solve()
{
	int l, c;
	fill(0, 0);         /*  ambele iesiri  */
	fill(n - 1, n - 1);    /*  desi ar trebui s† fie conex  */
	for (l = 0; l < n; l++)
		for (c = 0; c < n; c++)
			if (m[l][c] == 1)
			{
				if (!inside(l - 1, c) || m[l - 1][c] == 2) sol++;
				if (!inside(l + 1, c) || m[l + 1][c] == 2) sol++;
				if (!inside(l, c - 1) || m[l][c - 1] == 2) sol++;
				if (!inside(l, c + 1) || m[l][c + 1] == 2) sol++;
			}

	printf("%ld\n", (sol - 4) * 9);
}

int main()
{
	readdata();
	solve();
	return 0;
}
