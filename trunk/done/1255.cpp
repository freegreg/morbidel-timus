/*
 *  ACM Online
 *  Graveyard of the Cosa Nostra - Problem 1255
 *  color†m harta astfel: 1,2,3...k,1,2,3...k, ..., pƒn† la n
 *  2,3...k,1, 2,3...1, ..., n... si tot asa. R†spunsul e minimul frecventelor (!)
 */

#include <stdio.h>

long n, k, sol;

int main()
{
	scanf("%ld %ld", &n, &k);
	if (k > n) 
		sol = 0; else
	if ((n % k) * 2 - k < 0) 
		sol = n / k * (n + n % k); 
	else
		sol = n / k * (n + n % k) + 2 * (n % k) - k;
	printf("%ld\n", sol);
	return 0;
}