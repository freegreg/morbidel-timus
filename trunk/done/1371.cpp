/*
 *  ACM Timus Online
 *  Cargo agency - Problem 1371
 */

#include <stdio.h>
#include <stdlib.h>

#define input "file.in"
#define MAXN 50010

int N, on = 0;
int Fii[MAXN], Flag[MAXN], Q[MAXN], Tata[MAXN];
double Cost;
struct node
{
	int cost, nod;
	node *next;
} *A[MAXN];



void leaga(int n1, int n2, int cost)
{
	node *p;

	p = (node*)malloc(sizeof(*p));
	p->cost = cost;
	p->nod = n2;
	p->next = A[n1];
	A[n1] = p;
}

void Readdata()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%ld", &N);

	int i, n1, n2, c;

	for (i = 1; i <= N - 1; i++)
	{
		scanf("%d %d %d", &n1, &n2, &c);
		leaga(n1, n2, c);
		leaga(n2, n1, c);
	}
}

void Bf(int nod)
{
	node *p;
	int lev, mlev;

	Tata[nod] = 0;
	lev = mlev = 0;
	Q[mlev++] = nod;
	Flag[nod] = 1;

	for (; lev < mlev; nod = Q[++lev])
		for (p = A[nod]; p != NULL; p = p->next)
			if (!Flag[p->nod])
			{
				Tata[p->nod] = nod;
				Q[mlev++] = p->nod;
				Flag[p->nod] = 1;
			};;;
	for (lev = mlev - 1; lev >= 0; lev--)
		Fii[Tata[Q[lev]]] += Fii[Q[lev]];
}

void Solve()
{
	int i;
	node *p;

	for (i = 1; i <= N; i++) 
		Fii[i] = 1, Flag[i] = 0;


	Bf(1);

	Cost = 0;
	for (i = 1; i <= N; i++)
		for (p = A[i]; p != NULL; p = p->next)
			if (Fii[p->nod] < Fii[i])
				Cost += (double)p->cost * (double)Fii[p->nod] * (double)(N - Fii[p->nod]);

	if (N > 1)
	{
		Cost /= (double)N * (double)(N - 1);
		Cost *= 2;
	}

	printf("%.4lf\n", Cost);
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
