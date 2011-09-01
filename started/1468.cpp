/*
 *  ACM Timus
 *  Fraction
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN	10001
#define max(a, b) ((a) > (b) ? (a) : (b))

long M, N, Base;
bool Rest[MAXN];


int main()
{
	int k, neper, per;

	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	while (scanf("%d %d", &M, &N) == 2 && M && N)
	{
		scanf("%d", &Base);
		memset(Rest, false, sizeof(Rest));

		// nr de cifre din afara perioadei e max(puterea lui 2, puterea lui 5) din descomp in f.p. a lui N
		char pint[16], cat[32];
		strcpy(cat, _ltoa(M / N, pint, Base));
		for (k = 0; k < strlen(cat); k++)
			if (cat[k] >= 'a' && cat[k] <= 'z')
				cat[k] -= 32;
		printf("%s", cat);
		if (strlen(cat) == 0)
			while(1);
		M %= N;

		int p2 = 0, p5 = 0, n = N;
		while (n % 2 == 0) 
			p2++, n /= 2;
		while (n % 5 == 0) 
			p5++, n /= 5;
		neper = max(p2, p5);

		if (M)
		{
			printf(".");
			int cif, rest = M;
			
			// cifrele neperiodice
			for (k = 0; k < neper; k++)
			{
				cif = rest * Base / N;
				printf("%c", (cif > 9) ? ('A' + cif - 10) : '0' + cif);
				rest = (rest * Base) % N;
			}

			if (rest)
			{
				printf("(");
				while (!Rest[rest])
				{
					Rest[rest] = true;
					cif = rest * Base / N;
					printf("%c", (cif > 9) ? ('A' + cif - 10) : '0' + cif);
					rest = (rest * Base) % N;
				}
				printf(")");
			}
		}
		printf("\n");
	}
}
