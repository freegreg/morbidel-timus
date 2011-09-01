/*
 *  ACM Timus Online
 *  Archiver - Problem 1307
 *
 *  solutie: inlocuim 'the'urile... :D
 */

#include <stdio.h>
#include <string.h>

#define input "file.in"
#define output "file.cpp"

long Len;
char Text[200020], Text2[200020];


void readdata()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	Len = fread(Text, 1, 200010, stdin);
}

void solve()
{
	long i, h = 0;

	

	for (i = 0; i < Len; i++)
		if (Text[i] == 't' && Text[i + 1] == 'h' && Text[i + 2] == 'e')
			Text2[h++] = '|', i += 2;
		else
		{
			if (Text[i] == '\t')
				Text2[h++] = '\\', Text2[h++] = 't';
			else
			if (Text[i] == '\n')
				Text2[h++] = '\\', Text2[h++] = 'n';
			else
			if (Text[i] == '\'')
				Text2[h++] = '\\', Text2[h++] = '\'';
			else
			if (Text[i] == '%')
				Text2[h++] = '%', Text2[h++] = '%';
			else
			if (Text[i] == '\"')
				Text2[h++] = '\\', Text2[h++] = '\"';
			else
				Text2[h++] = Text[i];
		}

	#ifndef ONLINE_JUDGE
	freopen(output, "w", stdout);
	#endif

	printf("//CPP\n#include<stdio.h>\n#include <string.h>\nchar *Ionela=\"");
	for (i = 0; i < h; i++)
		printf("%c", Text2[i]);
	printf("\";\nint main()\n{\n");
	printf("\nchar *p = Ionela;for (; *p; p++)\n");
    printf("printf((*p == '|') ? \"the\" : \"%%c\", *p);\nreturn 0;\n}");
}

int main()
{
	readdata();
	solve();

	return 0;
}
