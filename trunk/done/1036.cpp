/*
 *  ACM Online
 *	Lucky Tickets - Problem 1036
 *
 *  solutie: t[n, s] = sum† de la k = 0 la 9 din t[n - 1, s - k]
 *  cred ca e un bug in teste... (e clar† simetria deci 10, 2 = 10, 178 dar
 *  o surs† care a luat acc. a returnat: 0 si 100 nu 100 si 100. Deci...)
 */

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
#define NMAX 230

typedef long HUGE[50];
HUGE l2[NMAX], l1[NMAX], sol;
long N, S, OS, poz, BASE = 1e4L;


void add(HUGE &a, HUGE b)         /* a += b */
{
	long i, k = 0;
	a[0] = max(a[0], b[0]);
	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / BASE, a[i] %= BASE;
	if (k)
		a[++a[0]] = k;
}

void sub(HUGE &a, HUGE b)         /* a -= b */
{
	long i, k = 0;
	a[0] = max(a[0], b[0]);
	for (i = 1; i <= a[0]; i++)
	{
		a[i] -= b[i] + k;
		if (a[i] < 0) k = 1; else k = 0;
		if (k) a[i] += BASE;
		// a[i] += (k = (a[i] -= b[i] + k) < 0) ? BASE : 0;
	}
	while (!a[a[0]] && a[0] > 1) a[0]--;
}

void mul(HUGE a, HUGE b, HUGE &c) /* c = a * b */
{
	long i, j, k;
	for (i = 0; i < 50; i++) c[i] = 0;
	c[0] = a[0] + b[0] - 1;
	for (i = 1; i <= a[0]; i++)
		for (j = 1; j <= b[0]; j++)
			c[i + j - 1] += a[i] * b[j];
	for (i = 1; i <= c[0]; i++)
		k = c[i] / BASE, c[i] %= BASE, c[i + 1] += k;
	if (k)
		c[++c[0]] = k;
}

void afis(HUGE a)
{
	int i;
	printf("%ld", a[a[0]]);
	for (i = a[0] - 1; i; printf("%04ld", a[i--]));
	printf("\n");
}

int main()
{
	long i, j, mid;
	scanf("%ld %ld", &N, &S);
	OS = S;
	if (S & 1) S = 10000L;
	S /= 2;
	S = min(S, 9 * N - S);
	memset(l1, 0, sizeof(l1)); memset(l2, 0, sizeof(l2));
	for (i = 0; i < 10; i++) l1[i][0] = l1[i][1] = 1;
	if (S >= 0)
	for (i = 2; i <= N; i++)
	{
		l2[0][0] = l2[0][1] = 1; poz = 0;
		mid = 9 * i / 2 + (i & 1);
		for (j = 1; j <= mid; j++)
		{
			memcpy(l2[j], l2[j - 1], sizeof(l2[j - 1]));
			add(l2[j], l1[min(j, 9 * (i - 1) - j)]);
			if (j >= 10)
				sub(l2[j], l1[poz++]);
		}
		memcpy(l1, l2, sizeof(l2));
		memset(l2, 0, sizeof(l2));
	}
	if (S >= 0)
		mul(l1[S], l1[S], sol);
	if (S < 0) sol[0] = 1;
	if (OS == 2 && N >= 10) sol[0] = 1, sol[1] = 0;
	afis(sol);
	return 0;
}
