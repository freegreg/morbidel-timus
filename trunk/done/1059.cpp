/*
 *  ACM Online
 *  Expression - Problem 1059
 *  desfacem polinomul †la cu Horner altfel are prea mult...
 */

#include <stdio.h>

long n, i;


int main()
{
	scanf("%ld", &n);
	printf("0\n");
	for(i = 1; i <= n; i++)
		printf("X\n*\n%ld\n+\n", i);
	return 0;
}
