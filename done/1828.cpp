/*
 * ACM Timus Online
 * Approximation by a Progression
 *
 * soluție: http://en.wikipedia.org/wiki/Simple_linear_regression
 *          f(x) = alfa + beta * x (alfa e t[0], beta e rația)
 *          beta = cov(x, y)/var(x), alfa = ym - beta * xm
 *          xm și ym sunt mediile seriei (am presupus seria x ca fiind 0,1,2,...)
 */

#include <cstdio>

int N, Y[10000];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif

  int i;
  double xm = 0, ym = 0;
  
  scanf("%d", &N);

  for (i = 0; i < N; i++)
  {
    scanf("%d", &Y[i]);
    xm += (double)i;
    ym += (double)Y[i];
  }

  xm /= (double)N;
  ym /= (double)N;

  // calculez covarianța seriilor x cu y
  double alfa, beta;
  double cov_xy = 0, var_x = 0;

  for (i = 0; i < N; i++)
  {
    cov_xy += (i - xm) * (Y[i] - ym);
    var_x += (i - xm) * (i - xm);
  }
  if (var_x != 0)
  {
    beta = cov_xy / var_x;
    alfa = ym - beta * xm;
  }
  else
  {
    beta = 0;
    alfa = ym;
  }

  printf("%.6lf %.6lf\n", alfa, beta);

  return 0;
}
