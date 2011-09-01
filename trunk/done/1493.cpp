/*
 *  ACM Timus Online
 *  One Step from Happiness - Problem 1493
 */

#include <stdio.h>

int N;


bool Lucky(int n)
{
	int s = 0;
	
	s += n % 10; n /= 10;
	s += n % 10; n /= 10;
	s += n % 10; n /= 10;

	s -= n % 10; n /= 10;
	s -= n % 10; n /= 10;
	s -= n;

	return s == 0;
}


int main()
{
	scanf("%d", &N);

	if (Lucky(N + 1) || Lucky(N - 1))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
