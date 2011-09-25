/*
 * ACM Timus Online Contest - 18 September 2011
 * Problem F - GCD 2010
 */

#include <cstdio>
#include <vector>
#include <map>

#define MAXN		32000

int GCD, N, Ciur[MAXN];
std::vector<int> Large;		// each n is a product of small primes and only one large prime (> 31000)
std::vector<int> P, Flag;
std::map<int, int> M;


void Decompose(int n, int &large, bool first)
{
	int i, j, cnt, prod;


	for (i = 0; i < P.size(); i++)
	{
		if (n == 1)
			break;
		cnt = 0;
		prod = 1;
		while (n % P[i] == 0)
		{
			prod *= P[i];
			n /= P[i];
			cnt++;
		}
		if (first)
		{
			GCD *= prod;
			Flag[P[i]] = cnt;
		}
		else if (cnt < Flag[P[i]])
		{
			for (j = 0; j < Flag[P[i]] - cnt; j++)
				GCD /= P[i];
			Flag[P[i]] = cnt;
		}
	}

	large = n;

	if (first)
		GCD *= large;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int i, j;

	// Ciur
	for (i = 2; i < MAXN; i++)
		for (j = 2; i * j < MAXN; j++)
			Ciur[i * j] = 1;

	for (i = 2; i < MAXN; i++)
		if (Ciur[i] == 0)
			P.push_back(i);


	scanf("%d\n", &N);

	Flag.resize(MAXN, 0);
	Large.resize(N, 0);

	char ch;
	int n;

	GCD = 1;
	for (i = 0; i < N; i++)
	{
		scanf("%c %d\n", &ch, &n);

		if (ch == '+')
		{
			M[n]++;
			Decompose(n, Large[i], i == 0);
		}
		else
		{
			M[n]--;
		}

		printf("%d\n", GCD);

		// bruteforce
		int res = 1, first = 0;
		std::map<int, int>::iterator it;

		for (it = M.begin(); it != M.end(); it++)
		{
			if (it->second > 0)
			{
				if (!first)
				{
					res = it->first;
					first = 1;
				}
				else
				{
					res = gcd(res, it->first);
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}