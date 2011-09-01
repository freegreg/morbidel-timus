/*
 * ACM Timus Online
 * Penalty Time - Problem 1636
 *
 * solution: compute the time of ZZZ if no rejected submissions. If it's < T1 -> "Dirty debug", otherwise "No chance"
 */

#include <cstdio>

int T1, T2;

int main()
{
	int i, nr, c;
	
	scanf("%d %d", &T1, &T2);

	c = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &nr);
		c += nr;
	}

	if (T2 - c * 20 < T1)
		printf("Dirty debug :(");
	else
		printf("No chance.");

	return 0;
}
