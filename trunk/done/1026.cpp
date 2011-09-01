// ACM Online
// Questions and answers - Problem 1026

#include <stdio.h>

long n, hn, q[100];
int k, v[100000L];

void readdata()
{
	long i;
	char c[10];
	scanf("%ld", &n);
	for (i = 0; i < n; scanf("%d", &v[i++]));
	scanf("%s %d", &c, &k);
	for (i = 0; i < k; scanf("%ld", &q[i++]));
}

void sift(long pos)
{
	long minpos = pos, son;
	do
	{
		son = 2 * pos + 1;
		if (son < hn && v[minpos] < v[son]) minpos = son;
		son = 2 * pos + 2;
		if (son < hn && v[minpos] < v[son]) minpos = son;
		if (pos == minpos) break;
		son = v[pos]; v[pos] = v[minpos]; v[minpos] = son;
		pos = minpos;
	}
	while (1);
}

void heapsort()
{
	long i;
	for (i = hn / 2; i >= 0; sift(i--));
	while (hn > 1)
	{
		i = v[0]; v[0] = v[hn - 1]; v[hn - 1] = i;
		hn--; sift(0);
	}
}

void solve()
{
	int i;
	hn = n;
	heapsort();
	for (i = 0; i < k; i++)
		printf("%d\n", v[q[i] - 1]);
}

void main()
{
	readdata();
	solve();
}