/*
 *  ACM Online
 *  Buttons - Problem 1023
 *
 *  solutie: -1 + cel mai mic divizor >= 3
 */

#include <stdio.h>

long k, l, min;


int main()
{
	scanf("%ld", &k);

	for (min = k, l = 2; l * l <= k; l++)
		if (k % l == 0)
		{
			if (l > 2 && l < min) min = l;
			if (k / l < min && k / l > 2) min = k / l;
		}

	printf("%ld\n", min - 1);

	return 0;
}
