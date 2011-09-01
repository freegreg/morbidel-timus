/*
 *  ACM Timus Contest 28 Feb 2004
 *  Problem G - One Way Ticket
 *
 *  solutie: 11...111 0 88...8 90, sunt N/2 - 1 de 1 si N/2 - 2 de 8 (!)
 */

#include <stdio.h>

int N;


int main()
{
	int i;

	scanf("%ld", &N);

	if (N == 2) printf("10\n");
	else
	{
		for (i = 1; i <= N / 2 - 1; i++)
			printf("1");
		printf("0");
		for (i = 1; i <= N / 2 - 2; i++)
			printf("8");
		printf("90\n");
	}

	return 0;
}
