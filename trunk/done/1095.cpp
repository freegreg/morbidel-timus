/*
 *  ACM Online
 *  Nikifor 3 - Problem 1095
 *
 *  solutie: caut secventa de 1,2,3,4 care d† resturile 0..6 si o pun la coad†
 *  iau restul primelor si pun secventa cu restul 6 - 4 * el. (thanks Radu...)
 */

#include <stdio.h>
#include <math.h>

int k, flag[10], mods[] = {4123, 4231, 4213, 1234, 3421, 1324, 1243};
__int64 left;


int main()
{
	int i, j, rest;
	char ch;

	scanf("%d\n", &k);
	for (; k--; )
	{
		for (j = 0; j < 10; flag[j++] = 0);
		left = 0;
		do
		{
			scanf("%c", &ch);
			if (ch < '0' || ch > '9') break;
			flag[ch - '0']++;
		}
		while (1);
		flag[1]--; flag[2]--; flag[3]--; flag[4]--;
		for (i = 9; i >= 0; i--)
			for (j = 0; j < flag[i]; j++)
				left = left * (__int64)10 + i;
		/*  caz special, are doar 0 -> Œi punem Œn coad† */
		if (!left)
		{
			printf("4123");
			for (i = 0; i < flag[0]; i++)
				printf("0");
		} else
		{
			printf("%I64d", left);
			rest = left % 7;
			printf("%d", mods[rest]);
		}
		printf("\n");
	}

	return 0;
}
