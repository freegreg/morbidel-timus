/*
 *  ACM Timus - Goat in the Garden 5
 */

#include <stdio.h>

#define MAXN 1024

int N;
struct point
{
	double x, y;
} P[MAXN];
double BestArea;
int First[MAXN], Second[MAXN];


void Readdata()
{
	int i;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);
}

void Solve()
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
}


int main()
{
	Readdata();
	Solve();

	return 0;
}
