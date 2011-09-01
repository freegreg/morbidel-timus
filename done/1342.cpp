/*
 *  ACM Timus Online
 *  Enterprise - Problem 1342
 *
 *  solutie: A[i][j] -> optim for i workshops and j brooms
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010
#define INF  666666666666

bool bSchedule = true;
int N, M;
struct Workshop
{
	short K;
	float P, Q;
} W[MAXN];

float A[2][MAXN];



float Brooms(int i, int k)
{
	return (k > W[i].K) ? INF : ((W[i].K == 1) ? W[i].P : (k * W[i].P + (W[i].Q - W[i].P) * k * (k - 1) / 2 / (W[i].K - 1)));
}

void readdata()
{
	int i, cnt = 0;

	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%d %f %f", &W[i].K, &W[i].P, &W[i].Q);

		cnt += W[i].K;
	}

	if (cnt < M)
		M = cnt, bSchedule = false;
}

void solve()
{
	float min, now;
	int i, j, k;

	for (i = 1; i <= M; i++)
	{
		A[0][i] = Brooms(0, i);
		A[1][i] = INF;
	}

	for (i = 1; i < N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			min = INF;

			for (k = 0; k <= W[i].K; k++)
				if ((now = A[0][j - k] + Brooms(i, k)) < min)
					min = now;
			A[1][j] = min;
		}
		for (j = 0; j <= M; j++)
			A[0][j] = A[1][j], A[1][j] = INF;
	}

	if (!bSchedule)
		printf("Maximum possible amount: %d\n", M);

	printf("Minimum possible cost: %.2f\n", A[0][M]);
}

int main()
{
	readdata();
	solve();

	return 0;
}
