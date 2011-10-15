/*
 * ACM Timus Online Judge Contest 15 October 2011
 * Problem H - New Year Cruise
 */

#include <cstdio>

#define MAX(a, b)		((a) > (b) ? (a) : (b))

int N, A[100][100];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int i, j, k, max;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		};

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			if (A[i][j] == 0)
				continue;

			// Vladi -> Moscow
			if (i < j && j - i > 1)
			{
				for (k = i; k < j; k++)
				{
					A[k][k + 1] += A[i][j];
				}
			}
			// Moscow -> Vladi
			else if (i > j && i - j > 1)
			{
				for (k = i; k > j; k--)
				{
					A[k][k - 1] += A[i][j];
				}
			}
		};


	// get maximum for each pair of stations
	max = 0;
	for (i = 0; i < N - 1; i++)
	{
		if (MAX(A[i][i + 1], A[i + 1][i]) > max)
		{
			max = MAX(A[i][i + 1], A[i + 1][i]);
		}
	}

	if (max % 36 == 0)
		max /= 36;
	else
		max = 1 + max / 36;
	printf("%d", max);

	return 0;
}