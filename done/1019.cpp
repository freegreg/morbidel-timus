/*
 *  ACM Online
 *  A Line Painting - Problem 1019
 *
 *  solutie: sunt 10000 repere asa cå le punem pe un vector si în O(N^2) e usor... (parcurg lista din nou)
 */

#include <stdio.h>
#include <stdlib.h>

struct set
{
	char c;
	long l1, l2;
} s[5010];
long n, v[11000], col[11000], len, lmax = 0, m1, m2, i1, i2;


void readdata()
{
	int i, j;
	char ch;

	scanf("%ld", &n);
	s[0].l1 = v[0] = 0; s[0].l2 = 1e9L; s[0].c = 0;
	v[++v[0]] = 0; v[++v[0]] = 1e9L;
	for (n++, i = 1; i < n; i++)
	{
		scanf("%ld %ld %c", &s[i].l1, &s[i].l2, &ch);
		s[i].c = (ch == 'b') ? 1 : 0;
		for (ch = 0, j = 1; j <= v[0]; j++)
			if (s[i].l1 == v[j]) ch = 1, j = v[0];
		if (!ch)
			v[++v[0]] = s[i].l1;
		for (ch = 0, j = 1; j <= v[0]; j++)
			if (s[i].l2 == v[j]) ch = 1, j = v[0];
		if (!ch)
			v[++v[0]] = s[i].l2;
	}
}

int cmp(const void *arg1, const void *arg2)
{
   return *((long*)arg1) - *((long*)arg2);
}

int bfind(long x)
{
	long l = 1, r = v[0], m;

	do
	{
		m = (l + r) / 2;
		if (v[m] > x) r = m; else
		if (v[m] < x) l = m + 1; else
		return m;
	}
	while (1);
}

void solve()
{
	int i, j, p1, p2, l1, l2;

	/*  sortåm reperele  */
	i = v[0]; v[0] = 0;
	qsort(v, i + 1, sizeof(v[0]), cmp);
	v[0] = i;

	for (i = 0; i < n; i++)
	{
		p1 = bfind(s[i].l1);
		p2 = bfind(s[i].l2);
		for (j = p1; j < p2; j++)
			col[j] = s[i].c;
	}
	if (!col[1]) 
		len = v[2]  - v[1], m1 = v[1], m2 = v[2];
	for (i = 2; i < v[0]; i++)
		if (col[i])
		{
			if (len > lmax)
				lmax = len, i1 = m1, i2 = m2;
			len = 0;
		} else
		{
			if (col[i - 1]) m1 = v[i];
			m2 = v[i + 1]; len += v[i + 1] - v[i];
		}
	if (len > lmax) 
		lmax = len, i1 = m1, i2 = m2;

	printf("%ld %ld\n", i1, i2);
}

int main()
{
	readdata();
	solve();
	return 0;
}
/*
 *  Sarpe serpeste cu solzi ca de peste, râul serpuieste
 *  Si-n apa pârâului umbra spinåråului, a sarpelui råului...
 */
