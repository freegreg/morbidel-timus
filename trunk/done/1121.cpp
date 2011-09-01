/*
 *  ACM Online
 *  Branches - Problem 1121
 * 
 *  solutie: fac OR intre cele mai apropiate...
 */

#include <stdio.h>

#define inside(l, c) (l > 0 && c > 0 && l <= M && c <= N)

int N, M, A[151][151];



void readdata()
{
	int i, j;

	scanf("%d %d", &M, &N);
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &A[i][j]);
}

int sum(int l, int c, int k)
{
	int i, s = 0;

	c -= k;

	for (i = 1; i <= k; i++, l--, c++)
		s |= inside(l, c) ? A[l][c] : 0;
	for (i = 1; i <= k; i++, l++, c++)
		s |= inside(l, c) ? A[l][c] : 0;
	for (i = 1; i <= k; i++, l++, c--)
		s |= inside(l, c) ? A[l][c] : 0;
	for (i = 1; i <= k; i++, l--, c--)
		s |= inside(l, c) ? A[l][c] : 0;

	return s;
}

void solve()
{
	int i, j, k, s;

	for (i = 1; i <= M; i++, printf("\n"))
		for (j = 1; j <= N; j++)
			if (A[i][j] > 0)
				printf("-1 ");
			else
			{
				for (s = 0, k = 1; !s && k <= 5; k++)
					s = sum(i, j, k);
				printf("%d ", s);
			}
}

int main()
{
	readdata();
	solve();

	return 0;
}
