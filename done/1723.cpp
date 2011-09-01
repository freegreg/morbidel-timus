/*
 * ACM Timus Online
 * Sandro's Book - Problem 1723
 *
 * solution: print the character which occurs the most times
 */

#include <cstdio>
#include <string.h>

int C[256];

int main()
{
	char ch, sol;
	int max = 0;

	memset(C, 0, sizeof(C));

	while (scanf("%c", &ch) == 1)
	{
		C[ch]++;
		if (C[ch] > max)
			max = C[ch], sol = ch;
	}

	printf("%c", sol);

	return 0;
}

