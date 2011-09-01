/*
 * ACM Timus Online
 * Chocolate 2 - Problem 1639
 *
 * Solution: the number of moves is constant, regardless on how we made the cuts.
 * 		Total number of moves is: M - 1 + M * (N - 1). If it's even second player wins, otherwise first
 */

#include <cstdio>

int M, N;

int main()
{
	scanf("%d %d", &M, &N);

	int sol = M - 1 + M * (N - 1);

	if (sol & 1)
		printf("[:=[first]");
	else
		printf("[second]=:]");

	return 0;
}

