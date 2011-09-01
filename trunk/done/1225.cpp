// ACM Online
// Flags - Problem 1225

#include <stdio.h>

int n;
unsigned long a, b, c;

void main()
{
	a = b = c = 2;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b; b = c;
	}
	printf("%lu", c);
}