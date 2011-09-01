/*
 *  ACM Timus
 *  C. Flags for Provinces
 */

#include <stdio.h>
#include <math.h>

#define MAXN	1024

int N;
short Mat[MAXN][MAXN];


int main()
{
	scanf("%d", &N);

	int i, j;
	int nsol, nstripes;

	// find nr of stripes: nstripes(nstripes+1)/2 = N

	int n = N;
	double sq;
	while (true)
	{
		sq = sqrtl(1 + 8 * n--);
		if (sq == (long)sq)
			break;
	}
	nstripes = (sq - 1) / 2;
	nsol = nstripes + 1;

	int cnt = 1;
	for (i = 0; i < nsol; i++)
		for (j = 0; j < nstripes; j++)
		{
			if (j < i)
				Mat[i][j] = Mat[j][i - 1];
			else
				Mat[i][j] = cnt++;
		};

	printf("%d\n", nsol);
	for (i = 0; i < nsol; i++)
	{
		printf("%d ", nstripes);
		for (j = 0; j < nstripes; j++)
		{
			printf("%d ", Mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}