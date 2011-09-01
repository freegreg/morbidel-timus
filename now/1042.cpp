/*
 *  ACM Timus Online
 *  Central Heating - Problem 1042
 *
 *  solutie: Gauss: transpun matricea apoi caut coloana (x1...x2) cu At * X = coloana de 1
 *  (e super usor dat fiind ca e modulo 2, scaderea e adunare, nu e impartire...)
 */

#include <stdio.h>

#define MAXN 251

int N;
int Sol[MAXN][MAXN], A[MAXN][MAXN], Lines[MAXN];


void readdata()
{
	int i, j;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		while (1)
		{
			scanf("%d", &j);
			if (j == -1) break;
			A[j][i] = 1;
		}
		A[i][0] = 1;
	}
}

void super_Gauss()
{
	int i, j, k, ok;

	for (i = 1; i < N; i++) /*  N - 1 pasi  */
	{
		/*  caut pe Xi  */
		for (ok = j = 1; j <= N; j++)
			if (!Lines[j] && A[j][i])
			{ 
				ok = 0; break; 
			}

		Lines[j] = 1;

		/*  trec termenii in cealalta parte  */
		for (k = 0; k <= N; k++)
			Sol[i][k] = (k == i) ? 0 : A[j][k];

		/*  unde apare Xi il scriu ca combinatia aia si modific coeficientii (modulo 2)  */
		for (k = 1; k <= N; k++)
			if (!Lines[k] && A[k][i])
			{
				A[k][i] = 0;
				for (j = 0; j <= N; j++)
					A[k][j] ^= Sol[i][j];
			}
	}
	Sol[N][0] = A[N][0];
	for (i = N; i; i--)
		for (j = i - 1; j; j--)
			if (Sol[j][i])
				Sol[j][i] = 0, Sol[j][0] ^= Sol[i][0];
	for (i = 1; i <= N; i++)
		if (Sol[i][0])
			printf("%d ", i);
}

int main()
{
	readdata();
	super_Gauss();

	return 0;
}
