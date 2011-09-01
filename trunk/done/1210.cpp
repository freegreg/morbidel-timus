/*
 *  ACM Timus Online
 *  Kind Spirits - Problem 1210
 *
 *  solutie: a[i] = min(Eij + a[j]), j fiu i...
 */

#include <stdio.h>
#include <string.h>

#define MAXN 31
#define min(a, b) ((a) > (b) ? (b) : (a))

int N = 0, Nlev, NL;
long Levc[MAXN], Leva[MAXN], Sol;



int main()
{
	int i, son, value;


	for (scanf("%d", &NL); NL--; )
	{
		for (scanf("%d", &Nlev); Nlev--; )
		{
			Levc[++Levc[0]] = 2000000000L;
			while (1)
			{
				scanf("%d", &son);
				if (!son) break;
				scanf("%d", &value);

				Levc[Levc[0]] = min(Levc[Levc[0]], value + Leva[son]);
			}
		}
		scanf("\n%c\n", &son); /*  lol  */

		memcpy(Leva, Levc, sizeof(Levc));
		memset(Levc, 0, sizeof(Levc));
	}

	for (Sol = 2000000000L, i = 1; i <= Leva[0]; i++)
		if (Leva[i] < Sol)
			Sol = Leva[i];

	printf("%d\n", Sol == 2e9L ? 0 : Sol);

	return 0;
}
