/*
 *  ACM Timus
 *  Pass Licenses
 */

#include <stdio.h>
#include <stdlib.h>

#define input_file "file.in"

short K, M, N;
long A[32][32];		// A[i][j] -> a number with the bits corresponding the licenses
short  P[32];		// generated license pack
bool bSolution, Flag[32];


void Readdata()
{
#ifndef ONLINE_JUDGE
	freopen(input_file, "rt", stdin);
#endif
	scanf("%d %d %d", &K, &N, &M);

	int i, j;

	for (i = 0; i < 32; i++)
		for (j = 0; j < 32; j++)
			A[i][j] = -1;

	for (i = 0; i < M; i++)
	{
		int n1, n2, type;

		scanf("%d %d %d", &n1, &n2, &type);

		if (A[n1][n2] == -1)
		{
			A[n1][n2] = (long)1 << (long)type;
		} else
			A[n1][n2] |= (long)1 << (long)type;


		A[n2][n1] = A[n1][n2];
	}
}

void DF(int nod, long rights)
{
	Flag[nod] = true;

	if (nod == 1 || bSolution)
	{
		bSolution = true;
		return;
	}

	int i;
	for (i = 0; i < N; i++)
		if (!Flag[i] && A[nod][i] >= 0 && (A[nod][i] & rights) > 0)
		{
			DF(i, rights);
		}
}

// generate (K, k) combinations
void back(int pos, int k)
{
	int i;

	if (pos == k)
	{
		long rights = 0;

		for (i = 0; i < k; i++)
			rights |= (long)1 << (long)P[i];

		bSolution = false;

		for (i = 0; i < N; i++)
			Flag[i] = false;

		DF(0, rights);

		if (bSolution)
		{
			printf("%d\n", k);
			for (i = 0; i < k; i++)
					printf("%d ", P[i]);
			printf("\n");

			exit(0);
		}
	} else
	for (i = pos == 0 ? 0 : P[pos - 1] + 1; i < K; i++)
	{
		P[pos] = i;

		back(pos + 1, k);

		P[pos] = 0;
	}
}

void Solve()
{
	// generate all 2^K combinations of 0 and 1 with i of 1
	int i;

	for (i = 1; i <= K; i++)
	{
		back(0, i);
	}
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
