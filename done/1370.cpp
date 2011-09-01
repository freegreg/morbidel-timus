/*
 *  ACM Timus Online
 *  Magician - Problem 1370
 */

#include <stdio.h>


int N, Pos, A[1024];


int main()
{
	int i;


	scanf("%d %d", &N, &Pos);

	for (i = 0; i < N; i++)
		scanf("%d", A + i);

	for (i = 0; i < 10; i++)
		printf("%d", A[(i + Pos) % N]);
	printf("\n");


	return 0;
}
