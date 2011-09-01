// ACM Online
// Divorce of the seven dwarfs - Problem 1243

// solutie: tre' sa impartim numarul la 7 si sa afisam restul...
// foarte grea problema...

#include <stdio.h>

int a[100];

void main()
{
	int i, aa;
	char ch;
	while (1)
	{
		scanf("%c", &ch);
		if (ch < '0' || ch > '9') break;
		a[++a[0]] = ch - 48;
	}
	for (aa = 0, i = 1; i <= a[0]; i++)
		aa = (10 * aa + a[i]) % 7;
	printf("%d", aa);
}