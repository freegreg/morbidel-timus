/*
 *  ACM Timus Online
 *  Stone Pile - Problem 1005
 *
 *  solutie: generam toate cfg
 */

#include <cstdio>

#define ABS(x) ((x) > 0 ? (x) : -(x))

int V[20];
int N, S;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif

  S = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", V + i);
    S += V[i];
  }

  int minDif = 1000000;

  for (int i = 0; i < (1 << (N - 1)); ++i)
  {
    int cur_sum = 0;

    for (int j = 0; j < N - 1; ++j)
      if (i & (1 << j))
      {
        cur_sum += V[j];
      }
    if (ABS(S - 2 * cur_sum) < minDif)
    {
      minDif = ABS(S - 2 * cur_sum);
    }
  }

  printf("%d", minDif);

  return 0;
}