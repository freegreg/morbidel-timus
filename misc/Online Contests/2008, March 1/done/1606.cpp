/*
 *  ACM Timus Online
 *  Slalom - Problem 1606
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

#define input "input.txt"

using namespace std;

struct elem
{
	int x, y;
	int index;
};

int N;
vector<elem> V;
vector<int> Sol;




void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d", &N);

	int i;

	for (i = 0; i < N; i++)
	{
		elem e;

		e.index = i;
		scanf("%d %d", &e.x, &e.y);

		V.push_back(e);
	}
}

bool operator < (const elem &a, const elem &b)
{
	return a.y > b.y;							// descrescator
}

void Solve()
{
	int i, old = -1;
	bool bUp;


	sort(V.begin(), V.end());

	if (V.size() == 1)
	{
		printf("1\n1\n");
		return;
	}

	bUp = V[0].x < V[1].x;

	i = 0;
	if (V[i].index + 1 != old)
	{
		Sol.push_back(V[i].index + 1);
		old = V[i].index + 1;
	}

	for (; i < V.size(); i++)
	{
		if (bUp)
		{
			while (i < V.size() - 1 && V[i].x < V[i + 1].x)
				i++;
		} else
		{
			while (i < V.size() - 1 && V[i].x > V[i + 1].x)
				i++;
		}

		if (V[i].index + 1 != old)
		{
			Sol.push_back(V[i].index + 1);
			old = V[i].index + 1;
		}

		bUp = !bUp;

		if (bUp)
		{
			while (i < V.size() - 1 && V[i].x < V[i + 1].x)
				i++;
		} else
		{
			while (i < V.size() - 1 && V[i].x > V[i + 1].x)
				i++;
		}

		if (V[i].index + 1 != old)
		{
			Sol.push_back(V[i].index + 1);
			old = V[i].index + 1;
		}

		bUp = !bUp;
	}

	printf("%d\n", Sol.size());

	for (i = 0; i < Sol.size(); i++)
		printf("%d ", Sol[i]);

	printf("\n");
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
