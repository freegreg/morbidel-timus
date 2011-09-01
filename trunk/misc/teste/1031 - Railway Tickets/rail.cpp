/*
 *  ACM Timus Online
 *  Railway Tickets - Problem 1031
 *
 */

#include <stdio.h>

#define input "rail.in"
#define output "rail.out"
#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAXN 10100

FILE *f;
long n, s1, s2, l1, l2, l3, c1, c2, c3;
long x[MAXN], d[MAXN];


void readdata()
{
	int i;
	
	f = fopen(input, "r");
	fscanf(f, "%ld %ld %ld %ld %ld %ld %ld %ld %ld", &l1, &l2, &l3, &c1, &c2, &c3, &n, &s1, &s2);
	if (s1 > s2) 
		i = s1, s1 = s2, s2 = i;
	for (i = 2; i <= n; i++)
		fscanf(f, "%ld", &d[i]);
	fclose(f);
}

long dist(int nod1, int nod2)
{
	return (d[nod2] - d[nod1]);
}

/*  scoate statia cea mai din stânga din [l, r] la o distanta maxim lim de node  */
long scoate_mare(long l, long r, long lim, long node)
{
	long m;

	do
	{
		if (l > r) return r;
		m = (l + r) / 2;
		if (dist(m, node) > lim) 
			l = m + 1;
		else 
		if (dist(m, node) <= lim)
		{
			if (dist(m - 1, node) > lim || m == 1) 
				return m;
			r = m - 1;
		}
	}
	while (1);
}

void solve()
{
	long i, p1, p2, p3;

	x[s1] = 0; d[0] = -2e9L;
	for (i = s1 + 1; i <= s2; i++)
	{
		p1 = scoate_mare(s1, i, l1, i);
		if (p1 < s1) p1 = s1;
		p2 = scoate_mare(s1, i, l2, i);
		if (p2 < s1) p2 = s1;
		p3 = scoate_mare(s1, i, l3, i);
		if (p3 < s1) p3 = s1;
		x[i] = 2e9L;
		x[i] = min((__int64)x[p1] + c1, min((__int64)x[p2] + c2, (__int64)x[p3] + c3));
	}
	fprintf(fopen(output, "w"), "%ld\n", x[s2]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
/*
 *  Apar de pe taramul negru cu stilul meu bolnav
 *  Fac sa va cada capetele voastre de scalvi (...)
 *  M-am saturat de voi ca virgula canditi a hoit
 *  Luati de-aici un mare va iubesc concretizat in coit...
 */