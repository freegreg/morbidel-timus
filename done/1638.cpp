/*
 * ACM Timus Online
 * Bookworm - Problem 1638
 *
 * solution: simulation
 */

#include <cstdio>

int Pages, Cover, First, Second;


int main()
{
	scanf("%d %d %d %d", &Pages, &Cover, &First, &Second);

	int sol; 

	if (Second > First)
		sol = 2 * Cover + (2 * Cover + Pages) * (Second - First - 1);
	else if (Second == First)
		sol = Pages;
	else
		sol = Pages + (2 * Cover + Pages) * (First - Second);

	printf("%d\n", sol);

	return 0;
}
