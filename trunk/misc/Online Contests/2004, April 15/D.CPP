/*
 *  ACM Timus Contest, 15 Aprilie 2004
 *  Problem D - Graph decomposition
 */

#include <stdio.h>
#include <stdlib.h>


#define input "file.in"
#define MAXN 1001

int Id[MAXN], Flag[MAXN];
struct graf
{
	int nod;
	graf *next;
} *A[MAXN];



void edge(int n1, int n2)
{
	graf *p;

	p = (graf*) malloc(sizeof(*p));
	p -> nod = n2; p -> next = A[n1]; A[n1] = p;
}

int getid(int x)
{
	int i;

	for (i = 1; i <= Id[0]; i++)
		if (Id[i] == x) return i;

	Id[++Id[0]] = x;
	return Id[0];
}

void readdata()
{
	int i, j, id1, id2;

	//freopen(input, "r", stdin);
	while (scanf("%d %d", &i, &j) == 2)
	{
		id1 = getid(i); id2 = getid(j);
		edge(id1, id2); edge(id2, id1);
	}
}

void df(int nod)
{
	graf *p;

	Flag[nod] = 1;
	for (p = A[nod]; p; p = p -> next)
		if (!Flag[p -> nod])
			df(p -> nod);
}

void solve()
{
	int i;

	df(1);

	for (i = 1; i <= Id[0]; i++)
		if (!Flag[i])
		{
			printf("0\n");
			return;
		}
	printf("1\n");
}

int main()
{
	readdata();
	solve();

	return 0;
}
