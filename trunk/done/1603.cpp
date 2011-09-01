/*
 *  ACM Timus Online
 *  Erudite - Problem 1603
 */

#include <stdio.h>
#include <string.h>

#define input	"input.txt"
#define MAXN	4

int nCuv;
char A[MAXN][MAXN + 1];
char szCuv[32];
bool M[MAXN][MAXN];
bool bSol;


void back(int l, int c, int k)
{
	if (bSol == true) return;

	if (k == strlen(szCuv))
	{
		bSol = true;
		return;
	}

	// avem caracterul k - 1 la i si j, mergem in vecinii cu caracterul k
	if (l > 0 && A[l - 1][c] == szCuv[k] && !M[l - 1][c])
	{
		M[l - 1][c] = true;
		back(l - 1, c, k + 1);
		if (bSol == true) return;
		M[l - 1][c] = false;
	}

	if (l < MAXN - 1 && A[l + 1][c] == szCuv[k] && !M[l + 1][c])
	{
		M[l + 1][c] = true;
		back(l + 1, c, k + 1);
		if (bSol == true) return;
		M[l + 1][c] = false;
	}

	if (c > 0 && A[l][c - 1] == szCuv[k] && !M[l][c - 1])
	{
		M[l][c -1] = true;
		back(l, c - 1, k + 1);
		if (bSol == true) return;
		M[l][c - 1] = false;
	}

	if (c < MAXN - 1 && A[l][c + 1] == szCuv[k] && !M[l][c + 1])
	{
		M[l][c + 1] = true;
		back(l, c + 1, k + 1);
		if (bSol == true) return;
		M[l][c + 1] = false;
	}
}

bool Validate()
{
	int i, j;

	for (i = 0; i < MAXN; i++)
		for (j = 0; j < MAXN; j++)
			if (A[i][j] == szCuv[0])
			{
				memset(M, false, sizeof(M));
				M[i][j] = true;

				bSol = false;
				back(i, j, 1);

				if (bSol)
					return true;
			}

	return false;
}


int main()
{
	int i;

	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	for (i = 0; i < MAXN; i++)
		gets(A[i]);

	scanf("%d", &nCuv);

	for (i = 0; i < nCuv; i++)
	{
		scanf("%s", &szCuv);

		bool bValid = Validate();

		printf("%s: %s\n", szCuv, bValid ? "YES" : "NO");
	}


	return 0;
}
