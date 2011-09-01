/*
 *  ACM Timus Online
 *  Presents - Problem 1366
 */

#include <stdio.h>
#include <string.h>

#define BASE	1000000
#define FORMAT "%06I64d"
#define sgn(x) ((x) < 0 ? (-1) : (1))

int N;
__int64 A[512], A1[512];



void imul(__int64 *a, __int64 x)
{
	__int64 i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / BASE, a[i] %= BASE;

	while (k)
		a[++a[0]] = k % BASE, k /= BASE;
}


void add(__int64 *a, __int64 x)
{
	__int64 i, k = 0;

	a[1] += x;

	for (i = 2; i <= a[0] + 1; i++)
		if (a[i - 1] < 0 || a[i - 1] >= BASE)
			a[i - 1] += BASE * sgn(x), a[i] += sgn(x);
	if (a[a[0] + 1] > 0)
		a[0]++;
}


int main()
{
	int i;


	scanf("%d", &N);

	A1[0] = 1; A1[1] = 0;
	for (i = 2; i <= N; i++)
	{
		memcpy(A, A1, sizeof(A1));
		imul(A, i);
		add(A, (i & 1) ? -1 : 1);
		memcpy(A1, A, sizeof(A));
	}

	printf("%I64d", A1[A1[0]]);
	for (i = A1[0] - 1; i > 0; i--)
		printf(FORMAT, A1[i]);
	printf("\n");


	return 0;
}
