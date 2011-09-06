/*
 * ACM Timus Online - Metro
 *
 * solution: DP -> A[i][j] -> optimal cost for reaching (i, j)
 */

#include <cstdio>
#include <cstring>

#define MAXN        1024
#define SQRT2       1.4142135623730950488
#define INF         1000000000000000.0
#define MIN(a, b)   ((a) > (b) ? (b) : (a))


int M, N, K;
char Q[MAXN][MAXN];
double A[2][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif
  scanf("%d %d %d", &M, &N, &K);

  int i, j;

  for (i = 0; i < K; i++)
  {
    int l, c;

    scanf("%d %d", &c, &l);
    Q[l - 1][c - 1] = 1;
  }

  // M, N squares -> M + 1, N + 1 points on grid.
  A[0][0] = 0;
  for (i = 1; i <= M; i++)
    A[0][i] = i * 100;

  for (i = 1; i <= N; i++)
  {
    A[1][0] = i * 100;
    for (j = 1; j <= M; j++)
    {
      A[1][j] = INF;

      // we can arrive diagonally at (i, j)
      if (Q[i - 1][j - 1])
        A[1][j] = MIN(A[1][j], A[0][j - 1] + 100 * SQRT2);
      
      // otherwise, we can come only from south or east
      A[1][j] = MIN(A[1][j], A[0][j] + 100);
      A[1][j] = MIN(A[1][j], A[1][j - 1] + 100);
    }
    memcpy(A[0], A[1], sizeof(A[1]));
  }

  printf("%.0lf\n", A[1][M]);

  return 0;
}
