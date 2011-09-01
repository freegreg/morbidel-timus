/*
 *  ACM Timus Online Contest, 8 November 2003
 *  Problem 9 -> Game tree
 */

#include <stdio.h>
#include <stdlib.h>

#define NODS 10200

int n, a[NODS], b[NODS], gr[NODS], tata[NODS];
struct graf
{
	int nod;
	graf *next;
} *g[NODS];


void readdata()
{
	char ch;
	int i;
	graf *q;

	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		scanf("\n%c %d", &ch, &tata[i]);
		q = (graf*) malloc(sizeof(*q));
		q -> nod = i; q -> next = g[tata[i]]; g[tata[i]] = q;
		if (ch == 'N') gr[tata[i]]++;
		if (ch == 'L') /* frunza  */
			scanf("%d", &a[i]), b[i] = a[i], gr[i] = -1;
	}
}

void solve()
{
	int i, j, ok, nod, next, w1, d1, w2, d2;
	graf *q;

	for (nod = 0, i = 1; i <= n; i++)
		if (!gr[i]) 
			nod = i, i = n;

	for (j = 0; j < n; j++)
	{
		if (gr[nod] < 0 || nod == 10000) break;

		
		/*  avem frunza nod, calculez a[nod] si b[nod]  */
		for (w1 = w2 = d1 = d2 = 0,  q = g[nod]; q; q = q -> next)
		{
			next = q -> nod;
			switch (b[next])
			{
				case 0: d1++; break;
				case 1: w1++; break;
			}
			switch (a[next])
			{
				case 0: d2++; break;
				case -1: w2++; break;
			}
		}
		a[nod] = w1 ? 1 : (d1 ? 0 : -1);
		b[nod] = w2 ? -1 : (d2 ? 0 : 1);

		/*  caut urm. frunza minima  */
		for (next = 10000, i = nod + 1; i <= n; i++)
			if (!gr[i])
				next = i, i = n;
		if (--gr[tata[nod]] == 0 && tata[nod] < next) 
			next = tata[nod];
		gr[nod] = -1; nod = next;
	}
	if (a[1] == 1) printf("+");
	printf("%d\n", a[1]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
