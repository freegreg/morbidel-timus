// ACM Online
// Maximum - Problem 1079

#include <stdio.h>

long n;
int a[100000L], m[100000L];

void main()
{
	long i;
	int max = 1;
	a[0] = m[0] = 0; a[1] = m[1] = 1;
	for (i = 2; i <= 100000L; i++)
	{
		a[i] = i & 1 ? a[i / 2] + a[i / 2 + 1] : a[i / 2];
		if (a[i] > max) max = a[i];
		m[i] = max;
	}
	do
	{
		scanf("%ld", &n);
		if (!n) break;
		printf("%d\n", m[n]);
	} while (1);
}