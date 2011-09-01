/*
 *  ACM Timus Online
 *  Bus Routes - Problem 1137
 *
 *  solutie: facem un graf din linii cu muchie daca au o statie comuna. Tinem pe biti o matrice de flag cu pozitia fiecarui 
 *  element in linie. gets AC with freopen!
 */


#include <stdio.h>

#define MAXL 101
#define MAXS 1001
#define MAXID 10001
#define value(l, x) ((Flag[l][x >> 3] >> (x % 8)) & 1)   /*  intoarce valoarea Flag[l][x]  */
#define check(l, x) (Flag[l][x >> 3] |= (1 << (x % 8)))  /*  seteaza Flag[l][x]  */

int N, Len;
unsigned char Flag[MAXL][MAXID >> 3];
short int A[MAXL][MAXL], Lines[MAXL][MAXS];
short int Q[MAXL], Flag2[MAXL];



void readdata()
{
	int i, j;

//	freopen("file.in", "r", stdin);
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &Lines[i][0]);
		Len += Lines[i][0];
		for (j = 1; j <= Lines[i][0] + 1; j++)
		{
			scanf("%d", &Lines[i][j]);
			check(i, Lines[i][j]);
		}
	}
}

void solution(int line, int poz)
{
	int i, now;

	for (i = 1; i <= Lines[line][0]; i++, poz = (poz == Lines[line][0]) ? 1 : poz + 1)
	{
		now = Lines[line][poz];

		if (now < 0)
		{
			solution(-now, A[line][-now]);
			printf("%d ", Lines[-now][A[line][-now]]);
		} else
			printf("%d ", now);
	}
}

void solve()
{
	int i, j, k, poz, l1, l2;

	/*  facem un graf cu A[i][j] = pozitia unde apare in linia j prima statie comuna din linia i (care e pe pozitia A[j][i]!!!)  */
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			for (poz = 0, k = 1; k <= Lines[j][0]; k++)
				if (value(i, Lines[j][k]))
					poz = k, k = Lines[j][0];

			poz++; poz--;
			A[i][j] = poz;
		}

	/*  acum caut un arbore cu BF, pun un -L la intersectii, L e cea care vine de acolo pe pozitia cunoscuta a[...] */
	for (l1 = 0, Q[0] = l2 = 1; l1 < l2; l1++)
	{
		k = Q[l1]; Flag2[k] = 1;
		for (i = 1; i <= N; i++)
			if (!Flag2[i] && A[k][i])
			{
				Lines[k][A[i][k]] = -i;
				Q[l2++] = i; Flag2[i] = 1;
			}
	}
	printf("%d ", Len);
	solution(1, 1);
	printf("%d\n", Lines[1][Lines[1][0] + 1]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
