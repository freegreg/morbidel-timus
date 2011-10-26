/*
 * ACM Timus Online Judge Contest 22 October 2011
 * Problem E - Bicycle Codes
 */

#include <cstdio>

int C1, C2;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d %d", &C1, &C2);
	
	int i;
	for (i = 0; i < 10000; i++)
	{
		if (((i & 1) && i == C2) || (!(i & 1) && i == C1))
		{
			printf("yes");
			return 0;
		}
	}

	printf("no");

	return 0;
}