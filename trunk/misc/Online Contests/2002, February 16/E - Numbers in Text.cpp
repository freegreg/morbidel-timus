/*
 *  ACM Online
 *  Numbers in text - Problem 1179
 *
 *  solutie: parcurgem secvential si cƒnd noua cifr† e mai mic† decƒt penultima
 *  crestem bazele intermediare... O(36 * input)
 */

#include <stdio.h>

long Base[40], Cnt = 0, Bz;


int value(char ch)
{
	if (ch >= 'A' && ch <= 'Z') return ch - 55;
	else
	if (ch >= '0' && ch <= '9') return ch - '0';
	else return 36;
}

int main()
{
	char chr;
	int i, c, oc;

	do 
		scanf("%c", &chr); 
	while (value(chr) == 36);

	oc = value(chr);
	for (i = oc + 1; i <= 36; i++)
		Base[i]++;

	while (scanf("%c", &chr) == 1)
	{
		c = value(chr);
		if (c < oc)
			for (i = c + 1; i <= oc; i++)
				Base[i]++;
		oc = c;
	}

	for (i = 36; i >= 2; i--)
		if (Base[i] >= Cnt)
			Cnt = Base[i], Bz = i;
	printf("%ld %ld\n", Bz, Cnt);

	return 0;
}
