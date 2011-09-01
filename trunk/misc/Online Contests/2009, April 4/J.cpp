/*
 *  ACM Timus
 *  J - Penguin-Avia
 */

#include <stdio.h>
#include <vector>

using namespace std;

int N, D, A, NC, Cost;
int Level[128], Flag[128];
char S[128][128];
vector<vector<int> > Comp;

void ReadData()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d %d %d", &N, &D, &A);

	for (int i = 0; i < N; i++)
		scanf("%s", &S[i]);
}

void DF(int nod)
{
	int i;

	Flag[nod] = NC;
	Comp[NC - 1].push_back(nod);

	for (i = 0; i < N; i++)
	{
		if (S[nod][i] == '1')
		{
			if (!Flag[i])
			{
				Level[i] = Level[nod] + 1;
				DF(i);
			}
			else
			if (Level[i] + 1 < Level[nod])
			{
				// muchie inapoi, deci necritica
				S[nod][i] = S[i][nod] = 'd';
				Cost += D;
			}
		};
	}
}

void Solve()
{
	int i, j;


	NC = 0;
	Cost = 0;

	// determinam componentele conexe. In DF determinam si muchiile critice
	for (i = 0; i < N; i++)
		if (!Flag[i])
		{
			NC++;
			Comp.resize(NC);
			Level[i] = 1;

			DF(i);
		};

	// apoi unim comp conexe intre ele
	for (i = 0; i < NC - 1; i++)
	{
		int n1 = Comp[i][0];
		int n2 = Comp[i + 1][0];

		S[n1][n2] = S[n2][n1] = 'a';
		Cost += A;
	}

	printf("%d\n", Cost);
	for (i = 0; i < N; i++, printf("\n"))
		for (j = 0; j < N; j++)
			printf("%c", (S[i][j] != '1') ? S[i][j] : '0');
}

int main()
{
	ReadData();
	Solve();

	return 0;
}
