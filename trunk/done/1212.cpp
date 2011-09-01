/*
 *  ACM Timus Online
 *  Sea battle - Problem 1212
 */

#include <stdio.h>
#include <stdlib.h>

int M, N, V, K, Ni;
__int64 Sol = 0;
struct ship
{
	int l, c, len, dir;
} S[100];
struct set
{
	int l, r;
} T[1000];



void readdata()
{
	int i, nv = 0, l, c, len;
	char dir;


	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	scanf("%d %d %d", &N, &M, &V);
	for (i = 0; i < V; i++)
	{
		scanf("%d %d %d %c\n", &c, &l, &len, &dir);

		if (dir == 'V')
		{
			S[nv].l = l - 1; S[nv].c = c - 1; S[nv].len = len + 2; S[nv++].dir = 1;
			S[nv].l = l - 1; S[nv].c = c; S[nv].len = len + 2; S[nv++].dir = 1;
			S[nv].l = l - 1; S[nv].c = c + 1; S[nv].len = len + 2; S[nv++].dir = 1;
		} else
		{
			S[nv].l = l - 1; S[nv].c = c - 1; S[nv].len = len + 2; S[nv++].dir = 0;
			S[nv].l = l; S[nv].c = c - 1; S[nv].len = len + 2; S[nv++].dir = 0;
			S[nv].l = l + 1; S[nv].c = c - 1; S[nv].len = len + 2; S[nv++].dir = 0;
		}
	}
	V = nv;
	scanf("%d", &K);
}

void addSegment(int l, int r)
{
	int i;

	for (i = Ni - 1; i >= 0; i--)
		if (l >= T[i].l && l <= T[i].r && r >= T[i].r)/*  tl l tr r  */
			T[i].r = l - 1;
		else
		if (l >= T[i].l && l <= T[i].r && r < T[i].r) /*  tl l r tr  */
			T[Ni].l = r + 1, T[Ni++].r = T[i].r, T[i].r = l - 1;
		else
		if (r >= T[i].l && r <= T[i].r && l < T[i].l) /*  l tl r tr  */
			T[i].l = r + 1;
		else
		if (l < T[i].l && r > T[i].r) /*  l tl tr r  */
			T[i].l = 0, T[i].r = -1;
}

void solve()
{
	int i, j, how;

	/*  pe orizontala  */
	for (i = 1; i <= N; i++)
	{
		Ni = T[0].l = 1; T[0].r = M;

		for (j = 0; j < V; j++)
		{
			if (S[j].dir == 0 && S[j].l == i)
				addSegment(S[j].c, S[j].c + S[j].len - 1);
			if (S[j].dir == 1 && S[j].l <= i && S[j].l + S[j].len - 1 >= i)
				addSegment(S[j].c, S[j].c);
		}

		for (j = 0; j < Ni; j++)
		{
			if (T[j].l > T[j].r) continue;
			how = (T[j].r - T[j].l + 1) - K + 1;
			if (how > 0)
				Sol += (__int64)how;
		}
	}

	/*  pe verticala  */
	if (K != 1)
	for (i = 1; i <= M; i++)
	{
		Ni = T[0].l = 1; T[0].r = N;

		for (j = 0; j < V; j++)
		{
			if (S[j].dir == 1 && S[j].c == i)
				addSegment(S[j].l, S[j].l + S[j].len - 1);
			if (S[j].dir == 0 && S[j].c <= i && S[j].c + S[j].len - 1 >= i)
				addSegment(S[j].l, S[j].l);
		}

		for (j = 0; j < Ni; j++)
		{
			if (T[j].l > T[j].r) continue;
			how = (T[j].r - T[j].l + 1) - K + 1;
			if (how > 0)
				Sol += (__int64)how;
		}
	}

	printf("%I64d\n", Sol);
}

int main()
{
	readdata();
	solve();
	return 0;
}
