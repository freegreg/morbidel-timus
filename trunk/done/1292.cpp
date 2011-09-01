/*
 *  ACM Timus Online
 *  Mars space stations - Problem 1292
 *
 *  solutie: alea cicleaza la maxim 15 elemente deci il generez apoi iau modulo...
 */

#include <stdio.h>

long N, K, L, T, Sol, poz, clen;
long S[100], C[100];


long f(long x)
{
	long sum = 0;

	while (x)
		sum += (x % 10) * (x % 10) * (x % 10), x /= 10;

	return sum;
}

long solve()
{
	int i;

	S[0] = clen = poz = 0;

	S[++S[0]] = K;

	do
	{
		S[S[0] + 1] = f(S[S[0]]);
		S[0]++;
		for (i = 1; i < S[0]; i++)
			if (S[S[0]] == S[i])
				poz = i, i = S[0];
		if (poz) break;
	}
	while (1);

	for (i = poz; i < S[0]; i++)
		C[clen++] = S[i];
	S[0] = poz - 1;

	if (N <= S[0])
		return S[N];

	N -= S[0] + 1;

	return C[N % clen];
}

int main()
{
	scanf("%ld", &T);

	for (; T--; )
	{
		scanf("%ld %ld %ld", &N, &K, &L);
		Sol = solve();
		printf("%ld\n", Sol - L);
	}

	return 0;
}
