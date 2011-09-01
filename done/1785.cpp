/*
 * ACM Timus Online
 * Lost in Localization - Problem 1785
 */

#include <stdio.h>

int N;
char words[9][16] = {"few", "several", "pack", "lots", "horde", "throng", "swarm", "zounds", "legion"};
int limits[9] = {4, 9, 19, 49, 99, 249, 499, 999, 10000};

int main()
{
	int i;


	scanf("%d", &N);

	for (i = 0; i < 10; i++)
		if (limits[i] >= N) 
			break;

	printf("%s", words[i]);

	return 0;
}

