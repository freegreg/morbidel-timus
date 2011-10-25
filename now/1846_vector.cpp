/*
 * ACM Timus
 * Problem 1846 - GCD 2010
 */

#include <cstdio>
#include <algorithm>
#include <vector>

int N;
std::vector<int> V, O;          // values, operations (translate all 10k longs in an integer 0..10k)
std::vector<short> F, Pos;      // F[i] is the frequency of V[i], Pos[i] is the position in V of i-th operation


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
  int res = -1;
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

short GetIndex(int long_value)
{
  std::vector<int>::iterator pos = lower_bound(V.begin(), V.end(), long_value);

  if (pos != V.end())
    return pos - V.begin();
  else
    return -1;
}

int main()
{
  //gen();
  char ch;
	int i, j, n, res = -1, pos;


#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	scanf("%d\n", &N);

  O.resize(N);
  Pos.resize(N);
  F.resize(N, 0);
  
	for (i = 0; i < N; i++)
	{
		scanf("%c %d\n", &ch, &n);

    O[i] = (ch == '+') ? n : -n;
    if (ch == '+')
      V.push_back(n);
	}

  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end() ), V.end());

  for (i = 0; i < N; i++)
  {
    Pos[i] = (O[i] > 0) ? GetIndex(O[i]) : GetIndex(-O[i]);

    pos = Pos[i];
    if (O[i] > 0)
    {
      F[pos]++;

      if (F[pos] == 1)
      {
        res = (res == -1) ? O[i] : gcd(res, O[i]);
      }
    }
    else
    {
      F[pos]--;

      if (F[pos] == 0)
      {
        res = -1;
        for (j = 0; j < i; j++)
          if (F[Pos[j]] > 0)
          {
            res = (res == -1) ? V[Pos[j]] : gcd(res, V[Pos[j]]);
          }
      }
    }

    if (res == -1)
      printf("1\n");
    else
      printf("%d\n", res);
  }

	return 0;
}

