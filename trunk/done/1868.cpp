/*
 * ACM Timus Online Judge Contest 15 October 2011
 * Problem G - Prediction Contest
 */

#include <cstdio>
#include <string>
#include <map>

int N, Res;
std::map<std::string, bool> gold, silver, bronze;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int i, j, k, pred, max;
	char sz[64], medal[8];

	// gold
	for (i = 0; i < 4; i++)
	{
		scanf("%s\n", &sz);
		gold[sz] = true;
	}
	// silver
	for (i = 0; i < 4; i++)
	{
		scanf("%s\n", &sz);
		silver[sz] = true;
	}
	// bronze
	for (i = 0; i < 4; i++)
	{
		scanf("%s\n", &sz);
		bronze[sz] = true;
	}

	max = 0;
	Res = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &k);

		pred = 0;
		for (j = 0; j < k; j++)
		{
			scanf("%s : %s\n", &sz, &medal);

			if (medal[0] == 'g' && gold.find(sz) != gold.end())
			{
					pred++;
			}
			if (medal[0] == 's' && silver.find(sz) != silver.end())
			{
					pred++;
			}
			if (medal[0] == 'b' && bronze.find(sz) != bronze.end())
			{
					pred++;
			}
		}

		if (pred > max)
		{
			max = pred;
			Res = 5;
		}
		else if (pred == max)
		{
			Res += 5;
		}
	}

	printf("%d", Res);

	return 0;
}