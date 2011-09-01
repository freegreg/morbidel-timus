/*
 *  ACM Timus Online
 *  Electric Path - Problem 1143
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXN 300

int N, hn, Flag[MAXN], S[MAXN], Last[MAXN];
double Len, MLen;
double M[MAXN][MAXN];
struct point
{
	double x, y;
} P[MAXN];



void readdata()
{
	int i;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);
}

double dist(point a, point b)
{
	return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

/*void back(int l)
{
	int i;

	if (l == N + 1)
	{
		Len = 0;
		for (i = 1; i < N; i++)
			Len += A[S[i]][S[i + 1]];
		if (Len < MLen)
		{
			MLen = Len;
			for (i = 1; i <= N; i++) printf("%d ", S[i]);
			printf("\nCost = %.3lf\n\n", MLen);
			memcpy(Last, S, sizeof(S));
		}
	} else
	for (i = 1; i <= N; i++)
		if (!Flag[i])
			Flag[i] = 1, S[l] = i, back(l + 1), Flag[i] = 0;
}

void brute_solve()
{
	MLen = 1e9;
	back(1);
	printf("%.3lf\n", MLen);
}*/

#define next(n) (1 + n % N)
#define prev(n) (n - 1 == 0 ? N : n - 1)


void go(int node, int links)
{
	int k;

	Flag[node] = 1;

	if (links == N)
	{
		/*for (k = node; k != -1; k = Last[k])
			printf("%d ", k);
		printf("\nCost = %.3lf\n\n", M[node][links - 1]);*/
	} else
	{
		k = next(node);
		while (Flag[k]) k = next(k);

		if (M[node][links - 1] + dist(P[node], P[k]) < M[k][links])
		{
			M[k][links] = M[node][links - 1] + dist(P[node], P[k]), Last[k] = node;
			go(k, links + 1);
		}

		k = prev(node);
		while (Flag[k]) k = next(k);

		if (M[node][links - 1] + dist(P[node], P[k]) < M[k][links])
		{
			M[k][links] = M[node][links - 1] + dist(P[node], P[k]), Last[k] = node;
			go(k, links + 1);
		}
	}
	Flag[node] = 0;
}

void DP()
{
	int i, k;


	MLen = 1e9;

	for (k = 1; k <= N; k++) // start node
	{
		memset(Flag, 0, sizeof(Flag));
		memset(Last, 0, sizeof(Last));
		memset(M, 100, sizeof(M));

		M[k][0] = 0;
		Last[k] = -1;
		go(k, 1);

		for (i = 1; i <= N; i++)
			if (i != k && M[i][N - 1] < MLen)
				MLen = M[i][N - 1];
	}

	printf("%.3lf\n", MLen);
}

void solve()
{
	/*int i, j;

	for (i = 1; i <= N; i++)
		for (j = i + 1; j <= N; j++)
			A[i][j] = A[j][i] = dist(P[i], P[j]);

	/*N = 200;

	for (i = 1; 4 * i <= N; i++)
	{
		double alpha = (i - 1) * (3.14159265258979323846264338 / 2 / (N / 4));
		double x, y, R = 1000;

		x = R * cos(alpha);
		y = R * sin(alpha);
		printf("%.3lf %.3lf\n", x, y);
		printf("%.3lf %.3lf\n", -x, y);
		printf("%.3lf %.3lf\n", x, -y);
		printf("%.3lf %.3lf\n", -x, -y);
	}*/
	//brute_solve();
	DP();
}


int main()
{
	readdata();
	solve();

	return 0;
}

