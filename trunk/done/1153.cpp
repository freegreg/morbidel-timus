/*
 *  ACM Online
 *  Supercomputer - Problem 1153
 *
 *  solutie: N = (sqrt(8 * M + 1) - 1) / 2
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef int bignum[1500];

bignum m, n, r, c, oc;



void readdata()
{
	char ch;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	while (scanf("%c", &ch) == 1)
	{
		if (ch < '0' || ch > '9') break;
		m[++m[0]] = ch - '0';
	}
}

void imul(bignum a, long x)
{
	long i, k = 0;
	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / 10, a[i] %= 10;
	while (k) a[++a[0]] = k % 10, k /= 10;
	if (!x) a[0] = 1, a[1] = 0;
}

void imul2(long x)
{
	long i, k = 0;
	c[0] = n[0];
	for (i = 1; i <= c[0]; i++)
		c[i] = n[i] * x + k, k = c[i] / 10, c[i] %= 10;
	while (k) c[++c[0]] = k % 10, k /= 10;
}

int cmp(bignum a, bignum b)    /*  1, 0, -1  */
{
	int i;
	if (a[0] > b[0]) return 1;
	if (a[0] < b[0]) return -1;
	for (i = a[0]; i; i--)
		if (a[i] > b[i]) return 1; else
		if (a[i] < b[i]) return -1;
	return 0;
}

void sub(bignum a, bignum b)
{
	long i, k = 0;
	for (i = 1; i <= a[0]; i++)
		a[i] += (k = (a[i] -= b[i] + k) < 0) ? 10 : 0;
	while (!a[a[0]] && a[0] > 1) a[0]--;
}

void add(bignum a, int cif)
{
	int i, k;
	a[1] += cif;
	for (i = 1; i <= a[0]; i++)
		k = a[i] / 10, a[i + 1] += k, a[i] %= 10;
	if (k) a[++a[0]] = k;
}

void flip(bignum a)
{
	int i, j;
	for (i = 1; i <= a[0] / 2; i++)
		j = a[i], a[i] = a[a[0] - i + 1], a[a[0] - i + 1] = j;
}

void div(bignum a, long x)
{
	long i, r = 0;
	for (i = a[0]; i; i--)
		r = r * 10 + a[i], a[i] = r / 2, r %= 2;
	while (!a[a[0]] && a[0] > 1) a[0]--;

}

void solve()
{
	long i, k;

	//printf("\n");
	flip(m);
	imul(m, 8);
	add(m, 1);

	/*  n = sqrt(m)  */
	if (m[0] & 1)
		r[0] = 1, r[1] = m[m[0]], i = m[0];
	else
		r[0] = 2, r[1] = m[m[0]], r[2] = m[m[0] - 1], i = m[0] - 1;
	n[0] = 1;
	if (r[0] == 1) k = r[1]; else k = 10 * r[1] + r[2];
	n[1] = sqrtl(k);
	flip(r);
	for (k = 0; k < n[1]; k++)
		sub(r, n);
	flip(r);
	for (i--; i; i -= 2)
	{
		imul(r, 10); add(r, m[i]);
		imul(r, 10); add(r, m[i - 1]);
		flip(n); imul2(2); flip(n);
		flip(c); c[0]++;
		memcpy(oc, c, sizeof(c));
		for (k = 0; k < 10; k++)
		{
			c[c[0]] = k;
			flip(c); imul(c, k);
			if (cmp(r, c) == -1) break;
			memcpy(c, oc, sizeof(oc));
		}
		n[++n[0]] = k - 1;
		memcpy(c, oc, sizeof(oc));
		c[c[0]] = k - 1;
		flip(c); imul(c, k - 1);
		sub(r, c);
	}
	flip(n);
	r[0] = r[1] = 1;
	sub(n, r);
	div(n, 2);

	for (i = n[0]; i; i--)
		printf("%d", n[i]);
	printf("\n");
}

int main()
{
	readdata();
	solve();

	return 0;
}
