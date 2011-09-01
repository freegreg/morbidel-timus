/*
 *  ACM Timus Online Contest, 8 November 2003
 *  Problem 7 -> Topological Sort
 */

#include <stdio.h>

#define NODS 2010

int n, m, poz[NODS], s[NODS];
struct edge
{
	int n1, n2;
} e[200100];


int main()
{
	int i, ok;

	scanf("%d %d", &n,  &m);
	for (i = 0; i < m; i++)
		scanf("%d %d", &e[i].n1, &e[i].n2);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]), poz[s[i]] = i;

	for (ok = i = 0; i < m; i++)
	{
		if (poz[e[i].n1] > poz[e[i].n2]) 
		{
			ok = 1; 
			break;
		}
	}
	printf("%s\n", ok ? "NO" : "YES");

	return 0;
}
