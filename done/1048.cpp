// ACM Online
// Superlong Sums - Problem 1048

#include <stdio.h>

long n;

int main()
{
	long i, j;
	int a, b, c9, o;
	scanf("%d", &n);
	if (!n) return 0;
	o = c9 = 0;
	scanf("%d %d", &a, &b);
	if (a + b >= 10) printf("1");
	o = (a + b) % 10;
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		if (a + b >= 10)
		{
			printf("%d", o + 1);
			for (j = 0; j < c9; j++) printf("0");
			c9 = 0; o = (a + b) % 10;
		}
		if (a + b == 9) c9++;
		if (a + b < 9)
		{
			printf("%d", o);
			for (j = 0; j < c9; j++) printf("9");
			c9 = 0; o = a + b;
		}
	}
	printf("%d", o);
	for (j = 0; j < c9; j++) printf("9");
	return 0;
}
