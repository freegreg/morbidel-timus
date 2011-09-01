/*
 *  ACM Timus Online
 *  Construction - Problem 1359
 */

#include <stdio.h>
#include <math.h>

#define G 10.0
#define INF 1e10
#define min(a, b) ((a) > (b) ? (b) : (a))
#define sqr(x) ((x) * (x))

int M, N;
double T[51][51], V[51][51];



int main()
{
	int i, j, k, l;
	double a, d, dE, t1, t2, v1, v2;


	scanf("%d %d", &M, &N);

	for (i = 0; i <= M; i++)
		for (j = 0; j <= N; j++)
			T[i][j] = INF;

	V[0][0] = T[0][0] = 0;

	for (i = 0; i <= M; i++)
		for (j = 0; j <= i; j++) /* plec din (i, j) in (k, l) */
			for (k = i + 1; k <= M; k++)
				for (l = j; l <= N; l++)
					if (k != i || l != j)
					{
						dE = sqrtl(sqr(k - i) + sqr(l - j));

						d = sqrtl(1 + dE * dE);
						a = G * dE / d;

						t1 = T[i][j];
						v1 = V[i][j];

						t2 = (a * t1 - v1 + sqrtl(v1 * v1 + 2 * a * d - a * a * t1 * t1)) / a;
						v2 = v1 + a * (t2 - t1);

						if (t2 < T[k][l])
							T[k][l] = t2, V[k][l] = v2;
					}

	printf("%.4f\n", T[M][N]);


	return 0;
}
