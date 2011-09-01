/*
 *  ACM Timus Online
 *  LaraKiller - Problem 1364
 */

#include <stdio.h>

#define input "file.in"
#define MAXN	128

int M, N, T;
int A[MAXN][MAXN];
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int Q[MAXN * MAXN][2];


void Readdata()
{
	int l, c;

	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d %d", &M, &N);
	scanf("%d %d", &l, &c); // Lara
	A[l][c] = 3;
	scanf("%d %d", &l, &c); // Treasure
	A[l][c] = 2;
	scanf("%d", &T);
}

int inside(int l, int c)
{
	return (l > 0 && l <= M && c > 0 && c <= N);
}


void Solve()
{
	int l, c, dir = 0, nl, nc, lev = 0;

	l = c = 1;
	for (; A[l][c] != 3; ) // break if treasure
	{
		if (A[l][c] == 2)
			T -= lev;
		Q[lev][0] = l;
		Q[lev++][1] = c;
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
		if (A[l][c] == 3)
			Q[lev][0] = l, Q[lev++][1] = c;
	}
	T += lev;

	for (l = T; l > 0; l--)
		printf("%d %d\n", Q[lev - l][0], Q[lev - l][1]);
}

int main()
{
	Readdata();
	Solve();

	return 0;
}
