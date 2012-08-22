/*
 * ACM Timus Online Judge
 * Russian pipelines
 *
 * soluție: sortare topologică apoi ia fiecare nod din sortare și relaxează muchiile
 */

#include <cstdio>
#include <vector>
#include <list>

#define INPUT_FILE 	"input.txt"
#define OUTPUT_FILE 	"output.txt"

using namespace std;

int N, M, S, F;
vector<int> D, T;
vector<bool> Flag;

struct edge
{
	int node, cost;
	edge (int n, int c)
	{
		node = n;
		cost = c;
	}
};
vector<list<edge> > A;

void DF(int node)
{
	list<edge>::iterator it;

	Flag[node] = true;
	for (it = A[node].begin(); it != A[node].end(); ++it)
		if (!Flag[it->node])
		{
			DF(it->node);
		}
	T.push_back(node);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif
	scanf("%d %d", &N, &M);

	A.resize(N);
		
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);
		A[a - 1].push_back(edge(b - 1, c));
	}
	scanf("%d %d", &S, &F);
	--S;
	--F;

	Flag.resize(N, false);
	D.resize(N, -1);

	// topological order
	DF(S);

	D[S] = 0;
	for (int i = T.size() - 1; i >= 0; --i)
	{
		list<edge>::iterator it;

		for (it = A[T[i]].begin(); it != A[T[i]].end(); ++it)
			if (D[T[i]] + it->cost > D[it->node])
			{
				D[it->node] = D[T[i]] + it->cost;
			}
	}

	if (D[F] == -1)
	{
		printf("No solution");
	}
	else
	{
		printf("%d", D[F]);
	}

	return 0;
}