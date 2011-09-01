// ACM Online
// Sum of Digits - Problem 1206

// solutie: 36 * 55 ^ (n - 1)

#include <stdio.h>
#include <string.h>

int n, a[1000];

void imul(int x)
{
	int i, k = 0;
	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / 10, a[i] %= 10;
	while (k)
		a[++a[0]] = k % 10, k /= 10;
}

void main()
{
	int i;
	scanf("%d", &n);
	a[0] = 2; a[1] = 6; a[2] = 3;
	for (i = 1; i < n; i++) imul(55);
	for (i = a[0]; i; printf("%d", a[i--]));
}