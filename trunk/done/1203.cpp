// ACM Online
// Conference, problem 1203

// solutie: le sortam dupa timpul de sfarsit apoi e banal...

#include <stdio.h>

long n, hn, p = 0;
int s[15000], f[15000];

void readdata()
{
	scanf("%ld", &n);
	for (long i = 0; i < n; i++)
		scanf("%d %d", &s[i], &f[i]);
}

int a;
#define flip(i, j) a = s[i], s[i] = s[j], s[j] = a, a = f[i], f[i] = f[j], f[j] = a;

void sift(int pos)
{
	int son, minpos = pos;
	do
	{
		son = 2 * pos + 1;
		if (son < hn && f[son] > f[minpos]) minpos = son;
		son = 2 * pos + 2;
		if (son < hn && f[son] > f[minpos]) minpos = son;
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
	p = 1; k = f[0];
	for (i = 1; i < n; i++)
		if (s[i] > k)
			k = f[i], p++;
	printf("%ld", p);
}
void main()
{
	readdata();
	solve();
}