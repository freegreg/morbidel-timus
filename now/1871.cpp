/*
 * ACM Timus Online Judge Contest 15 October 2011
 * Problem J - Seismic Waves
 */

#include <cstdio>
#include <string>
#include <vector>
#include <map>

#define INF		1000000

int N, Flag[100], D[100];
std::string Mes;
std::vector<std::string> Names;
std::vector<std::string> Followers[100];
std::vector<int> Result;
std::map<std::string, int> Map;


void DF(int n, std::string mes)
{
	int i, nod;
	std::string newmes;

	if (mes.size() > 140)
		return;

	Flag[n] = 1;
	Result.push_back(n);
	for (i = 0; i < Followers[n].size(); i++)
	{
		nod = Map[Followers[n][i]];

		if (!Flag[nod])
		{
			newmes = std::string("RT @") + Names[n] + ": " + mes;
			DF(nod, newmes);
		}
	}
}

void Dijkstra()
{
	int i, j, k, min, nod;
  int src = 0;

	D[src] = 0;
	Flag[src] = 1;

	for (i = 1; i < N; i++)
  {
		D[i] = INF;
  }

	for (i = 0; i < Followers[src].size(); i++)
	{
		nod = Map[Followers[src][i]];
		D[nod] = Mes.size();
    Flag[nod] = 1;
	}

	for (i = 0; i < N; i++)
	{
		min = INF;

		for (j = 0; j < N; j++)
			if (!Flag[j] && D[j] < min)
			{
				min = D[j];
				k = j;
			};

		if (min == INF)
			continue;
		Flag[k] = 1;

		// relax all followers of k (k retweets the message)
		for (j = 0; j < Followers[k].size(); j++)
		{
			nod = Map[Followers[k][j]];
			int dist = D[k] + 4 + 2 + Names[k].size();

			if (dist < D[nod])
			{
				D[nod] = dist;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int i, j, k;
	char sz[1024];

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s %d", &sz, &k);

		Names.push_back(sz);
		Map[sz] = i;
		for (j = 0; j < k; j++)
		{
			scanf("%s", &sz);
			Followers[i].push_back(sz);
		}
		scanf("\n");
	}
	gets(sz);
	Mes = sz;

	// First tweets Mes
	Dijkstra();

	for (i = 0; i < N; i++)
		if (D[i] <= 140)
			Result.push_back(i);

	printf("%d\n", Result.size());
	for (i = 0; i < Result.size(); i++)
		printf("%s\n", Names[Result[i]].c_str());

	return 0;
}
