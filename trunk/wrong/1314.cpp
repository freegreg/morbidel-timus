/*
 *  ACM Timus Contest, 13 Aprilie 2004
 *  Problem H - Chase in a Subway
 */

#include <stdio.h>

#define MAXN 3000


int N, Last;
int Flag[MAXN], Id[MAXN], Q[MAXN];
char A[MAXN][101], Flag2[40000];


int get(int id)
{
	int i;

	for (i = 1; i <= Id[0]; i++)
		if (Id[i] == id) return i;

	Id[++Id[0]] = id;
	return Id[0];
}

void readdata()
{
	int i, k, nod, old, n1, n2;

	//freopen("file.in", "r", stdin);
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &k, &old);
		for (k--; k--; )
		{
			scanf("%d", &nod);
			n1 = get(nod); n2 = get(old);
			A[n1][++A[n1][0]] = n2;
			A[n2][++A[n2][0]] = n1;
			old = nod;
		}
	}
	scanf("%d", &k);
	for (; k--; )
		scanf("%d", &nod), Flag[Last = get(nod)] = 1;
}

void solve()
{
	int i, lev, lmax, nod;

	for (Q[lev = 0] = Last, lmax = 1; lev < lmax; lev++)
		for (nod = Q[lev], i = 1; i <= A[nod][0]; i++)
			if (!Flag[A[nod][i]])
				Flag[A[nod][i]] = 2, Q[lmax++] = A[nod][i];

	Flag[Last] = 2;
	for (i = 1; i <= Id[0]; i++)
		if (Flag[i] == 2)
			Flag2[Id[i]] = 1;
	for (i = 1; i <= 35000; i++)
		if (Flag2[i])
			printf("%d\n", i);
}

int main()
{
	readdata();
	solve();

	return 0;
}
