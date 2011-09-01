/*
 *  ACM Timus Online
 *  Topological Sort -> Problem 1280
 *
 *  solutie: banal, retinem pozitiile elementelor si apoi verificam daca corespunde ordinii...
 */

#include <stdio.h>

#define NODS 1001

int n, m, poz[NODS];
struct edge
{
	short n1, n2;
} e[100001];


int main()
{
	int i, ok;

	scanf("%d %d", &n,  &m);

	for (i = 0; i < m; i++)
		scanf("%d %d", &e[i].n1, &e[i].n2);

	for (i = 0; i < n; i++)
		scanf("%d", &ok), poz[ok] = i;


	for (ok = i = 0; i < m; i++)
		if (poz[e[i].n1] > poz[e[i].n2]) 
			ok = 1, i = m;

	printf("%s\n", ok ? "NO" : "YES");

	return 0;
}
