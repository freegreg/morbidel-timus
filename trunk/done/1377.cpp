/*
 *  ACM Timus Online
 *  Lara Croft - Problem 1377
 */

#include <stdio.h>

#define input "file.in"
#define MAXN	128

int M, N, Time;
int A[MAXN][MAXN];
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void Readdata()
{
	int l, c;

	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d %d", &M, &N);
	scanf("%d %d", &l, &c);
	A[l][c] = -1;
	scanf("%d %d", &l, &c);
	A[l][c] = -1;
}

int inside(int l, int c)
{
	return (l > 0 && l <= M && c > 0 && c <= N);
}


void Solve()
{
	int l, c, dir = 0, nl, nc;

	// first treasure
	l = c = 1;
	for (; A[l][c] != -1; )
	{
		A[l][c] = 1;
		nl = l + dirs[dir % 4][0];
		nc = c + dirs[dir % 4][1];

		if (A[nl][nc] == 1 || !inside(nl, nc))
		{
			dir++;
			nl = l + dirs[dir % 4][0];
			nc = c + dirs[dir % 4][1];
		}
		l = nl;
		c = nc;
	}
	A[l][c] = 1;

	// second treasure
	for (Time = 0; A[l][c] != -1; Time++)
	{
		A[l][c] = 1;
		nl = l + dirs[dir % 4][0];
		nc = c + dirs[dir % 4][1];

		if (A[nl][nc] == 1 || !inside(nl, nc))
		{
			dir++;
			nl = l + dirs[dir % 4][0];
			nc = c + dirs[dir % 4][1];
		}
		l = nl;
		c = nc;
	}

	printf("%d\n", Time);
}

int main()
{
	Readdata();
	Solve();

	return 0;
}
