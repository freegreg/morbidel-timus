/*
 * ACM Timus Online Judge
 * Ural Championship 2012 - Problem E
 * The Lessons of the Past
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define INPUT_FILE		"input.txt"
#define OUTPUT_FILE		"output.txt"
#define ABS(x)        ((x) > 0 ? (x) : -(x))
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define INF           1000000000

using namespace std;

int N;
vector<int> R, P;
struct interval
{
  int l, r;
};
vector<interval> L1, L2;
set<interval> V;


template <class T>
void sw(T &a, T &b)
{
  T c = a;
  a = b;
  b = c;
}

bool operator < (const interval &a, const interval &b)
{
  return (a.l < b.l || (a.l == b.l && a.r < b.r));
}

// solve b <= |x + a| <= c. answer is interval1 plus interval2
void SolveEq(int a, int b, int c, interval &i1, interval &i2)
{
  if (b < 0)
  {
    b = 0;
  }

  int aa, bb, cc, dd;
  // |x + a| <= c
  aa = c - a;
  bb = -c - a;
  if (aa > bb)
  {
    sw(aa, bb);
  }

  // |x + a| >= b
  cc = b - a;
  dd = -b - a;
  if (cc > dd)
  {
    sw(cc, dd);
  }

  // intersect [aa, bb] with [cc, dd]
  i1.l = aa;
  i1.r = cc;

  i2.l = dd;
  i2.r = bb;

  if (i1.r == i2.l)
  {
    i2.l = INF;
    i1.r = i2.r;
  }
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif

  cin >> N;

  R.resize(N);
  for (int i = 0; i < N; ++i)
  {
    P.push_back(i);
    cin >> R[i];
  }

  L1.clear();
  L2.clear();

  do
  {
    // process permutation in P
    // solve |...|X+R[P[0]]| + R[P[1]]| + ... + R[P[N - 1]| <= 1

    interval i1, i2;
    i1.l = 0;
    i1.r = 1;

    L1.clear();
    L1.push_back(i1);

    for (int i = 0; i < N; ++i)
    {
      L2.clear();
      for (int j = 0; j < L1.size(); ++j)
      {
        interval l = L1[j];

        SolveEq(-R[P[i]], L1[j].l, L1[j].r, i1, i2);

        L2.push_back(i1);
        if (i2.l != INF)
        {
          L2.push_back(i2);
        }
      }

      L1 = L2;
    }

    for (int i = 0; i < L1.size(); ++i)
    {
      V.insert(L1[i]);
    }
  }
  while (next_permutation(P.begin(), P.end()));

  printf("%d\n", V.size());
  set<interval>::iterator it;

  for (it = V.begin(); it != V.end(); ++it)
  {
    printf("%d %d\n", it->l, it->r);
  }

	return 0;
}