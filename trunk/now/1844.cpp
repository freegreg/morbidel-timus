/*
 * ACM Timus Online Contest - 18 September 2011
 * Problem D - Warlord of the Army of Mages
 */

#include <cstdio>
#include <vector>

#define MAXN	1024

int T, N, M, K;
std::vector<int> Deja, Mage1, Mage2;


bool Solve()
{
	int i, i1, i2, mag, steps = 0;
	int waits1, waits2;

	Deja.resize(K + 1, 0);

	i1 = 0;
	i2 = 0;
	waits1 = waits2 = 0;

	while (true)
	{
		steps++;
		if (waits1 > 0 && waits2 > 0)
			return false;
		if (waits1 > 0 && i2 == M)
			return false;
		if (waits2 > 0 && i1 == N)
			return false;
		if (i1 == N && i2 == M)
			break;

		if (i2 < M && waits2 == 0)
		{
			mag = Mage2[i2];
			if (mag > 0)
			{
				// mag intra la interviu
				if (Deja[mag] == 0)
				{
					Deja[mag] = 2;
					++i2;
				}
				else
				{
					waits2 = mag;
				}
			}
			else
			{
				// mag iese de la interviu. Celalalt se activeaza, daca-l astepta pe mag
				Deja[-mag] = 0;
				if (waits1 == -mag)
					waits1 = 0;
				++i2;
			}
		}

		if (i1 < N && waits1 == 0)
		{
			mag = Mage1[i1];
			if (mag > 0)
			{
				// mag intra la interviu
				if (Deja[mag] == 0)
				{
					Deja[mag] = 1;
					++i1;
				}
				else
				{
					waits1 = mag;
				}
			}
			else
			{
				// mag iese de la interviu. Celalalt se activeaza, daca-l astepta pe mag
				Deja[-mag] = 0;
				if (waits2 == -mag)
					waits2 = 0;
				++i1;
			}
		}
	}

	return true;
}

int main()
{
	int i, k;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d", &T);

	while (T--)
	{
		char ch;

		scanf("%d %d %d\n", &N, &M, &K);

		Mage1.resize(N, 0);
		Mage2.resize(M, 0);

		for (i = 0; i < N; i++)
		{
			scanf("%c %d\n", &ch, &k);
			if (ch == '-')
				k *= -1;
			Mage1[i] = k;
		}
		for (i = 0; i < M; i++)
		{
			scanf("%c %d\n", &ch, &k);
			if (ch == '-')
				k *= -1;
			Mage2[i] = k;
		}

		bool sol = Solve();

		printf("%s\n", sol ? ":-)" : ":-(");
	}

	return 0;
}