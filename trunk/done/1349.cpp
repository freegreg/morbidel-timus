/*
 *  ACM Timus Online
 *  Farm - Problem 1349
 */

#include <stdio.h>

int a, b, c, n;

int main()
{
	scanf("%d", &n);

	if (n == 1)
		printf("1 2 3\n");
	else
	if (n == 2)
		printf("3 4 5\n");
	else
		printf("-1\n");

	return 0;
}