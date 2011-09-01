/*
 * ACM Timus Online
 * Sandro's Biography - Problem 1786
 *
 * solution: assume every i as the position of S and compute the rest of operations
 */

#include <cstdio>
#include <string.h>

#define PASSWORD		"Sandro"
#define LOWER(ch)		((ch) >= 'a' && (ch) <= 'z')
#define UPPER(ch)		((ch) >= 'A' && (ch) <= 'Z')

int N, NP;
char S[256], P[256];

int Cost(int pos)
{
	int i, c = 0;


	for (i = 0; i < NP; i++)
	{
		if (S[pos + i] == P[i])
			continue;
		else if (LOWER(S[pos + i]) && UPPER(P[i]))	/* differente case */
		{
			if (S[pos + i] == P[i] + 32)		/* equal */
				c++;
			else
				c += 2;				/* different */
		}
		else if (UPPER(S[pos + i]) && LOWER(P[i]))	/* differente case */
		{
			if (S[pos + i] == P[i] - 32)		/* equal */
				c++;
			else
				c += 2;				/* different */
		}
		else
			c++;					/* different but same case */
	}

	return c * 5;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%s", &S);

	int i, c, min = 1000000;

	N = strlen(S);
	strcpy(P, PASSWORD);
	NP = strlen(P);

	for (i = 0; i <= N - NP; i++)
	{
		c = Cost(i);

		if (c < min)
			min = c;
	}

	printf("%d\n", min);

	return 0;
}

