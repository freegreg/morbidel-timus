// ACM Online
// Cover - problem 1112

// solutie: le sortam dupa coordonata capatului din dreapta apoi e ushor

#include <stdio.h>

#define min(a, b) a > b ? b : a

int n, hn, p = 0, flag[100], l[100], r[100];

void readdata()
{
	int x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		l[i] = min(x, y); r[i] = x + y - l[i];
	}
}

int a;
#define flip(i, j) a = l[i], l[i] = l[j], l[j] = a, a = r[i], r[i] = r[j], r[j] = a;

void sift(int pos)
{
	int son, minpos = pos;
	do
	{
		son = 2 * pos + 1;
		if (son < hn && r[son] > r[minpos]) minpos = son;
		son = 2 * pos + 2;
		if (son < hn && r[son] > r[minpos]) minpos = son;
		if (pos == minpos) return;
		flip(pos, minpos);
		pos = minpos;
	}
	while (1);
}
void heapsort()
{
	for (int i = hn / 2; i >= 0; sift(i--));
	while(hn)
	{
		flip(0, hn - 1); hn--;
		sift(0);
	}
}
void solve()
{
	int i, k;
	hn = n;
	heapsort();
	flag[0] = p = 1;
	k = r[0];
	for (i = 1; i < n; i++)
		if (l[i] >= k)
			flag[i] = 1, k = r[i], p++;
	printf("%d\n", p);
	for (i = 0; i < 100; i++)
		if (flag[i])
			printf("%d %d\n", l[i], r[i]);
}
void main()
{
	readdata();
	solve();
}