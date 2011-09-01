/*
 *  ACM Online
 *  Disk Tree - Problem 1067
 *
 *  solutie: traiasca STLu'... sortam inputu si apoi avem grija pe acolo
 */

#include <stdio.h>
#include <string>

using namespace std;

int N, Len;
char line[100];
string Text[501], foo, Deep[50], ODeep[50];

#define min(a, b) ((a) > (b) ? (b) : (a))


void baga(string foo)
{
	strcpy(line, foo.c_str());
	printf("%s\n", line);
}

int main()
{
	int i, j, k, l, ol, p1, p2;

	//freopen("file.in","r", stdin);

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", &line);
		Text[i] = line; // :D

		for (j = 0; j < Text[i].size(); j++)
			if (Text[i][j] == '\\')
				Text[i][j] = 1;
	}

	/*  sort input  */
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (Text[i] > Text[j])
				foo = Text[i], Text[i] = Text[j], Text[j] = foo;

	for (i = 0; i < N; i++)
	{
		for (p1 = -1, Len = 0; p1 != Text[i].size(); Len++)
		{
			p2 = p1;
			p1 = Text[i].find_first_of(1, p1 + 1);
			if (p1 == -1)
				p1 = Text[i].size();
			foo = Text[i].substr(p2 + 1, p1 - p2 - 1);
			Deep[Len] = foo;
		}
		
		j = 0;
		if (i != 0)
			for (j = 0; j < min(ol, Len); j++)
				if (Deep[j] != ODeep[j]) break;

		for (l = j; l < Len; l++)
		{
				for (k = 0; k < l; k++)
					printf(" ");
				baga(Deep[l]);
		}

		for (ol = 0; ol < Len; ol++)
			ODeep[ol] = Deep[ol];
	}

	return 0;
}
