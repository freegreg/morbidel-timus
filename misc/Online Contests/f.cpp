/*
 *	Problem F - interesting number
 */


#include <stdio.h>


int N;

int main()
{
	scanf("%d", &N);

	if (N == 1) printf("14\n");
	else
	if (N == 2) printf("155\n");
	else
	{
		int i;

		printf("1575");
		for (i = 0; i < N - 3; i++)
			printf("0");
		printf("\n");
	}


	return 0;
}

