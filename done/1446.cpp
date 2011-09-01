/*
 *  ACM Timus Online
 *  Sorting Hat - Problem 1446
 */

#include <stdio.h>
#include <list>
#include <map>
#include <string>
#include <string.h>

#define INPUT_FILE "input.txt"

using namespace std;

int N;
map<string, list<string> > Map;


void PrintShit(list<string> l)
{
	list<string>::iterator it;

	for (it = l.begin(); it != l.end(); it++)
		printf("%s\n", (*it).c_str());
	printf("\n");
}



int main()
{
	int i;
	string s1, s2;
	char sz[1024];


#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif
	scanf("%d\n", &N);

	for (i = 0; i < N; i++)
	{
		gets(sz);
		if (sz[strlen(sz) - 1] == '\n')
			sz[strlen(sz) - 1] = 0;
		s1 = sz;

		scanf("%s\n", &sz);
		s2 = sz;

		Map[s2].push_back(s1);
	}

	printf("Slytherin:\n");
	PrintShit(Map["Slytherin"]);

	printf("Hufflepuff:\n");
	PrintShit(Map["Hufflepuff"]);

	printf("Gryffindor:\n");
	PrintShit(Map["Gryffindor"]);

	printf("Ravenclaw:\n");
	PrintShit(Map["Ravenclaw"]);


	return 0;
}
