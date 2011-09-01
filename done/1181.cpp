/*
 *  ACM Timus Online
 *  Cutting a painted polygon - Problem 1181
 *
 *  Sol: DP a la optimal matrix chain product
 */


#include <stdio.h>
#include <string.h>

#define MIN(a, b)	((a) > (b) ? (b) : (a))
#define MAX(a, b)	((a) > (b) ? (a) : (b))

int N;
char S[1024];
short A[1024][1024];
bool Sol[1024][1024];


int POS(int n)
{
	if (n < 0)
		return n + N;
	else if (n >= N)
		return n % N;
	else 
		return n;
}

bool Triangle(int p1, int p2, int p3)
{
	return (S[p1] + S[p2] + S[p3] == 'R' + 'G' + 'B');
}

void GenerateSol(int i, int j)
{
	if (POS(j - i) == 2)
	{
		Sol[MIN(POS(i), POS(i + 1))][MAX(POS(i), POS(i + 1))] = true;
		Sol[MIN(POS(i + 1), POS(i + 2))][MAX(POS(i + 1), POS(i + 2))] = true;
		Sol[MIN(POS(i + 2), POS(i))][MAX(POS(i + 2), POS(i))] = true;
		
		//printf("%d %d %d\n", POS(i), POS(i + 1), POS(i + 2));
	}
	else if (A[i][j] >= 0)
	{
		//printf("%d %d %d\n", i, A[i][j], j);

		Sol[MIN(i, A[i][j])][MAX(i, A[i][j])] = true;
		Sol[MIN(A[i][j], j)][MAX(A[i][j], j)] = true;
		Sol[MIN(j, i)][MAX(j, i)] = true;

		GenerateSol(i, A[i][j]);
		GenerateSol(A[i][j], j);
	}
}

void Solve()
{
	int i, j, k;

	memset(A, -1, sizeof(A));

	for (k = 2; k <= N - 1; k++)
		for (i = 0; i < N - k; i++)
		{
			/* compute A[i][i + k] */
			if (k == 2)
			{
				A[i][i + k] = i + 1;	/* doesn't matter, should be >= 0. We will print these triangles anyway */
			}
			else if (S[i] != S[i + k])
			{
				for (j = i; j < N; j++)
				{
					if (Triangle(i, j, i + k))
					{
						if ((j == i + 1 && A[j][i + k] >= 0) || 
						    (j == i + k - 1 && A[i][j] >= 0) || 
						    (A[i][j] >= 0 && A[j][i + k] >= 0))
							A[i][i + k] = j;

						if (A[i][i + k] >= 0)	/* found a solution */
							break;
					}
				}
			}
		}

	memset(Sol, false, sizeof(Sol));
	GenerateSol(0, N - 1);

	for (i = 0; i < N; i++)
		for (j = i + 2; j < N; j++)
			if (Sol[i][j] && !(i == 0 && j == N - 1))	/* do not print sides of the original poly */
				printf("%d %d\n", i + 1, j + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d %s", &N, &S);
	

	/* always N - 3 diagonals */
	printf("%d\n", N - 3);

	Solve();

	return 0;
}

