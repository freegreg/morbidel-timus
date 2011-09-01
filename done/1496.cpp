/*
 *  ACM Timus Online
 *  Spammer - Problem 1496
 */

#include <stdio.h>
#include <map>
#include <string>

#define input "input.txt"

using namespace std;

int N;
map<string, int> Map;



void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif


	int i;
	char sz[1024];
	string s;


	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", &sz);

		s = sz;

		Map[s]++;
	}
}

void Solve()
{
	map<string, int>::iterator it;


	for (it = Map.begin(); it != Map.end(); it++)
	{
		pair<string, int> x = *it;

		if (x.second > 1)
			printf("%s\n", x.first.c_str());
	}
}

int main()
{
	ReadData();
	Solve();

	return 0;
}
