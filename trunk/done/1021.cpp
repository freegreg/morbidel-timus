// ACM Online
// Sacrament of the Sum - Problem 1021

// solutie: adunam 32768 la toate numerele apoi tinem primul sir pe flag
// si belind al doilea sir vedem daca e flag de diferenta atunci e bine...
// suma devine 10000 += 2 * 32768 = 75536...

#include <stdio.h>
#include <string.h>

long n, suma, sol = 0;
char flag[100001L];      // pune 100.000

void main()
{
	long i, nr;
	suma = 75536L;
	memset(flag, 0, sizeof(flag));

	scanf("%ld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &nr);
		nr += 32768L;
		if (nr > suma) continue;
		flag[nr] = 1;
	}
	scanf("%ld", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &nr);
		nr += 32768L;
		if (nr > suma) continue;
		if (flag[suma - nr])
		{ sol = 1; break; }
	}
	printf(sol ? "YES" : "NO");
}