/*
 *  ACM Online
 *  Spell Checker - Problem 1038
 *
 *  solutie: ce solutie, baleiem tot textul...
 */

#include <stdio.h>

char ch;
int m = 0, cuv, ph, nrc;


int mica(char c)
{
	return (c >= 'a' && c <= 'z');
}

int mare(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int punc(char c)
{
	return (c == '.' || c == '!' || c == '?');
}

int main()
{
	ph = cuv = nrc = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (cuv && (mica(ch) || mare(ch))) nrc++;
		if (mica(ch) && !ph) m++, ph = cuv = nrc = 1;
		if (mare(ch) && !ph) ph = 1;
		if (ph && punc(ch)) cuv = nrc = ph = 0;
		if (ph && !mica(ch) && !mare(ch)) cuv = nrc = 0;
		if (!cuv && (mica(ch) || mare(ch))) cuv = 1, nrc = 1;
		if (cuv && nrc > 1 && mare(ch)) m++;
	}
	printf("%d\n", m);

	return 0;
}
