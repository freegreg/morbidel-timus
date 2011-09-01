/*
 *  ACM Timus Online
 *  Checkers - Problem 1334
 */

#include <stdio.h>

#define inside(l, c) (l > 0 && l < 9 && c > 0 && c < 9)

char strMove[3];
int nLine, nColumn, nMove, nTable[10][10];
short dirs[8][2] = {{-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}, {-1, +1}, {+1, -1}, {+1, +1}, {-1, -1}};



int main()
{
	#ifndef ONLINE_JUDGE
		freopen("file.in", "r", stdin);
	#endif


	int i;

	for (nMove = 0; scanf("%s", &strMove) == 1; nMove++)
	{
		nLine = strMove[0] - 'a' + 1;
		nColumn = strMove[1] - '0';

		nTable[nLine][nColumn] = (nMove & 1) + 1;


		for (i = 0; i < 8; i += 2)
			if (inside(nLine + dirs[i][0], nColumn + dirs[i][1]) && 
				nTable[nLine + dirs[i][0]][nColumn + dirs[i][1]] * nTable[nLine][nColumn] == 2)
			{
				printf("%d\n", nMove + 1);
				return 0;
			}
	}

	printf("Draw\n");


	return 0;
}
