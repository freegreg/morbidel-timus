/*
 *  ACM Timus Online
 *  Crazy Notations - Problem 1295
 *
 *  solutie: retin doar ultimele 18 cifre... (rez e 0, 1, sau 2 oricum...)
 */

#include <stdio.h>

long N;


int main()
{
	__int64 one, put2, put3, put4;
	long i, n0;

	scanf("%ld", &N);

	put2 = put3 = put4 = 1;

	for (i = 0; i < N; i++)
	{
		put2 = (put2 * 2) % (__int64)(1e5);
		put3 = (put3 * 3) % (__int64)(1e5);
		put4 = (put4 * 4) % (__int64)(1e5);
		i = i;
	}
	one = 1 + put2 + put3 + put4;

	n0 = 0;
	while (1)
	{
		if (one % 10) break;
		n0++; one /= 10;
	}
	printf("%ld\n", n0);


	return 0;
}
