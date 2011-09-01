/*
 *  ACM Timus Online
 *  Alchemy - Problem 1573
 */

#include <cstdio>


int B, R, Y, K;

int main()
{
	char s[16];
	int sol = 1;

	scanf("%d %d %d %d", &B, &R, &Y, &K);

	while (K--)
	{
		scanf("%s\n", &s);
		if (s[0] == 'B')
			sol *= B;
		else if (s[0] == 'R')
			sol *= R;
		else if (s[0] == 'Y')
			sol *= Y;
	}

	printf("%d", sol);

	return 0;
}

