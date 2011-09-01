// ACM Online
// Symbolic Sequence - Problem 1219
// generati un sir aiurea de 10^6 caractere a.i fiecare nu apare mai mult de
// 40000 ori, fiecare sec. de 2 de 2000, de 3 de 100;

// random la greu

#include <stdio.h>
#include <stdlib.h>

long flag[300];

void main()
{
	long i;
	char ch;
	for (i = 0; i < 300; flag[i++] = 0);
	// randomize();
	for (i = 0; i < 1000000L; i++)
	{
		do
			ch = 97 + rand() % 26;
		while (flag[ch] > 39999L);
		flag[ch]++;
		printf("%c", ch);
	}
}