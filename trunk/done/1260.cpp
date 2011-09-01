/*
 *  ACM Timus Online
 *  A nudnik photographer - Problem 1260
 *
 *  solutie: a[i][j] -> perm de i care incep cu j si sar maxim 2. 
 *  a[i][1] = a[i - 1][1] + a[i - 1][2], a[i][2] = a[i - 1][2] + a[i - 3][2]. 
 *  Raspunsul e a[n][1]...
 */

#include <stdio.h>

int n;
__int64 a1, a2, a11, a12, a22, a32;


int main()
{
	int i;
	scanf("%ld", &n);

	if (n < 4) 
		printf("%d\n", n == 3 ? 2 : 1); 
	else
	{
		a11 = a12 = 2; a22 = 1; a32 = 0;
		for (i = 4; i <= n; i++)
		{
			a1 = a11 + a12; 
			a2 = a12 + a32;
			a11 = a1; a32 = a22; 
			a22 = a12; a12 = a2;
		}
		printf("%I64d\n", a1);
	}

	return 0;
}
