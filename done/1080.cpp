/*
 *  ACM Timus Online
 *  Map Colouring - Problem 1080
 */

#include <stdio.h>
#include <list>

#define input	"input.txt"
#define MAXN	100

using namespace std;

int N;
bool A[MAXN][MAXN];
int Colours[MAXN];
bool Flag[MAXN];



void ReadData()
{
	int i, j;


	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		do
		{
			scanf("%d", &j);
			if (j == 0) break;

			j--;

			A[i][j] = A[j][i] = true;
		}
		while (j != 0);
	}
}

bool BF(int nod)
{
	int i;
	list<int> q;


	Flag[nod] = true;
	q.push_back(nod);

	while (q.size() > 0)
	{
		nod = q.front();
		q.pop_front();

		for (i = 0; i < N; i++)
			if (A[nod][i])
			{
				if (Flag[i] && Colours[i] != 1 - Colours[nod])
					return false;

				if (Colours[i] == -1)
				{
					Colours[i] = 1 - Colours[nod];
				}

				if (!Flag[i])
				{
					Flag[i] = true;
					q.push_back(i);
				}
			};
	}

	return true;
}

void Solve()
{
	int i, j;


	for (i = 0; i < N; i++)
		Colours[i] = -1;

	Colours[0] = 0;

	if (!BF(0))
	{
		printf("-1\n");
		return;
	}

	for (i = 0; i < N; i++)
		printf("%d", Colours[i]);
	printf("\n");
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
