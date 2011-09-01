/*
 *  ACM Timus Online
 *  In The Army Now - Problem 1090
 *
 *  solutie: ni se cere vectorul cu cele mai multe inversiuni, deci "merge sort"...
 */

#include <stdio.h>

#define MAXN 10010

int K, N, Row[MAXN], Row2[MAXN];
long Inv, MaxInv = -1, MaxRow;


void merge(int l, int r)
{
	int m = (l + r) / 2, i = l, j = m + 1, p = 0;

	if (l == r) return;

    merge(l, m);
    merge(m + 1, r);

    while (i <= m || j <= r)
    	if ((Row[j] < Row[i] && j <= r) || i > m)
        	Row2[l + p++] = Row[j++], Inv += m - i + 1;
        else Row2[l + p++] = Row[i++];
    for (i = l; i <= r; i++) 
		Row[i] = Row2[i], Row2[i] = 0;
}

int main()
{
	int i, j;

	scanf("%d %d", &N, &K);

	for (i = 1; i <= K; i++)
	{
		for (Inv = j = 0; j < N; j++)
			scanf("%d", &Row[j]);
		merge(0, N - 1);
		if (Inv > MaxInv)
			MaxInv = Inv, MaxRow = i;
	}

	printf("%d\n", MaxRow);

	return 0;
}
