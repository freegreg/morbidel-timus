/*
 *  ACM Timus - Gamers
 */

#include <stdio.h>


int N, L, C, Pieces;
int Map[512][512];
int Panel[10][256][512];



void Readdata()
{
	scanf("%d %d %d", &N, &L, &C);

	L--; C--;
	N = 1 << N;
}

int loga(int n)
{
	int c = 0;

	while (n)
		n /= 2, c++;

	return c - 1;
}

void Copy(int a[][512], int b[][512], int pos, int n)
{
	int i, j;

	if (pos == 0)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i][j] = b[i][j];
	else
	if (pos == 1)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i][j + n] = b[i][j];
	else
	if (pos == 2)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i + n][j] = b[i][j];
	else
	if (pos == 3)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i + n][j + n] = b[i][j];
}

void Generate(int n, int l, int c, int a[][512])
{
	int i, j;


	if (n == 2)
	{
		Pieces++;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (i == l && j == c)
					a[i][j] = 0;
				else
					a[i][j] = Pieces;
		return;
	}

	if (l < n / 2 && c < n / 2)
	{
		Generate(n / 2, l, c, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 0, n / 2);

		Generate(n / 2, n / 2 - 1, 0, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 1, n / 2);

		Generate(n / 2, 0, n / 2 - 1, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 2, n / 2);

		Generate(n / 2, 0, 0, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 3, n / 2);

		a[n / 2 - 1][n / 2] = a[n / 2][n / 2 - 1] = a[n / 2][n / 2] = ++Pieces;
	} else
	if (l < n / 2 && c >= n / 2)
	{
		Generate(n / 2, n / 2 - 1, n / 2 - 1, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 0, n / 2);

		Generate(n / 2, l, c - n / 2, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 1, n / 2);

		Generate(n / 2, 0, n / 2 - 1, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 2, n / 2);

		Generate(n / 2, 0, 0, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 3, n / 2);

		a[n / 2 - 1][n / 2 - 1] = a[n / 2][n / 2 - 1] = a[n / 2][n / 2] = ++Pieces;
	} else
	if (l >= n / 2 && c < n / 2)
	{
		Generate(n / 2, n / 2 - 1, n / 2 - 1, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 0, n / 2);

		Generate(n / 2, n / 2 - 1, 0, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 1, n / 2);

		Generate(n / 2, l - n / 2, c, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 2, n / 2);

		Generate(n / 2, 0, 0, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 3, n / 2);

		a[n / 2 - 1][n / 2 - 1] = a[n / 2 - 1][n / 2] = a[n / 2][n / 2] = ++Pieces;
	} else
	if (l >= n / 2 && c >= n / 2)
	{
		Generate(n / 2, n / 2 - 1, n / 2 - 1, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 0, n / 2);

		Generate(n / 2, n / 2 - 1, 0, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 1, n / 2);

		Generate(n / 2, 0, n / 2 - 1, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 2, n / 2);

		Generate(n / 2, l - n / 2, c - n / 2, Panel[loga(n)]);
		Copy(a, Panel[loga(n)], 3, n / 2);

		a[n / 2 - 1][n / 2 - 1] = a[n / 2 - 1][n / 2] = a[n / 2][n / 2 - 1] = ++Pieces;
	}
}

void Solve()
{
	Pieces = 0;

	if ((N * N - 1) % 3 != 0)
		printf("-1\n");
	else
	{
		int i, j;

		Generate(N, L, C, Map);

		for (i = 0; i < N; i++, printf("\n"))
			for (j = 0; j < N; j++)
				printf("%d ", Map[i][j]);
	}
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
