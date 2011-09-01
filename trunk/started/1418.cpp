/*
 *  ACM Timus Online
 *  Military - Problem 1418
 */


#include <stdio.h>
#include <math.h>
#include <string.h>

#define NMAX 4096
#define INF  100000

FILE *f;
int on, n, hn, lev[NMAX], flag[NMAX], s[NMAX], a[NMAX];
double t[NMAX], ot[NMAX];
struct point
{
	double x, y;
} p[NMAX];


void readdata()
{
    int i;
	double maxx = -INF;

	freopen("file.in", "rt", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
		if (p[i].y > maxx) maxx = p[i].y;
	}
	for (i = 0; i < n; i++) p[i].y = maxx - p[i].y;
}

double dist(int i, int j)
{
	return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}

int left(int pt, int i, int j, int k)    // i, j, k fac unghi <= 180 la stanga
{
	double d1, d2, d3;
	int ok = (p[j].x - p[i].x) * (p[k].y - p[i].y) >= (p[k].x - p[i].x) * (p[j].y - p[i].y);
	if (t[i] == t[j] && t[j] == t[k])
	{
		d1 = dist(pt, i); d2 = dist(pt, j); d3 = dist(pt, k);
		if (!(d3 < d2 && d2 < d1)) ok = 0;
	}
	return ok;
}

int getmin()
{
	int i, pt;
	double min = INF;
	for (i = 0; i < n; i++)
		if (p[a[i]].x < min) min = p[a[i]].x, pt = a[i]; else
		if (p[a[i]].x == min && p[a[i]].y < p[pt].y) pt = a[i];
	return pt;
}

void calc_panta(int pt)
{
        int i;
	memset(t, 0, sizeof(t));
	for (i = 0; i < n; i++)
		if (a[i] != pt)
			// t[i] = (p[a[i]].y == p[pt].y) ? INF : (p[a[i]].x - p[pt].x) / (double)(p[a[i]].y - p[pt].y);
			t[i] = (p[a[i]].x == p[pt].x) ? INF : (p[a[i]].y - p[pt].y) / (double)(p[a[i]].x - p[pt].x);
		else t[i] = -INF;
}

void sift(int pos)
{
	int minpos = pos, son;
	double aux;
	do
	{
		son = 2 * pos + 1;
		if (son < hn && t[minpos] < t[son]) minpos = son;
		son = 2 * pos + 2;
		if (son < hn && t[minpos] < t[son]) minpos = son;
		if (minpos == pos) break;
		a[minpos] = (a[minpos] ^ a[pos]) ^ (a[pos] = a[minpos]);
		aux = t[minpos]; t[minpos] = t[pos]; t[pos] = aux;
		pos = minpos;
	}
	while (1);
}

void sort_pts()
{
	int i;
	double aux;
	for (i = hn / 2; i >= 0; sift(i--));
	while (hn)
	{
		a[0] = (a[0] ^ a[hn - 1]) ^ (a[hn - 1] = a[0]);
		aux = t[0]; t[0] = t[hn - 1]; t[hn - 1] = aux;
		hn--; sift(0);
	}
	i = i;
	memset(ot, 0, sizeof(ot));
	for (i = 0; i < n; i++) ot[a[i]] = t[i];
	memcpy(t, ot, sizeof(ot));
}

void convex_hull(int pt)       // Graham
{
	int l = 2;
	s[0] = 2; s[1] = a[0]; s[2] = a[1]; a[n] = a[0];
	do
	{
		while (!left(pt, s[s[0] - 1], s[s[0]], a[l++]))
			s[s[0]--] = 0, l--;
		s[++s[0]] = a[l - 1];
	}
	while (l < n);
	s[++s[0]] = s[1];
}

void out()
{
	int i, l = 1, l2 = 0;
	memset(flag, 0, sizeof(flag));
	for (i = 0; i < n; i++)
		if (a[i] == s[l]) l++, a[i] = -1;
	for (i = 0; i < n; i++)
		if (a[i] != -1) flag[l2++] = a[i];
	memcpy(a, flag, sizeof(flag));
	n -= s[0] - 1;
}

void solve()
{
	int i, j, pt;
	on = n;
	for (i = 0; i < n; i++) a[i] = i;
	for (j = 1; n > 2; j++)
	{
		hn = n;
		memset(s, 0, sizeof(s));
		pt = getmin();
		calc_panta(pt);
		sort_pts();
		convex_hull(pt);
		out();
		for (i = 1; i < s[0]; i++) lev[s[i]] = j;
	}
	for (i = 0; i < n; i++) lev[a[i]] = j;
	pt = 0;
	for (i = 0; i < on; i++)
		if (lev[i] > pt)
			pt = lev[i];

	printf("%d\n", pt);
}

int main()
{
	readdata();
	solve();
	return 0;
}
