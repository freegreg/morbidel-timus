#include <stdio.h>

int N, Sol = 0;
int Map[64][64];



int afara(int l, int c)
{
	return !(l >= 0 && l < N && c >= 0 && c < N);
}

int good(int lin, int col)
{
	int i, j;

	// pe linii si coloane
	for (i = 0; i < N; i++)
		if (Map[lin][i] != 0 || Map[i][col] != 0)
			return 0;

	// diagonale
	i = lin; j = col;
	while (!afara(i, j))
	{
		if (Map[i][j] != 0) return 0;
		i--; j--;
	}

	i = lin; j = col;
	while (!afara(i, j))
	{
		if (Map[i][j] != 0) return 0;
		i++; j++;
	}

	i = lin; j = col;
	while (!afara(i, j))
	{
		if (Map[i][j] != 0) return 0;
		i--; j++;
	}

	i = lin; j = col;
	while (!afara(i, j))
	{
		if (Map[i][j] != 0) return 0;
		i++; j--;
	}

	return 1;
}

void back(int line, int lev)
{
	int i, j;


	if (lev == N + 1)
	{
		printf("Solutia %d\n", ++Sol);
		for (i = 0; i < N; i++, printf("\n"))
			for (j = 0; j < N; j++)
				printf("%2d ", Map[i][j]);
	} else
	for (i = line; i < N; i++)
		for (j = 0; j < N; j++)
			if (good(i, j))
			{
				Map[i][j] = lev;
				back(i + 1, lev + 1);
				Map[i][j] = 0;
			}
}

int main()
{
	printf("Dati N: "); scanf("%d", &N);

	back(0, 1);


	return 0;
}