// ACM Online
// History Exam - Problem 1196

#include <stdio.h>

long prof[15000], how = 0, m, n;

int find(long l, long r, long what)
{
	long mid = (l + r) / 2;
	if (what == prof[mid]) return 1; else
	if (l >= r) return 0; else
	if (what > prof[mid]) return find(mid + 1, r, what);
	else return find(l, mid - 1, what);
}

void main()
{
	long i, j;
	scanf("%ld", &n);
	for (i = 1; i <= n; scanf("%ld", &prof[i++]));
	scanf("%ld", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%ld", &j);
		if (find(1, n, j)) how++;
	}
	printf("%ld", how);
}