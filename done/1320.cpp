/*
 *  ACM Timus Contest, 15 Aprilie 2004
 *  Problem D - Graph decomposition
 *
 *  solutie: verific daca componentele conexe au nr. de muchii par. Multimi disjuncte.
 */

#include <stdio.h>

#define MAXN 1001

int Tata[MAXN], Rang[MAXN], Gr[MAXN];


int find(int x)
{
	if (x != Tata[x]) 
		Tata[x] = find(Tata[x]);
	return Tata[x];
}

void join(int x, int y)
{
	if (Rang[x] > Rang[y]) 
		Tata[y] = x;
	else
	{
		Tata[x] = y;
		if (Rang[x] == Rang[y])
			Rang[y]++;
	}
}

int main()
{
	int i, a, b, ga, gb;


	for (i = 0; i < MAXN; i++)
		Rang[i] = 0, Tata[i] = i;

	while (scanf("%d %d", &a, &b) == 2)
	{
		Gr[a]++; Gr[b]++;
		ga = find(a); gb = find(b);

		if (ga != gb)
			join(ga, gb);
	}

	for (i = 1; i < MAXN; i++)
		a = find(i), Rang[i] = 0;

	for (i = 1; i < MAXN; i++)
		Rang[Tata[i]] += Gr[i];

	for (i = 0; i < MAXN; i++)
		if (Rang[i] % 4)
		{
			printf("0\n");
			return 0;
		}

	printf("1\n");

	return 0;
}
