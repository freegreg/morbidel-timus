/*
 *  ACM Timus Online
 *  Heritage - Problem 1108
 *
 *  solutie: x[i] = produs(x[j]) + 1, 1 <= j < i...
 */


typedef __int64 HUGE[7700];

#include <stdio.h>
#include <string.h>

#define base 10000000L

int N;
HUGE Prod, Next, foo;


void add1(HUGE &c)
{
	int i;
	
	c[1]++;
	for (i = 1; i <= c[0]; i++)
		c[i + 1] += c[i] / base, c[i] %= base;
	if (c[c[0] + 1] > 0)
		c[0]++;
}

/*  inmultire de numere mari  */
void mul(HUGE &c, HUGE a, HUGE b)
{
	__int64 i, j, k = 0;

	foo[0] = a[0] + b[0] - 1;
	for (i = 1; i <= foo[0]; foo[i++] = 0);

	for (i = 1; i <= a[0]; i++)
		for (j = 1; j <= b[0]; j++)
			foo[i + j - 1] += a[i] * b[j];

	for (i = 1; i <= foo[0]; i++)
		k = foo[i] / base, foo[i] %= base, foo[i + 1] += k;
	if (k)
		foo[++foo[0]] = k;
	for (i = 0; i <= foo[0]; i++)
		c[i] = foo[i];
	while (!c[c[0]] && c[0] > 1) c[0]--;
}

void afis(HUGE a)
{
	int i;

	printf("%I64d", a[a[0]]);
	for (i = a[0] - 1; i; i--)
		printf("%07I64d", a[i]);
	printf("\n");
}

int main()
{
	int i;

	scanf("%d", &N);
	Prod[0] = 1; Prod[1] = 2;
	printf("2\n");

	for (i = 2; i <= N; i++)
	{
		memcpy(Next, Prod, sizeof(Prod));
		add1(Next);
		afis(Next);
		mul(Prod, Prod, Next);
		add1(Next);
	}

	return 0;
}
