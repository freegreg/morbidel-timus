/*
 *  ACM Timus Contest, 15 Aprilie 2004
 *  Problem I - Dirt
 *
 *  solutie: Dijkstra (max 8 neighbours for edge)
 */

#include <stdio.h>
#include <stdlib.h>


#define MAXN 100

int N, DN, DM, SL, SC, FL, FC, Sn, Dn;
char Map[501][501];
int Flag[MAXN], D[MAXN], T[MAXN];
struct node
{
	long id, c;
	node *next;
} *A[MAXN];



void readdata()
{
	int i;

	freopen("file.in", "r", stdin);
	scanf("%d %d %d %d %d %d", &DM, &DN, &SL, &SC, &FL, &FC);
	for (i = 1; i <= DM; i++)
			scanf("%s", Map[i] + 1);
}

long getnode(int l, int c)
{
	return (l - 1) * DN + c;
}

int good(int l, int c)
{
	return (l > 0 && l <= DM && c > 0 && c <= DN && Map[l][c] != '0');
}

void edge(long i, long j, long c)
{
	node *p;

	p = (node*) malloc(sizeof(*p));
	p -> id = j; p -> c = c;
	p -> next = A[i]; A[i] = p;
}

void solve()
{
	int i, j, minj, l1, l2, c;

	Sn = getnode(SL, SC); Dn = getnode(FL, FC);

	N = DM * DN;

	/*  get edges from matrix and build graph  */
	for (i = 1; i <= DM; i++)
		for (j = 1; j <= DN; j++)
			if (Map[i][j] != '0')
				for (l1 = -1; l1 <= 1; l1++)
					for (l2 = -1; l2 <= 1; l2++)
					{
						if ((!l1 && !l2) || !good(i + l1, j + l2)) continue;

						c = (Map[i][j] != Map[i + l1][j + l2]);
						edge(getnode(i, j), getnode(i + l1, j + l2), c);
						edge(getnode(i + l1, j + l2), getnode(i, j), c);
					}

	for (i = 0; i <= N; i++)
		D[i] = 1000000000L;

	for (i = 1; i <= N; i++)
	{

	}
}

int main()
{
	readdata();
	solve();

	return 0;
}
