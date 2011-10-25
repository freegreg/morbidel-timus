/*
 * ACM Timus
 * Problem 1846 - GCD 2010
 *
 * solution: recompute gcd for all set only when one number completly dissappears from the set.
 *            When the collection remains empty, signal it somehow, for the next insert to know.
 */

#include <cstdio>
#include <map>

int N;
std::map<int, short> M;


int gcd(int a, int b)
{
  int t;
  while (b > 0)
  {
    t = a;
    a = b;
    b = t % b;
  }
  return a;
}

int ComputeGCD()
{
  std::map<int, short>::iterator it;
  int res = -1;

  for (it = M.begin(); it != M.end(); it++)
    if (it->second > 0)
    {
      res = (res == -1) ? it->first : gcd(res, it->first);
    }

  return res;
}

void gen()
{
  int i, n = 5000;

  FILE *f = fopen("input.txt", "wt");
  fprintf(f, "%d\n", 2 * n);
  /*for (i = 1; i <= n; i++)
    fprintf(f, "+ %d\n- %d\n", i, i);*/
  for (i = 1; i <= n; i++)
    fprintf(f, "+ %d\n", i);
  for (i = 1; i <= n; i++)
    fprintf(f, "- %d\n", n - i + 1);
  fclose(f);
}

int main()
{
  //gen();
  char ch;
	int i, n, res = -1;


#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	scanf("%d\n", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%c %d\n", &ch, &n);

		if (ch == '+')
		{
			++M[n];
      if (M[n] == 1)
      {
        // if a new number arrives the new gcd is simple to compute
        res = (res == -1) ? n : gcd(res, n);
      }
		}
		else
		{
			--M[n];

      if (M[n] == 0)
      {
        // if n is no more in the collection, then we recalculate all gcd-s
        res = ComputeGCD();
      }
		}

    if (res == -1)
      printf("1\n");
    else
      printf("%d\n", res);
	}

	return 0;
}
