/*
 *  ACM Timus Online
 *  Babies - Problem 1339
 */

#include <stdio.h>

#define MAXN 100

long N, Boys[MAXN], Girls[MAXN];


int main()
{
	long i, j, k;

	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", Boys + i);
		Girls[Boys[i]] = i;
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &k);
		if (Girls[i] == 0)
			Girls[i] = k;

	}

	for (i = 1; i <= N; i++)
		if (Boys[i] != 0)
			Girls[Boys[i]] = i;

	for (i = 1; i <= N; i++)
		printf("%d ", Boys[i]);


	return 0;
}
