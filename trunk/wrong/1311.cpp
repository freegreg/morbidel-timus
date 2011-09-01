/*
 *  ACM Timus Contest, 13 Aprilie 2004
 *  Problem E - Bricks
 */

#include <stdio.h>
#include <string.h>

int N, N1, N2, l;
struct brick
{
	int l1, l2;
	float med;
} L1[1001], L2[1001];


int main()
{
	long i, j, a, b;

	freopen("file.in", "r", stdin);
	scanf("%d %d", &N, &N1);

	for (i = 0; i < N1; i++)
		scanf("%d %d", &L1[i].l1, &L1[i].l2), L1[i].med = (float)(L1[i].l1 + L1[i].l2) / 2;

	for (i = 1; i < N; i++)
	{
		scanf("%d", &N2);
		for (j = 0; j < N2; j++)
			scanf("%d %d", &L2[j].l1, &L2[j].l2), L2[j].med = (float)(L2[j].l1 + L2[j].l2) / 2;

		/*  interclasez lista mijloacele de pe nivelul superior cu lista limitelor caramizilor de jos  */
		l = 0; a = 0; b = 0;
		while (1)
		{
			if (a >= N1) break;

			if (L1[a].med <= L2[b].l1 || L1[a].med == L2[b].l2 || (b >= N2 && a < N1))
			{ printf("No\n"); return 0; }

			if (L1[a].med > L2[b].l1 && L1[a].med < L2[b].l2)
				a++;
			if (L1[a].med > L2[b].l2)
				b++;
		}

		memcpy(L1, L2, sizeof(L2)); N1 = N2;
	}

	printf("Yes\n");

	return 0;
}
