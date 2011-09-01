/*
 *  ACM Timus Online
 *  Fuses - Problem 1327
 */

#include <stdio.h>

long A, B, Sol;


int main()
{
	scanf("%ld %ld", &A, &B);

	A -= (A & 1);
	B += (B & 1);

	Sol = (B - A) / 2;

	printf("%ld\n", Sol);

	return 0;
}
