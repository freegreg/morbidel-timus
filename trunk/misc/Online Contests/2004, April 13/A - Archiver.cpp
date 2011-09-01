/*
 *  ACM Timus Contest, 13 Aprilie 2004
 *  Problem A - Archiver
 */

#include <stdio.h>
#include <string.h>

#define input "file.in"
#define output "file.cpp"
#define letter(a) (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
#define MAXWORDS 50

long nc, len;
short list[MAXWORDS + 1][110], text[200010], word[110];


/*  compare list[x] with word  */
int compare(int x)
{
	if (list[x][0] != word[0]) return 0;

	int i;

	for (i = 1; i <= word[0]; i++)
		if (word[i] != list[x][i])
			return 0;

	return 1;
}

int main()
{
	long i, j, c;
	char ch;
	bool cuv = false;

	nc = len = 0;


	/*  encode  */

	//freopen(input, "r", stdin);
	while (scanf("%c", &ch) == 1)
	{
		c = ch;
		if (nc == MAXWORDS)
		{
			text[len++] = c;
			continue;
		}

		if (cuv && !letter(c))
		{
			cuv = false;

			for (i = 0; i < nc; i++)
				if (compare(i))
					break;
			text[len++] = -i;
			text[len++] = c;
			if (i == nc)
			{
				/*  add word  */
				for (i = 0; i <= word[0]; i++)
					list[nc][i] = word[i];
				nc++;
			}
			word[0] = 0;
		} else
		if (!cuv && !letter(c))
			text[len++] = c;
		else
		if (letter(c))
			word[++word[0]] = c, cuv = true;
	}


	/*  decode and flush to C source code  */

	//freopen(output, "w", stdout);
	printf("//CPP\n\n#include <stdio.h>\n\n#define a printf\n\n");


	/*  writing variables  */

	printf("char x[%ld][110] = {\n", nc);
	for (i = 0; i < nc - 1; i++)
	{
		printf("{\"");
		for (j = 1; j <= list[i][0]; j++)
			printf("%c", list[i][j]);
		printf("\"},\n");
	}
	printf("{\"");
	for (j = 1; j <= list[nc - 1][0]; j++)
		printf("%c", list[nc - 1][j]);
	printf("\"}\n};\n\n");


	/*  write code  */

	printf("int main()\n{\n");

	for (c = cuv = i = 0; i < len; i++)
	{
		if (text[i] <= 0) /*  print x[-text[i]] word  */
		{
			if (cuv)
				c = 0, printf("\");\n");
			printf("\ta(\"%%s\", x[%ld]);\n", -text[i]), cuv = false;
		}
		else
		{
			if (!cuv)
			{
				if (text[i] == 10)
					printf("\ta(\"\\n");
				else
				if (text[i] == '\t')
					printf("\ta(\"\\t");
				else
				if (text[i] == '"')
					printf("\ta(\"\\\"");
				else
					printf("\ta(\"%c", text[i]);
				cuv = c = 1;
			}
			else
			{
				c++;
				if (text[i] == 10)
					printf("\\n");
				else
				if (text[i] == '\t')
					printf("\\t");
				else
				if (text[i] == '"')
					printf("\\\"");
				else
					printf("%c", text[i]);
			}
			if (c == 1000 || i == len - 1)
				c = 0, printf("\");\n"), cuv = 0;
		}
	}


	printf("\n\treturn 0;\n}\n");

	return 0;
}
