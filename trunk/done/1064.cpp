/*
 *  ACM Timus Online
 *  Binary Search - Problem 1064
 *
 *  solutie: incerc toate numerele din 1..10000 :)
 *  in pascal merge
 */

#include <stdio.h>

#define MAXN 50001

long N, L, X, NI = 0;
struct Ionela
{
	int n1, n2;
} S[MAXN];


/*  intoarce numarul de comparatii pentru a-l gasi pe x  */
long BS(int x)
{
	int p, q, i, l;

	l = p = 0; q = N - 1;

	while (p <= q) 
	{
		i = (p + q) / 2;
		l++;
		if (i == x)
			return l;
		if (x < i)
			q = i - 1;
		else
			p = i + 1;
	}
	return 0;
}

int main()
{
	scanf("%ld %ld", &X, &L);

	for (N = 1; N <= 10000; N++)
		if (BS(X) == L)
		{
			if (NI && S[NI - 1].n2 == N - 1) /*  il joinam la asta  */
				S[NI - 1].n2 = N;
			else                             /*  creem un interval nou  */
				S[NI].n1 = S[NI++].n2 = N;
		}
	
	printf("%ld\n", NI);
	for (N = 0; N < NI; N++)
		printf("%ld %ld\n", S[N].n1, S[N].n2);

	return 0;
}
