// ACM Online
// Akbardin's Roads - Problem 1178
// asta am facut-o live, adica in concursul online...

#include <stdio.h>

int n, hn;
struct city
{
	int oldn;
	long x, y;
} c[1000];

void readdata()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%ld %ld", &c[i].x, &c[i].y), c[i].oldn = i;
}

void flip(int n1, int n2)
{
	long a;
	a = c[n1].x; c[n1].x = c[n2].x; c[n2].x = a;
	a = c[n1].y; c[n1].y = c[n2].y; c[n2].y = a;
	a = c[n1].oldn; c[n1].oldn = c[n2].oldn; c[n2].oldn = a;
}

void sift(int pos)
{
	int minpos = pos, son;
	do
	{
		son = 2 * pos + 1;
		if (son < hn && (c[son].y > c[minpos].y ||
			c[son].y == c[minpos].y && c[son].x > c[minpos].x))
				minpos = son;
		son = 2 * pos + 2;
		if (son < hn && (c[son].y > c[minpos].y ||
			c[son].y == c[minpos].y && c[son].x > c[minpos].x))
				minpos = son;
		if (pos == minpos) return;
		flip(pos, minpos);
		pos = minpos;
	}
	while (1);
}

void heapsort()
{
	int i;
	for (i = hn / 2; i >= 0; sift(i--));
	while (hn)
	{
		flip(0, hn - 1);
		hn--; sift(0);
	}
}

void solve()
{
	int i;
	hn = n;
	heapsort();
	for (i = 0; i < n; i += 2)
		printf("%d %d\n", c[i].oldn + 1, c[i + 1].oldn + 1);
}

void main()
{
	readdata();
	solve();
}