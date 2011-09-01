/*
 * ACM Timus Online
 * Cipher Message - Problem 1654
 *
 * solution: when a 'XX' is found, delete also neighbouring characters if they are equal.
 */

#include <cstdio>
#include <string.h>

char S[200001];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%s", &S);

	int i, n = strlen(S);

	for (i = 1; i < n; i++)
	{
		if (S[i] == S[i - 1])
		{
			int l, r, c = 2;

			l = i - 1;
			while (i + 1 < n && S[i + 1] == S[i])
				c++, i++;

			l += c / 2 - 1;
			r = l + 1;

			while (l >= 0 && r < n && S[l] == S[r])
			{
				S[l] = S[r] = 0;

				/* find 2 valid values */
				while (l >= 0 && S[l] == 0)
					l--;
				while (r < n && S[r] == 0)
					r++;
			}
		}
	}

	for (i = 0; i < n; i++)
		if (S[i] != 0)
			printf("%c", S[i]);
	printf("\n");

	return 0;
}

