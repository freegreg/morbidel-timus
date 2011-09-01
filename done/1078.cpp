/*
 *  ACM Timus Online
 *  Segments - Problem 1078
 */

#include <stdio.h>
#include <string.h>
#include <list>

#define input	"input.txt"
#define MAXN	500

using namespace std;

int N, MaxLen;
bool A[MAXN][MAXN];
struct Segm
{
	int l, r;
} S[MAXN];
int D[MAXN], Sol[MAXN], Fii[MAXN], Fiu[MAXN];
bool Flag[MAXN];
list<int> Q;



void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &S[i].l, &S[i].r);
	}
}

// i inclus in j
bool Include(int i, int j)
{
	return S[i].l > S[j].l && S[i].r < S[j].r;
}

void BF()
{
	int i, nod;


	while (Q.size() > 0)
	{
		nod = Q.front();
		Q.pop_front();
		Flag[nod] = false;

		for (i = 0; i < N; i++)
			if (A[nod][i])							// nod e inclus in i
			{
				if (D[i] == -1 || D[i] < D[nod] + 1)
				{
					D[i] = D[nod] + 1;
					Fiu[i] = nod;

					if (!Flag[i])
					{
						Flag[i] = true;
						Q.push_back(i);
					}
				}
			};
	}
}

void Road(int nod)
{
	if (nod != -1)
	{
		Road(Fiu[nod]);
		Sol[++Sol[0]] = nod;
	}
}

void Solve()
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (Include(i, j))
			{
				A[i][j] = true;
				Fii[j]++;
			};

	memset(D, -1, sizeof(D));
	memset(Flag, false, sizeof(Flag));

	Q.clear();

	// pornesc din frunze
	for (i = 0; i < N; i++)
		if (!Fii[i])
		{
			D[i] = 0;
			Fiu[i] = -1;
			Q.push_back(i);
		};

	BF(
		);

	int max = 0, tata = -1;
	for (i = 0; i < N; i++)
		if (D[i] > max)
		{
			max = D[i];
			tata = i;
		};

	if (max > MaxLen)
	{
		Sol[0] = 0;
		MaxLen = max;
		Road(tata);
	}

	if (Sol[0] == 0)
	{
		Sol[++Sol[0]] = 0;
	}

	printf("%d\n", Sol[0]);
	for (i = 1; i <= Sol[0]; i++)
		printf("%d ", Sol[i] + 1);
	printf("\n");
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
