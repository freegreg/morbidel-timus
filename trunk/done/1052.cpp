// ACM Online
// Rabbit Hunt - Problem 1052

// maxim de puncte colineare -> N^3 super banal...

#include <stdio.h>

int n;
struct point
{
	int x, y;
} p[200];


void readdata()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
}

void solve()
{
	int i, j, k, aa, bb, cc, maxp = 0, maxc;
	for (i = 0; i < n; i++)         // P1
		for (j = i + 1; j < n; j++)     // P2
		{
			maxc = 2; // capetele
			aa = p[i].y - p[j].y; bb = p[j].x - p[i].x;
			cc = p[i].x * p[j].y - p[j].x * p[i].y;
			for (k = 0; k < n; k++)
				if (k != i && k != j && aa * p[k].x + bb * p[k].y + cc == 0)
					maxc++;
			if (maxc > maxp) maxp = maxc;
		}
	printf("%d", maxp);
}

void main()
{
	readdata();
	solve();
}