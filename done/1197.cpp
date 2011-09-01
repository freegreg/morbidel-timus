// ACM Online
// Lonesome Knight - Problem 1197

#include <stdio.h>

char s[3];
int n, table[8][8] =           // p†i nu?
{{2, 3, 4, 4, 4, 4, 3, 2},
 {3, 4, 6, 6, 6, 6, 4, 3},
 {4, 6, 8, 8, 8, 8, 6, 4},
 {4, 6, 8, 8, 8, 8, 6, 4},
 {4, 6, 8, 8, 8, 8, 6, 4},
 {4, 6, 8, 8, 8, 8, 6, 4},
 {3, 4, 6, 6, 6, 6, 4, 3},
 {2, 3, 4, 4, 4, 4, 3, 2}};

void main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", &s);
		printf("%d\n", table[s[0] - 97][s[1] - 49]);
	}
}