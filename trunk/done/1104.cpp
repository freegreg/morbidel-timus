/*
 *  ACM Timus Online
 *  Don't ask woman about her age - Problem 1104
 *
 *  solutie: calculez restul pt fiecare baza in parte...
 */

#include <stdio.h>

char ch;
int r[50], k;


int main()
{
	int baza, num, nmax = 1;

	while (scanf("%c", &ch) == 1)
	{
		if (ch < '0') break;
		if (ch <= '9') num = ch - '0'; else
		if (ch <= 'Z') num = ch - 'A' + 10;
		if (num > nmax) nmax = num;
		for (baza = nmax + 1; baza <= 36; baza++)
			r[baza] = (r[baza] * baza + num) % (baza - 1);
	}

	for (k = nmax + 1; k <= 36; k++)
		if (!r[k]) break;

	(k == 37) ? printf("No solution.\n") : printf("%d\n", k);

	return 0;
}
