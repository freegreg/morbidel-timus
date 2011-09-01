/*
 *  ACM Timus Online Judge
 *  Pascal vs. C++. Version 2
 */

#include <stdio.h>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <string.h>

#define MAXN			10001
#define INPUT_FILE		"input.txt"
#define ABS(x)			((x) > 0 ? (x) : -(x))
#define MAX(a, b) 		((a) > (b) ? (a) : (b))
#define MIN(a, b) 		((a) < (b) ? (a) : (b))

using namespace std;

map<long, list<int> > mapIndex;
vector<long> V;
int N;



void ReadData()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif
	scanf("%d", &N);

	V.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &V[i]);
		mapIndex[V[i]].push_back(i);
	}
}

void Solve()
{
}

void Generate(int n)
{
	int i;


	FILE *f = fopen(INPUT_FILE, "wt");

	fprintf(f, "%d\n", n);
	for (i = 0; i < n; i++)
		fprintf(f, "%ld ", 1000000000L - i);

	fclose(f);
}


int main()
{
	//Generate(10000);
	ReadData();
	Solve();

	return 0;
}
