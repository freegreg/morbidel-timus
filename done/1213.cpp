/*
 *  ACM Timus Online
 *  Cockroaches! - Problem 1213
 *
 *  solutie: afis N - 1...
 */

#include <stdio.h>
#include <string>

using namespace std;

int N = 0;
string Text[50];


int main()
{
	int i;
	char shit[100];
	string f1, f2;

	scanf("%s", &shit);

	while (scanf("%s", &shit) == 1)
	{
		if (!strcmp(shit, "#")) break;
		f1 = shit;
		i = f1.find_first_of("-", 0);
		f2 = f1.substr(i + 1, f1.size());
		f1.erase(i, f1.size());

		for (i = 0; i < N; i++)
			if (Text[i] == f1)
				break;
		if (i == N)
			Text[N++] = f1;

		for (i = 0; i < N; i++)
			if (Text[i] == f2)
				break;
		if (i == N)
			Text[N++] = f2;
	}

	printf("%d\n", N ? N - 1 : 0);


	return 0;
}
