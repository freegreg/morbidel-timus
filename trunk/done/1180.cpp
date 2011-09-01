// ACM Online
// A Stone Game -> 1180

// solutie: suma e div. cu 3 ? atunci castiga 2, altfel castiga 1 cu s mod 3
// demonstratia ar fi ca 3 e singurul numar care da resturi puteri ale lui 2...

#include <stdio.h>

long s = 0;
char ch;

void main()
{
	while(scanf("%c", &ch) == 1)
	{
		if (ch < '0' || ch > '9') break;
		s += ch - 48;
	}
	if (s % 3 == 0) printf("2");
	else printf("1\n%d", s % 3);
}