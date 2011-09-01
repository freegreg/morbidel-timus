/*
 *  ACM Timus Online
 *  Stars - Problem 1028
 *
 *  solutie: retinem doar X-ii si apoi, pt fiecare tre' sa vedem cate sunt <= in stanga. Facem un 
 *  O(sqrtN) cu smenul lui Batog (cred ca se putea si logN...)
 */

#include <stdio.h>
#include <math.h>

#define MAXN 32100L

int N, M = 0, Glen, V[MAXN], Gr[MAXN], Pr[MAXN], Flag[MAXN];


void readdata()
{
	int i, pp;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &V[i], &pp);
		if (V[i] > M)
			M = V[i];
	}
}

void baga_mare(int a, int b)
{
	int i, g1, g2;

	g1 = (a + Glen) / Glen;
	g2 = (b + Glen) / Glen;

	if (g1 == g2)
		for (i = a; i <= b; i++)
			Pr[i]++;
	else
	{
		for (i = a; i <= g1 * Glen - 1; i++)
			Pr[i]++;
		for (i = g1 + 1; i < g2; i++)
			Gr[i]++;
		for (i = (g2 - 1) * Glen; i <= b; i++)
			Pr[i]++;
	}
}

int how(int nod)
{
	int g = (nod + Glen) / Glen;

	return Gr[g] + Pr[nod];
}

void solve()
{
	int i;
	
	Glen = sqrtl(++M);

	for (i = 1; i <= N; i++)
		baga_mare(V[i], M - 1), Flag[how(V[i]) - 1]++;

	for (i = 0; i < N; i++)
		printf("%d\n", Flag[i]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
