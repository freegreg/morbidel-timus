/*
 *  ACM Timus Online
 *  Routing - Problem 1072
 *
 *  solutie: BF
 */

#include <stdio.h>

#define MAXN 100

int N, X, Y, Ints[MAXN], A[MAXN][MAXN], Flag[MAXN], Tata[MAXN], Q[MAXN];
__int64 PC[MAXN][10];


void readdata()
{
	__int64 ip, mask;
	int i, j, k, x, ch;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &Ints[i]);

		for (j = 0; j < Ints[i]; j++)
		{
			/*  ip  */
			ip = mask = 0;
			for (k = 0; k < 4; k++)
			{
				scanf("%d%c", &x, &ch);
				ip = ip * 256 + (__int64)x;
			}
			/*  mask  */
			for (k = 0; k < 4; k++)
			{
				scanf("%d%c", &x, &ch);
				mask = mask * 256 + (__int64)x;
			}
			PC[i][j] = ip & mask;
		}
	}
	scanf("%d %d", &Y, &X); /*  sa scapam de afisarea inversa...  */
}

void make_graf()
{
	int i, j, k, l, was;

	for (i = 1; i <= N; i++)
		for (j = i + 1; j <= N; j++)
		{
			was = 0;

			for (k = 0; k < Ints[i]; k++)
				for (l = 0; l < Ints[j]; l++)
					if (PC[i][k] == PC[j][l])
						was = 1, k = l = 10;
			A[i][j] = A[j][i] = was;
		}
}

void bf(int nod)
{
	int i, lev, mlev;

	Flag[nod] = 1; Q[lev = 0] = nod; mlev = 1;

	for (; lev < mlev; lev++)
		for (i = 1; i <= N; i++)
			if (A[Q[lev]][i] && !Flag[i])
			{
				Q[mlev++] = i;
				Flag[i] = 1; Tata[i] = Q[lev];
			}
}

void solve()
{
	make_graf();

	Tata[Y] = Tata[X] = -1;
	bf(X);

	if (Tata[Y] == -1 && X != Y)
		printf("No\n");
	else
	{
		printf("Yes\n");
		for (N = Y; N > 0; N = Tata[N])
			printf("%d ", N);
	}
}

int main()
{
	readdata();
	solve();
	return 0;
}
