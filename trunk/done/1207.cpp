// ACM Online
// Problem 1207 - Median

#include <stdio.h>
#include <math.h>

int hn, n, minp, index[20000], hx, hy;
float panta[20000];
long minx, miny;
struct point
{
	long x, y;
} p[20000];


void readdata()
{
	minx = miny = 1000000000.;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%ld %ld", &p[i].x, &p[i].y);
		if (p[i].y < miny || p[i].y == miny && p[i].x < minx)
			minp = i, minx = p[i].x, miny = p[i].y;
	}
}

float tg(int ii)
{
	float alfa;
	if (p[ii].x == minx) alfa = 0; else
	if (p[ii].y == miny) alfa = 1000000000.; else
		alfa = (float)(p[ii].x - minx) / (p[ii].y - miny);
	return alfa;
}

void flip (int ii, int jj)
{
	long aux;
	float pp;

	aux = p[ii].x; p[ii].x = p[jj].x; p[jj].x = aux;
	aux = p[ii].y; p[ii].y = p[jj].y; p[jj].y = aux;
	aux = index[ii]; index[ii] = index[jj]; index[jj] = aux;
	pp = panta[ii]; panta[ii] = panta[jj]; panta[jj] = pp;
}

void sift(int pos)
{
	int minpos = pos, son;

	do
	{
		son = 2 * pos + 1;
		if (son < hn && panta[son] < panta[minpos]) minpos = son;
		son = 2 * pos + 2;
		if (son < hn && panta[son] < panta[minpos]) minpos = son;
		if (pos == minpos) break;
		flip(pos, minpos);
		pos = minpos;
	}
	while (1);
}

void heapsort()
{
	for (int i = hn / 2; i >= 0; sift(i--));
	while (hn)
	{
		flip(0, hn-- - 1);
		sift(0);
	}
}

void solve()
{
	int i;

	for (i = 0; i < n; i++)
		panta[i] = tg(i), index[i] = i;
	flip(minp, n - 1);
	hn = n - 1;
	heapsort();

	printf("%d %d\n", minp + 1, index[n / 2 - 1] + 1);
}

int main()
{
	readdata();
	solve();
	return 0;
}
