/*
 *  ACM Timus Online
 *  K-inversions - Problem 1523
 */

#include <stdio.h>
#include <string.h>

#define input	"file.in"
#define MAXN	20001

int N, K;
int A[MAXN], Row[MAXN], Row2[MAXN];
long Sol = 0, Inv;


void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	int i;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		scanf("%d", A + i);
}


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


void Solve()
{
	Inv = 0;

	memcpy(Row, A, sizeof(A));
	merge(0, N - 1);

	printf("%ld\n", Inv);
}

int main()
{
	ReadData();
	Solve();

	return 0;
}
