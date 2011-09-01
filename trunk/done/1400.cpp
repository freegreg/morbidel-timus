/*
 *  ACM Timus - Cellular Characters
 */

#include <stdio.h>
#include <string.h>

#define INF		100000

int Best;
int M, N, Total, Last;
int Map[256][256];
int MapSol[256][256];


int Valid(int l, int c)
{
	if (l < 0 || l >= M || c < 0) return 0;
	if (l == M - 1 && c > Last || l != M - 1 && c >= N) return 0;

	return 1;
}

void Go(int l, int c, int dist)
{
	if (dist > M / 2 + N / 2) return;
	if (!Valid(l, c) || Map[l][c] <= dist) return;

	Map[l][c] = dist;

	// up
	if (Valid(l - 1, c))
		Go(l - 1, c, dist + 1);

	// down
	if (Valid(l + 1, c))
		Go(l + 1, c, dist + 1);

	// left
	if (Valid(l, c - 1))
		Go(l, c - 1, dist + 1);
	else
	if (c == 0 && l > 0)
		Go(l - 1, N - 1, dist + 1);
	else
	if (c == 0 && l == 0)
		Go(M - 1, Last, dist + 1);

	// right
	if (Valid(l, c + 1))
		Go(l, c + 1, dist + 1);
	else
	if (c == N && l < M - 1)
		Go(l + 1, 0, dist + 1);
	else
	if (c == Last && l == M - 1)
		Go(0, 0, dist + 1);
}

void Readdata()
{
	scanf("%d %d", &Total, &N);

	M = Total / N + 1;
	Last = Total % N;
	if (Last == 0)
		M--, Last = N - 1;
	else
		Last--;
}

int Cost(int line, int col)
{
	if (line < 0 || line >= M) return INF;

	int i, j, cost = 0;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			Map[i][j] = INF;

	Go(line, col, 0);

	cost = 0;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cost += ((i < M - 1 || i == M - 1 && j <= Last) ? Map[i][j] : 0);

	return cost;
}

void Solve()
{
	int i, j, cost;

	Best = INF;
	j = (M & 1) ? M / 2 : M / 2 - 1;

	for (i = j - 1; i <= j + 1; i++)
		if ((cost = Cost(i, 0)) < Best)
		{
			Best = cost;
			memcpy(MapSol, Map, sizeof(Map));
		}

	printf("Mean = %.2lf\n", (double)Best / (double)Total);
	for (i = 0; i < M; i++, printf("\n"))
		for (j = 0; j < (i == M - 1 ? Last + 1: N); j++)
			printf("%d ", MapSol[i][j]);
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
