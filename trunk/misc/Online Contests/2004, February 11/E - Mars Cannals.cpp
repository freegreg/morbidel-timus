/*
 *  ACM Timus Contest 28 Feb 2004
 *  Problem E - Mars Cannals
 *
 *  solutie: citesc linie cu linie si dinamica: tin lmax stanga, sus, diag stanga si diag dreapta. Recurenta e banala...
 */

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAXN 1500


int N, max1, max2; 
char S1[MAXN], S[MAXN];
struct shmen
{
	int left, leftd, up, rightd;
} L1[MAXN], L[MAXN];



void update(int lin, int col)
{
	int l, u, ld, rd, max;

	if (!lin)
	{
		l = L1[col].left; u = L1[col].up;
		ld = L1[col].leftd; rd = L1[col].rightd;
		max = max(l, max(u, max(rd, ld)));
		if (S1[col - 1] == 's' && max > max2)
			max2 = max;
		if (S1[col - 1] == 'S' && max > max1)
			max1 = max;
	} else
	{
		l = L[col].left; u = L[col].up;
		ld = L[col].leftd; rd = L[col].rightd;	
		max = max(l, max(u, max(rd, ld)));
		if (S[col - 1] == 's' && max > max2)
			max2 = max;
		if (S[col - 1] == 'S' && max > max1)
			max1 = max;
	}
}

int main()
{
	int i, j;

	scanf("%d", &N);

	max1 = max2 = 0;

	scanf("%s", &S1);
	L1[1].left = L1[1].leftd = L1[1].up = L1[1].rightd = 1;
	update(0, 1);

	for (i = 2; i <= N; i++)
	{
		L1[i].leftd = L1[i].up = L1[i].rightd = 1;
		if (S1[i - 1] == S1[i - 2])
			L1[i].left = L1[i - 1].left + 1;
		else
			L1[i].left = 1;
		update(0, i);
	}

	for (i = 2; i <= N; i++)
	{
		scanf("%s", &S);

		for (j = 1; j <= N; j++)
		{
			/*  left  */
			if (j > 1 && S[j - 1] == S[j - 2])
				L[j].left = L[j - 1].left + 1;
			else
				L[j].left = 1;

			/*  left diagonal  */
			if (j > 1 && S[j - 1] == S1[j - 2])
				L[j].leftd = L1[j - 1].leftd + 1;
			else
				L[j].leftd = 1;

			/*  up  */
			if (S[j - 1] == S1[j - 1])
				L[j].up = L1[j].up + 1;
			else
				L[j].up = 1;

			/*  right diagonal  */
			if (j < N && S[j - 1] == S1[j])
				L[j].rightd = L1[j + 1].rightd + 1;
			else
				L[j].rightd = 1;

			update(1, j);
			i = i;
		}

		strcpy(S1, S);
		memcpy(L1, L, sizeof(L));
	}

	if (max1 > max2)
		printf("S\n%d\n", max1);
	else
	if (max1 < max2)
		printf("s\n%d\n", max2);
	else
		printf("?\n%d\n", max1);

	return 0;
}
