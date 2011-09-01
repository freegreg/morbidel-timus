/*
 *  ACM Timus Online
 *  Ministry - Problem 1029
 *
 *  solutie: dinamica aia dubla...
 */

#include <stdio.h>
#include <string.h>

#define input "mini.in"
#define output "mini.out"
#define MAXN 510
#define MAXM 110
#define MMOVES 25100
#define min(a, b) ((a) > (b) ? (b) : (a))

FILE *f;
long d1[MAXN], d2[MAXN], a[MAXN];
int n, m;
char p[MAXM][MAXN]; /*  3 -> sus, 1 -> stanga, 2 -> dreapta  */
int road[MMOVES];

void solve()
{
	long i, j, t1, t2, t3;
	
	f = fopen(input, "r");
	fscanf(f, "%d %d", &m, &n);
	for (i = 1; i <= m; i++)
	{
		memcpy(d1, d2, sizeof(d2));
		for (j = 1; j <= n; j++)
		{
			fscanf(f, "%ld", &a[j]);
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
	fclose(f);
	for (t1 = d2[1], t2 = 1, i = 2; i <= n; i++)
		if (d2[i] < t1)
			t1 = d2[i], t2 = i;

	printf("cost = %ld\n", t1);
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

	f = fopen(output, "w");
	for (i = road[0]; i; i--)
		fprintf(f, "%ld\n", road[i]);
	fclose(f);
}

int main()
{
	solve();
	return 0;
}
