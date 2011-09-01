/*
 *  ACM Timus Online
 *  Ministry - Problem 1029
 *
 *  solutie: dinamica aia dubla... (tinem doar ultimele 2 linii)
 */

#include <stdio.h>
#include <string.h>

#define MAXN 1010
#define MAXM 210
#define min(a, b) ((a) > (b) ? (b) : (a))

long d1[MAXN], d2[MAXN], a[MAXN];
char p[MAXM][MAXN]; /*  3 -> sus, 1 -> stanga, 2 -> dreapta  */
int n, m, road[50100];


int main()
{
	long i, j, t1, t2, t3;
	
	scanf("%d %d", &m, &n);
	for (i = 1; i <= m; i++)
	{
		memcpy(d1, d2, sizeof(d2));
		for (j = 1; j <= n; j++)
		{
			scanf("%ld", &a[j]);
			if (i == 1) d2[j] = a[j];
		}
	
		if (i == 1) continue;
		/*  left -> right  */
		for (j = 1; j <= n; j++)
		{
			t1 = a[j] + d1[j]; /*  sus */
			t2 = (j == 1) ? 1e9L : a[j] + d2[j - 1]; /*  stanga */
			d2[j] = min(t1, t2);
			p[i][j] = (t1 > t2) ? 1 : 3;
		}
		/*  right -> left  */
		for (j = n; j; j--)
		{
			t1 = a[j] + d1[j]; /*  sus */
			t2 = (j == n) ? 1e9L : a[j] + d2[j + 1]; /*  dreapta */
			t3 = min(t1, t2);
			if (t3 < d2[j]) 
				p[i][j] = (t1 > t2) ? 2 : 3, d2[j] = t3;
		}
	}
	for (t1 = d2[1], t2 = 1, i = 2; i <= n; i++)
		if (d2[i] < t1)
			t1 = d2[i], t2 = i;

	road[++road[0]] = t2; t1 = m;
	do
	{
		if (t1 == 1) break;
		switch (p[t1][t2])
		{
			case 1: t2--; break;
			case 2: t2++; break;
			case 3: t1--; break;
		}
		road[++road[0]] = t2;
	}
	while (1);

	for (i = road[0]; i; i--)
		printf("%ld\n", road[i]);

	return 0;
}
