/*
 *  ACM Timus Online
 *  Sabotage - Problem 1290
 *
 *  solutie: sortare descrescatoare!
 */

#include <stdio.h>

int N, Max, Flag[25001];



int main()
{
	int i, j;

	scanf("%d", &N);

	for (Max = i = 0; i < N; i++)
	{
		scanf("%d", &j);
		Flag[j]++;
		if (j > Max)
			Max = j;
	}

	for (i = Max; i; i--)
		for (j = 0; j < Flag[i]; j++)
			printf("%d\n", i);

	return 0;
}
