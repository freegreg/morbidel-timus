// ACM Online
// Boxes - Problem 1114
// in cate moduri putem aseza <= A bile albe si <= B bile negre in <= N cutii ?
//							  
// formula este: 1 / (n!)^2 * suma(1, n) din (a + i)(b + i)
//							  

#include <stdio.h>

int n, a, b, flag[200], r[2000];


void imul(int x)
{
	int i, k = 0;
	for (i = 1; i <= r[0]; i++)
	{
		r[i] = r[i] * x + k;
		k = r[i] / 10;
		r[i] %= 10;
	}
	while (k)
		r[++r[0]] = k % 10, k /= 10;
}

void prime(int mode, int num)
{
	for (int d = 2; num > 1; d++)
		while (num % d == 0)
		{
			num /= d;
			if (!mode) flag[d]++; else flag[d]--;
		}
}

void main()
{
	int i, j;
	scanf("%d %d %d", &n, &a, &b);
	for (i = 1; i <= n; i++)
	{
		prime(0, a + i); prime(0, b + i);
		prime(1, i); prime(1, i);
	}
	r[0] = r[1] = 1;
	for (i = 0; i < 200; i++)
		for (j = 0; j < flag[i]; j++)
			imul(i);
	for (i = r[0]; i; printf("%d", r[i--]));
}