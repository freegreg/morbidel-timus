/*
 * ACM Timus Online
 * Turn for MEGA - Problem 1787
 *
 * solution: for each minute that passed, check the number of cars currently there
 */

#include <cstdio>

int N, K;


int main()
{
	int i, sum = 0, x;

	scanf("%d %d", &K, &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);
		sum += x - K;
		if (sum < 0)
			sum = 0;
	}

	printf("%d", sum);

	return 0;
}

