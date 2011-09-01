/*
 * ACM Timus Online
 * Travelling Tours - Problem 1077
 *
 * solutie: BFS/DFS pe toate comp conexe -> arbori. Muchiile care nu fac parte din ei ne vor da nr de cicluri => M - N + K
 * 	    Demonstrația e simplă: per comp conexă am Mi-(Ni-1) muchii extra => Mi-Ni+1. Sumă după i de la 1 la K (nr de c conexe) => cicluri = M-N+K
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <list>

#define MAXN	256

int N, M;
int A[MAXN][MAXN], Flag[MAXN], T[MAXN];
std::vector<std::vector<int> > Sol;


void DFS(int node)
{
	int i;

	Flag[node] = 1;
	for (i = 1; i <= N; i++)
		if (!Flag[i] && A[node][i] > 0)
		{
			// muchia node-i e parte din arborele DFS, o marchez cu 2. 
			// Cele rămase cu 1 vor fi muchiile extra care vor da nr de cicluri
			
			T[i] = node;
			A[node][i] = A[i][node] = 2;

			DFS(i);
		}
}

void BFS(int node)
{
	std::list<int> q;
	int nod, i;

	q.push_back(node);
	Flag[node] = 1;
	T[node] = -1;
	
	while (q.size() > 0)
	{
		nod = q.front();
		q.pop_front();

		for (i = 1; i <= N; i++)
			if (A[nod][i] && !Flag[i])
			{
				A[nod][i] = A[i][nod] = 2;
				q.push_back(i);
				Flag[i] = 1;
				T[i] = nod;
			}
	}
}

void Solve()
{
	int i, j, k = 0;

	for (i = 1; i <= N; i++)
		if (!Flag[i])
		{
			// o nouă componentă conexă
			k++;
			T[i] = -1;
			DFS(i);
		};

	// afișez soluția - caut toate muchiile cu A[i][j] = 1 și merg spre rădăcină din ambele -> compun apoi ciclul
	printf("%d\n", M - N + k);
	if (M - N + k < 0)
		while(1);

	std::vector<int> cycle1, cycle2;

	for (i = 1; i < N; i++)
		for (j = i + 1; j <= N; j++)
			if (A[i][j] == 1)
			{
				int nod;

				cycle1.clear();
				cycle2.clear();

				nod = i;
				while (nod != -1)
				{
					cycle1.push_back(nod);
					nod = T[nod];
				}
				nod = j;
				while (nod != -1)
				{
					cycle2.push_back(nod);
					nod = T[nod];
				}

				// tai nodurile comune
				while (cycle1.size() > 0 && cycle2.size() > 0 && cycle1[cycle1.size() - 1] == cycle2[cycle2.size() - 1])
				{
					nod = cycle1[cycle1.size() - 1];
					cycle1.pop_back();
					cycle2.pop_back();
				}
				cycle1.push_back(nod);
				for (k = cycle2.size() - 1; k >= 0; k--)
					cycle1.push_back(cycle2[k]);

				printf("%d ", cycle1.size());
				for (k = 0; k < cycle1.size(); k++)
					printf("%d ", cycle1[k]);
				printf("\n");
		
				for (k = 0; k < cycle1.size()-1; k++)
					if (A[cycle1[k]][cycle1[k + 1]] == 0)
					{
						while(1);
						printf("ERROR! edge %d %d is not correct\n", cycle1[k], cycle1[k + 1]);
					}
			};
}

int main()
{
	int i;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d %d", &N, &M);


	memset(A, 0, sizeof(A));
	memset(Flag, 0, sizeof(Flag));

	for (i = 0; i < M; i++)
	{
		int n1, n2;

		scanf("%d %d", &n1, &n2);

		A[n1][n2] = A[n2][n1] = 1;
	}

	Solve();

	return 0;
}

