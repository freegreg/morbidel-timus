// ACM Online
// Power - Problem 1110

// find all X so that X^N mod M = Y holds
// N, M < 999, Y < 99

#include <stdio.h>

int n, m, y, how = 0;

int modulo(int a, int b)
{
	int x;
	if (b == 1) return a % m; else
	{
		x = modulo(a, b / 2);
		if (b % 2) return (((x * x) % m) * a) % m;
		else return (x * x) % m;
	}
}

void main()
{
	int i, mod;
	scanf("%d %d %d", &n, &m, &y);
	for (i = 0; i < m; i++)
	{
		mod = modulo(i % m, n);
		if (mod == y)
			printf("%d ", i), how++;
	}
	if (!how) printf("-1");
}