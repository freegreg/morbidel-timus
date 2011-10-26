/*
 * ACM Timus Online Judge Contest 22 October 2011
 * Problem D - Centipede's Morning
 */

#include <cstdio>

int Left, Right, Res;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	scanf("%d %d", &Left, &Right);

	Res = 80 + 2 * (Right - 40) + 40;

	printf("%d", Res);

	return 0;
}