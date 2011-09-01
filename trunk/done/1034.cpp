/*
 *  ACM Timus Online
 *  Queens in peaceful positions - Problem 1034
 *
 *  solutie: Luam cele (50, 3) comb de dame si back cu ele.
 */

#include <stdio.h>
#include <string.h>

#define MAXN 51

typedef short table[MAXN][MAXN];
table T, Cfg[100];
int N, Sol = 0, Nc = 0, L[MAXN], C[MAXN];


#define good(l, c) (l > 0 && c > 0 && l <= N && c <= N)



void mark(int l, int c, int value);

void readdata()
{
	int i;

	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", L + i, C + i);
		T[L[i]][C[i]] = -1;
		mark(L[i], C[i], 1);
	}
}

void mark(int l, int c, int value)
{
	int i, j;

	if (!good(l, c)) return;

	for (i = 1; i <= N; i++)
	{
		if (i != l) T[i][c] += value;
		if (i != c) T[l][i] += value;
	}

	for (i = l, j = c; good(i, j); i--, j--);
	for (i++, j++; good(i, j); i++, j++)
		if (T[i][j] != -1)
			T[i][j] += value;

	for (i = l, j = c; good(i, j); i++, j--);
	for (i--, j++; good(i, j); i--, j++)
		if (T[i][j] != -1)
			T[i][j] += value;

	T[l][c] = (value == -1) ? 0 : -1;
}

void back(int line, int col, int dame)
{
	int i, j, k, aiurea, dame_aiurea;


	/*  am pus 3 dame, verific configuratia daca a mai fost  */
	if (dame == 3)
	{
		for (i = 0; i < Nc; i++)
		{
			dame_aiurea = 0;
			for (j = 1; j <= N; j++)
				for (k = 1; k <= N; k++)
					if (T[j][k] * Cfg[i][j][k] < 0) /*  dame puse diferit  */
						j = k = 1000; 

			aiurea = (j >= 1000 || k >= 1000);
			if (!aiurea) return;
		}

		/*  verific daca cele 3 dame sunt pe alte casute decat cele initiale  */

		dame_aiurea = 0;
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (Cfg[0][i][j] * T[i][j] < 0)
					dame_aiurea++;

		if (dame_aiurea < 3 * 2) return;

		Sol++;
		memcpy(Cfg[Nc++], T, sizeof(T));
	} else
	for (i = line; i <= N; i++)
		for (j = col; j <= N; j++)
			if (T[i][j] == 0)
			{
				mark(i, j, 1);
				back(line + 1, 1, dame + 1);
				mark(i, j, -1);
			}
}

void solve()
{
	int i, j, k;

	memcpy(Cfg[Nc++], T, sizeof(T));


	for (i = 1; i <= N; i++)
		for (j = i + 1; j <= N; j++)
			for (k = j + 1; k <= N; k++)
			{
				mark(L[i], C[i], -1);
				mark(L[j], C[j], -1);
				mark(L[k], C[k], -1);
				
				int l, c, cc = 0;
				for (l = 1; l <= N; l++)
					for (c = 1; c <= N; c++)
						if (T[l][c] == 0)
							cc++;

				if (cc > 5) /*  esential pt evitarea TLE  */
					back(1, 1, 0);

				mark(L[i], C[i], 1);
				mark(L[j], C[j], 1);
				mark(L[k], C[k], 1);
			}

	printf("%d\n", Sol);
}

int main()
{
	readdata();
	solve();

	return 0;
}
