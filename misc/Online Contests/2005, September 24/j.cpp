/*
 *  J - Roadworks
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN	10001

int N;
long A[MAXN], B[MAXN];
long Tai[MAXN], Move[MAXN];
int Tata[MAXN], Grad[MAXN], Flag[MAXN];
struct lista
{
	int nod;
	lista *next;
} *L[MAXN], *L2[MAXN];



void leaga(int i, int j)
{
	lista *p;

	p = new lista;
	p -> nod = i;
	p -> next = L[j];
	L[j] = p;
}

void leaga2(int i, int j)
{
	lista *p;

	p = new lista;
	p -> nod = j;
	p -> next = L2[i];
	L2[i] = p;
}

void Readdata()
{
	int i, j;

	#ifndef ONLINE_JUDGE
		freopen("file.in", "rt", stdin);
	#endif

	scanf("%d %d", &N, &i);

	long m = 0;
	while (scanf("%d %d", &i, &j) == 2)
	{
		leaga(i, j);
		leaga(j, i);
	}
}

void df(int nod)
{
	lista *p;

	Flag[nod] = 1;

	for (p = L[nod]; p != NULL; p = p -> next)
		if (!Flag[p -> nod])
		{
			leaga2(nod, p -> nod);
			Tata[p -> nod] = nod;
			Grad[nod]++;
			df(p -> nod);
		}
	Flag[nod] = 0;
}

void process(int nod)
{
	lista *p;
	int max = 0, fiu, sum;


	for (p = L2[nod]; p != NULL; p = p -> next)
		if (B[p -> nod] > max)
			max = B[p -> nod], fiu = p -> nod;

	A[nod] = max;
	Move[nod] = fiu;

	// B[i]
	// tai un fiu
	max = 30000; sum = fiu = 0;
	for (p = L2[nod]; p != NULL; sum += B[p -> nod], p = p -> next)
		if (B[p -> nod] < max)
			max = A[p -> nod], fiu = p -> nod;
	if (max == 30000)
		B[nod] = 0;
	else
		B[nod] = max + 1 + sum - B[fiu];
	Tai[nod] = fiu;

	// nu tai nici un fiu
	max = 0;
	for (p = L2[nod]; p != NULL; p = p -> next)
		max += B[p -> nod];
	if (max > B[nod])
		B[nod] = max, Tai[nod] = 0;
}

void Solution(int nod, int mode)
{
	lista *p;


	if (nod < 0 || nod > N) return;
	// mode 0 -> A, mode 1 -> B
	if (mode)
	{
		if (Tai[nod] != 0)
			printf("%d %d\n", nod, Tai[nod]);
		for (p = L2[nod]; p != NULL; p = p -> next)
			if (p -> nod == Tai[nod])
				Solution(p -> nod, 1 - mode);
			else
				Solution(p -> nod, mode);
	} else
		Solution(Move[nod], 1 - mode);
}

void df2(int nod)
{
	lista *p;

	Flag[nod] = 1;

	for (p = L[nod]; p != NULL; p = p -> next)
		if (!Flag[p -> nod])
			df2(p -> nod);

	Flag[nod] = 0;

	process(nod);
}

void Solve()
{
	Tata[1] = 0;
	df(1);

	df2(1);

	printf("%d\n", B[1]);
	Solution(1, 1);
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
