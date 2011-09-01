// ACM Online
// Factorials !!! - Problem 1083

#include <stdio.h>
#include <string.h>

char kk[20];
int k, n;
unsigned long rez = 1, t2;

void main()
{
	int i;
	scanf("%d %s", &n, &kk);
	k = strlen(kk);
	if (n % k == 0)
		for (i = 1; i <= n / k; i++)
			t2 += k, rez *= t2;
	else
	{
		t2 = n % k; rez = t2;
		for (i = 1; i <= n / k; i++)
			t2 += k, rez *= t2;
	}
	printf("%lu", rez);
}
