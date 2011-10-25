/*
 * ACM Timus
 * Problem 1846 - GCD 2010
 */

#include <cstdio>
#include <map>
#include <vector>

int N;
std::map<int, short> M;
std::vector<int> Op;
std::vector<int> R;


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
      if (res == 1)
        break;
    }

  return res;
}

int ComputeGCD(int pos)
{
  int i, res = -1;

  for (i = 0; i < pos; i++)
    if (Op[i] > 0)
      res = (res == -1) ? Op[i] : gcd(res, Op[i]);

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
    fprintf(f, "+ %d\n", 199999 * i);
  for (i = 1; i <= n; i++)
    fprintf(f, "- %d\n", 199999 * i);
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

  Op.resize(N);
  R.resize(N);

	for (i = 0; i < N; i++)
	{
		scanf("%c %d\n", &ch, &n);

    Op[i] = (ch == '+') ? n : -n;

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
        int p = 0;
        for (j = i; j >= 0; j--)
        {
          if (Op[j] == -n)
            p--;
          else if (Op[j] == n)
            p++;
          if (p == 0)
            break;
        }
        // before j we don't care about the removal of n. Re-use the value R[j] for computing GCD
        res = -1;
        if (j > 0)
          res = R[j - 1];
        
      }
		}

    if (res == -1)
      printf("1\n");
    else
      printf("%d\n", res);
    R[i] = res;
	}

	return 0;
}
