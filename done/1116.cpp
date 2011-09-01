/*
 *  ACM Timus Online
 *  Piecewise constant function - Problem 1116
 *
 *  solutie: retinem diferentele dintre intervalele 2 (adica zonele libere) si apoi le intersectam pe alea bune cu zonele astea
 */

#include <stdio.h>

#define MAXN 15001

int N, M, Num = 0, Ni = 0;
struct set
{
	short l, r, y;
} A[MAXN], B[MAXN], Sol[MAXN];



int cross(int l1, int r1, int l2, int r2)
{
	return !(r2 < l1 || l2 > r1);
}

int main()
{
	long i, j;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d %d %d", &A[i].l, &A[i].r, &A[i].y);

	scanf("%d", &M);
	for (i = 1; i <= M; i++)
		scanf("%d %d %d", &B[i].l, &B[i].r, &B[i].y);


	B[Ni].l = -32001; B[Ni++].r = M ? B[1].l : 32001;

	for (i = 2; i <= M; i++)
		if (B[i].l > B[i - 1].r)
			B[Ni].l = B[i - 1].r, B[Ni++].r = B[i].l;

	B[Ni].l = B[M].r; B[Ni++].r = 32001;

	for (i = j = 0; i < N; i++)
	{
		while (!cross(A[i].l, A[i].r, B[j].l, B[j].r) && A[i].l > B[j].r)
			j++;

		if (B[j].l >= A[i].l && B[j].r <= A[i].r)
			Sol[Num].y = A[i].y, Sol[Num].l = B[j].l, Sol[Num++].r = B[j].r, i--, j++;
		else
		if (B[j].l >= A[i].l && B[j].l <= A[i].r && B[j].r >= A[i].r)
			Sol[Num].y = A[i].y, Sol[Num].l = B[j].l, Sol[Num++].r = A[i].r;
		else
		if (A[i].l >= B[j].l && A[i].l <= B[j].r && A[i].r >= B[j].r)
			Sol[Num].y = A[i].y, Sol[Num].l = A[i].l, Sol[Num++].r = B[j].r, j++, i--;
		else
		if (A[i].l >= B[j].l && A[i].r <= B[j].r)
			Sol[Num].y = A[i].y, Sol[Num].l = A[i].l, Sol[Num++].r = A[i].r;
		if (Sol[Num - 1].l == Sol[Num - 1].r && Num > 0)
			Num--;
	}

	printf("%d\n", Num);
	for (i = 0; i < Num; i++)
		printf("%d %d %d\n", Sol[i].l, Sol[i].r, Sol[i].y);

	return 0;
}
