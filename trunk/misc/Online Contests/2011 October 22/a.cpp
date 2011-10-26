/*
 * ACM Timus Online Judge Contest 22 October 2011
 * Problem A - GOV Chronicles
 */

#include <cstdio>

int N, Chronic[12] = {5, 20, 12, 2, 1, 4, 6, 1, 4, 4, 1, 0};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d", &N);
	printf("%d", Chronic[N]);

	return 0;
}