/*
 * ACM Timus Online
 * Problem 1860 - Fiborial
 *
 * solutie: F[n] poate fi scris ca n^F[0] * (n-1)^F[1]... = produs(i=0..n-2) din (n-i)^F[i] unde F[i] este al i-lea nr Fibonacci
 *			Factorizez toate numerele de la 2 la n si inmultesc exponentii numerelor prime cu F[i], totul modulo M
 */

#include <cstdio>
#include <vector>

#define MAXN		1000001
#define MOD			1000000007

int N;
long long F0, F1, F2;
std::vector<int> Primes;
bool Ciur[MAXN];
long long Primi[MAXN];

int main()
{
	int i, j;

	for (i = 2; i < MAXN; i++)
		for (j = 2; i * j < MAXN; j++)
			Ciur[i * j] = true;
	for (i = 2; i < MAXN; i++)
		if (!Ciur[i])
			Primes.push_back(i);

	scanf("%d", &N);
	if (N == 1)
	{
		printf("1\n");
		return 0;
	}

	F0 = 1;
	F1 = 1;

	for (i = N; i >= 2; i--)
	{
		int n = i;

		if (i == N || i == N - 1)
			F2 = 1;
		else
			F2 = F0 + F1;
		F2 %= MOD;
		
		// decompun pe n in factori primi
		for (j = 0; j < Primes.size(); j++)
		{
			int exp = 0;
			if (!Ciur[n])
			{
				// daca n e prim, nu-l mai caut in vector, grabesc terminarea
				Primi[n] += F2;
				Primi[n] %= MOD;
				break;
			}
			while (n % Primes[j] == 0)
			{
				n /= Primes[j];
				exp++;
			}

			// ridic exponentii la puterea F2
			Primi[Primes[j]] += (long long)exp * F2;
			Primi[Primes[j]] %= MOD;
		}

		F0 = F1;
		F1 = F2;
	}

	long long sol = 1;
	for (i = 2; i <= N; i++)
	{
		sol *= (long long)Primi[i] + 1;
		sol %= MOD;
	}

	printf("%lld\n", sol);

	return 0;
}