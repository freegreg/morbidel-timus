/*
 *  ACM Timus Online
 *  Diplomas - Problem 1431
 */

#include <stdio.h>
#include <list>

#define input	"input.txt"
#define abs(x)	((x) > 0 ? (x) : -(x))

using namespace std;

int N, Sol;
int D[32];
list<int> Q;


void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	int i, x;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);

		Q.push_back(x);
	}
}

void Solve()
{
	Sol = 0;

	Q.sort();

	while (Q.size() > 0)
	{
		int d1, d2;

		if (Q.size() == 1)
		{
			Sol++;
			break;
		}

		d1 = Q.back();
		Q.pop_back();

		d2 = Q.back();
		Q.pop_back();

		Sol++;

		if (abs(d1 - d2 - 1) > 0)
			Q.push_back(abs(d1 - d2 - 1));

		Q.sort();
	}

	printf("%d\n", Sol);
}

int main()
{
	ReadData();
	Solve();

	return 0;
}
