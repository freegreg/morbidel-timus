/*
 *  ACM Timus Online
 *  Columns of Numbers - Problem 1506
 */

#include <stdio.h>
#include <string.h>

#define INPUT	 "input.txt"

int N, K;
int V[100];
int M[100][100];


void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(INPUT, "r", stdin);
	#endif


	int i;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		scanf("%d", V + i);
}

void Solve()
{
	int i, j, k = 0;
	int linii = N / K + (N % K == 0 ? 0 : 1);


	memset(M, -1, sizeof(M));

	for (i = 0; k < N && i < K; i++)
		for (j = 0; k < N && j < linii; j++)
			M[j][i] = V[k++];

	for (i = 0; i < linii; i++, printf("\n"))
		for (j = 0; j < K; j++)
			if (M[i][j] != -1)
			{
				printf("%4d", M[i][j]);
			};
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
