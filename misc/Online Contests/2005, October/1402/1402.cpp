/*
 *  ACM Timus - Cocktails
 */


#include <stdio.h>
#include <string.h>

int N;
int A[64], B[64];



void add(int a[], int b[])
{
	int i, k = 0;


	if (b[0] > a[0])
		a[0] = b[0];

	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / 10, a[i] %= 10;

	if (k)
		a[++a[0]] = k;
}

void imul(int a[], int x)
{
	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / 10, a[i] %= 10;

	while (k)
		a[++a[0]] = k % 10, k /= 10;
}

int main()
{
	scanf("%d", &N);

	int i, j;


	A[0] = 1;
	A[1] = 0;
	for (i = 2; i <= N; i++)
	{
		memset(B, 0, sizeof(B));
		B[0] = B[1] = 1;
		for (j = N - i + 1; j <= N; j++)
			imul(B, j);
		add(A, B);
	}

	for (i = A[0]; i > 0; i--)
		printf("%d", A[i]);
	printf("\n");


	return 0;
}
