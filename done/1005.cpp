/*
 *  ACM Timus Online
 *  Stone Pile - Problem 1005
 *
 *  solutie: dinamica: facem rucsac pana la jumatate din suma...
 */

#include <stdio.h>
#include <string.h>

long n, v[50], max, suma = 0;
unsigned char s[126000L];


long val(long x) /*  ret s[x]  */
{
	return (s[x / 8] >> (x % 8)) & 1;
}

void check(long x)  /*  s[x] = 1  */
{
	s[x / 8] |= (1 << (x % 8));
}

int main()
{
	long i, j;

	memset(s, 0, sizeof(s));

	scanf("%ld", &n);
	for (i = 0; i < n; i++)
		scanf("%ld", &v[i]), suma += v[i];

	check(v[0]);
	max = v[0];
	for (i = 1; i < n; i++)
	{
		for (j = max; j; j--)
			if (val(j))
			{
				check(j + v[i]);
				if (j + v[i] > max) 
					max = j + v[i];
			}
		check(v[i]);
		
		if (max > suma / 2) 
			max = suma / 2;
		if (val(suma / 2)) break;
	}
	for (i = max; i; i--)
		if (val(i)) break;

	j = suma - 2 * i;
	printf("%ld\n", j > 0 ? j : -j);

    return 0;
}