/*
 *  ACM Timus Online
 *  One-two, One-two  - Problem 1407
 */

#include <stdio.h>

#define BASE	10

int N;
int S[128], C[128], P5[128];


void imul(int a[], int x)
{
	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / BASE, a[i] %= BASE;

	while (k)
		a[++a[0]] = k % BASE, k /= BASE;
}

void add(int a[], int b[])
{
	if (a[0] < b[0])
		a[0] = b[0];

	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / BASE, a[i] %= BASE;
	if (k)
		a[++a[0]] = k;
}

int idiv(int a[], int x)
{
	int i, r = 0;

	for (i = a[0]; i > 0; i--)
	{
		r = r * BASE + a[i];
		a[i] = r / x;
		r %= x;
	}

	while (!a[a[0]] && a[0] > 1) a[0]--;

	return r;
}

void Pow(int a[], int b, int k)
{
	int i;

	a[0] = a[1] = 1;

	for (i = 1; i <= k; i++)
		imul(a, b);
}


int main()
{
	scanf("%d", &N);

	int i;
	S[0] = 1;
	S[1] = 2;
	P5[0] = P5[1] = 1;
	C[0] = C[1] = 1;

	for (i = 2; i <= N; i++)
	{
		imul(P5, 5);
		if (C[1] & 1) // C impar
		{
			S[++S[0]] = 1;			
			add(C, P5);
			idiv(C, 2);
		} else // C par
		{
			S[++S[0]] = 2;
			idiv(C, 2);
			add(C, P5);
		}
	}

	for (i = S[0]; i > 0; i--)
		printf("%d", S[i]);
	printf("\n");


	return 0;
}
