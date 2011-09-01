/*
 *  ACM Timus Online
 *  Penguins - Problem 1585
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;


int N;
map<string, int> Map;



int main()
{
	char s[1024];


	scanf("%d\n", &N);

	while (N--)
	{
		gets(s);
		Map[s]++;
	}

	int max = -1;
	string ales;
	map<string, int>::iterator it;

	for (it = Map.begin(); it != Map.end(); it++)
		if ((*it).second > max)
		{
			max = (*it).second;
			ales = (*it).first;
		};

	printf("%s\n", ales.c_str());


	return 0;
}
