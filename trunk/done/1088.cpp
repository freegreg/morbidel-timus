/*
 *  ACM Online
 *  Ilya Murumetz - Problem 1088
 *
 *  solutie: se cere de fapt distanta dintre 2 noduri de pe 2 nivele date
 *  Œntr-un arbore binar strict de ordin F dar e groaznic de incƒlcit textul...
 *  asta e usor, calcul†m tat†l frunzelor apropiate de ele de pe nivelul lor...
 */

#include <stdio.h>

#define tata(x) ((x + 1) / 2)
/*  x e poz lui, y e poz pietrei  */
long mlev, lx, ly, nx, ny, h, d = 0, nodx, nody;
long lcl, tx[50], ty[50];


int main()
{
	long i;
	scanf("%ld %ld %ld %ld %ld %ld", &ly, &lx, &mlev, &ny, &nx, &h);
	lx = mlev - lx; ly = mlev - ly;

	for (nodx = nx, i = mlev; i > lx; i--)
		nodx = tata(nodx);
	for (nody = ny, i = mlev; i > ly; i--)
		nody = tata(nody);

	/*  cel mai mic nivel comun  */
	tx[lx] = nodx; ty[ly] = nody;
	for (nx = nodx, i = lx - 1; i >= 0; i--)
		tx[i] = (nx = tata(nx));
	for (ny = nody, i = ly - 1; i >= 0; i--)
		ty[i] = (ny = tata(ny));
	for (i = 0; i < lx; i++)
		if (tx[i] != ty[i]) break;
	lcl = i - 1;

	do
	{
		if (nodx == nody && lx == ly) break;
		if (lx > lcl) nodx = tata(nodx), lx--, d++;
		if (ly > lcl) nody = tata(nody), ly--, d++;
	}
	while (1);

	printf("%s\n", d <= h ? "YES" : "NO");

	return 0;
}
