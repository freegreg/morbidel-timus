// ACM Online
// Brave balloonists - 1049

#include <stdio.h>

int flag[10000], max = 0;
long total = 1;

void prime(int n)
{
	int x = n, p = 2;
	do {
		while (!(x % p))
		{
			flag[p]++; x /= p;
			if (p > max) max = p;
		}
		p++;
	} while (x > 1);
}

void main()
{
	int i, n;
	for(i = 0; i < 10; i++)
	{
		scanf("%d\n", &n);
		prime(n);
	}
	for(i = 0; i <= max; i++)
		if (flag[i]) total *= flag[i] + 1;
	printf("%ld", total % 10);
}