/*
 *  ACM Timus Online
 *  Teamwork - Problem 1581
 */

#include <stdio.h>

#define INPUT	"input.txt"
int N;



int main()
{
	#ifndef ONLINE_JUDGE
	freopen(INPUT, "r", stdin);
	#endif

	int x, last, cnt;

	scanf("%d", &N);

	last = -1;
	cnt = 0;
	while (N--)
	{
		scanf("%d", &x);

		if (last == -1)
			last = x, cnt = 1;
		else
		if (last == x)
			cnt++;
		else
		if (last != x)
		{
			printf("%d %d ", cnt, last);
			cnt = 1;
			last = x;
		}
	}

	printf("%d %d\n", cnt, last);


	return 0;
}
