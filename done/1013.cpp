// ACM Online
// K-based Numbers. Version 3 - Problem 1013

// formula este: b[n] = (b[n - 2] +  b[n - 1]) * (k - 1)

#include <stdio.h>
#include <string.h>

int n, k;
long sol = 0;
typedef int HUGE[2000];
HUGE b, b1, b2;

void imul(HUGE &a, int x)
{
	int i, k = 0;
	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / 10, a[i] %= 10;
	while (k)
		a[++a[0]] = k % 10, k /= 10;
}

void add(HUGE &a, HUGE b)      // a += b
{
	int i, k = 0;
	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / 10, a[i] %= 10;
	if (k) a[++a[0]] = k;
}

void main()
{
	int i;
	scanf( "%d %d", &n, &k);
	b2[0] = 1; b2[1] = k - 1;
	b1[0] = b1[1] = 1;
	imul(b1, k * (k - 1));
	if (n == 1) b1[0] = 1, b1[1] = k - 1;
	for (i = 3; i <= n; i++)
	{
		memcpy(b, b1, sizeof(b1));
		add(b1, b2);
		imul(b1, k - 1);
		memcpy(b2, b, sizeof(b));
	}
	for (i = b1[0]; i; printf("%d", b1[i--]));
}