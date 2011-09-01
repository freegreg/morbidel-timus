/*
 *  ACM Timus Contest, 15 Aprilie 2004
 *  Problem I - Dirt
 */

#include <stdio.h>


#define input "file.in"
#define MAXN 501

int M, N, SL, SC, FL, FC, Lev, Lmax;
struct matrix
{
	int boots, len;
} A[MAXN][MAXN];
short int QL[300000], QC[300000];
char Map[MAXN][MAXN], Flag[MAXN][MAXN];



void readdata()
{
	int i;

	//freopen(input, "r", stdin);
	scanf("%d %d %d %d %d %d", &M, &N, &SL, &SC, &FL, &FC);
	for (i = 0; i < M; i++)
			scanf("%s", Map + i);
}

int good(int l, int c)
{
	return (l >= 0 && l < M && c >= 0 && c < N && Map[l][c] != '0');
}

void expand(int l, int c)
{
	int i, j, nl, nc;
	int boots, len, oboots, olen, cboots, clen;

	for (i = -1; i < 2; i++)
		for (j = -1; j < 2; j++)
		{
			nl = l + i; nc = c + j;
			if (!good(nl, nc) || !i && !j) continue;

			boots = oboots = A[l][c].boots, len = olen = A[l][c].len;
			cboots = A[nl][nc].boots; clen = A[nl][nc].len;
			if (Map[l][c] + Map[nl][nc] - 2 * '0' == 3) /*  schimb solul  */
				boots++;
			len++;
			if (!clen || (boots < cboots || boots == cboots && len < clen))
			{
				/*  am expandat, bag in coada  */
				A[nl][nc].boots = boots, A[nl][nc].len = len;
				if (!Flag[nl][nc])
					QL[Lmax] = nl, QC[Lmax++] = nc, Flag[nl][nc] = 1;
			}
		}
}

void solve()
{
	int l, c;

	SL--; SC--; FL--; FC--;

	/*  Lee la greu  */
	QL[0] = SL; QC[0] = SC; Flag[SL][SC] = 1;

	A[SL][SC].boots = 0; A[SL][SC].len = 1;
	for (Lev = 0, Lmax = 1; Lev < Lmax; Lev++)
	{
		l = QL[Lev]; c = QC[Lev];
		Flag[l][c] = 0;
		expand(l, c);
	}

	/*for (l = 0; l < M; l++, printf("\n"))
		for (c = 0; c < N; c++)
			printf("(%2.d, %2.d)  ", A[l][c].boots, A[l][c].len);*/

	printf("%d %d\n", A[FL][FC].len, A[FL][FC].boots);
}

int main()
{
	readdata();
	solve();

	return 0;
}
