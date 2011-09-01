/*
 *  ACM Timus Online
 *  The galactic story - Problem 1329
 *
 *  solutie: DF apoi aia cu intervalele
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define input "file.in"
#define NODS 40010

long N, NQ, Root, Level = 0;
long Fii[NODS], Grad[NODS], Pos[NODS], Tata[NODS], Start[NODS], Stop[NODS];



void readdata()
{
	long i, n1, n2;

#ifndef ONLINE_JUDGE
	freopen(input, "rt", stdin);
#endif

	scanf("%ld", &N);
    for (i = 0; i < N; i++)
    {
    	scanf("%ld %ld", &n1, &n2); // n2 tata lui n1
		n1++; n2++;

		if (n2 != 0)
			Grad[n2]++, Tata[n1] = n2;
		else
			Root = n1;
    }
}

void Df(int nod)
{
	int i, son;

	Start[nod] = Level++;

	for (i = 0; i < Grad[nod]; i++)
	{
		son = Fii[Pos[nod] + i];
		Df(son);
	}
	Stop[nod] = Level++;
}

void solve()
{
	long i, n1, n2, res;

	Pos[0] = Grad[0];
	for (i = 1; i < NODS; i++)
		Pos[i] = Pos[i - 1] + Grad[i - 1];

	for (i = 0; i < NODS; i++)
		if (Tata[i])
			Fii[Pos[Tata[i]] + Start[Tata[i]]++] = i;

	Df(Root);

	scanf("%ld", &NQ);
    for (i = 0; i < NQ; i++)
    {
    	scanf("%ld %ld", &n1, &n2);
		n1++; n2++;

		res = 0;
		if (Start[n1] <= Start[n2] && Stop[n2] <= Stop[n1])
			res = 1;
		else
		if (Start[n2] <= Start[n1] && Stop[n1] <= Stop[n2])
			res = 2;

		printf("%ld\n", res);
    }
}

int main()
{
	readdata();
	solve();

    return 0;
}
