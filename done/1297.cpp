/*
 *  ACM Timus Online
 *  Palindrome - Problem 1297
 *
 *  solutie: burbelia aia in N^2...
 */

#include <stdio.h>
#include <string.h>

long N;
char S[1010];


int searchpal(int poz)
{
	int len1, len2, l, r;

	for (l = r = poz; (l >= 0 || r < N) && S[l] == S[r]; l--, r++);
	len1 = r - l - 1;

	for (l = poz - 1, r = poz; (l >= 0 || r < N) && S[l] == S[r]; l--, r++);
	len2 = r - l - 1;

	return len1 > len2 ? len1 : len2;
}


int main()
{
	int i, clen, pmax, lmax;

	scanf("%s", &S);
	N = strlen(S);

	for (lmax = i = 0; i < N; i++)
	{
		clen = searchpal(i);
		if (clen > lmax)
			lmax = clen, pmax = i - lmax / 2;
	}

	for (i = pmax; i < pmax + lmax; i++)
		printf("%c", S[i]);
	printf("\n");

	return 0;
}
