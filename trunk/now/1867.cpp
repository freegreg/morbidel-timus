/*
 * ACM Timus Online
 * Problem 1867 - Nanotechnologies
 */

#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define SQR(n)    ((n) * (n))
#define ABS(n)    ((n) > 0 ? (n) : -(n))

int N;
int D[100][100];
struct point
{
  int x, y;
  point()
  {
    x = y = 0;
  }
  point(int xx, int yy)
  {
    x = xx;
    y = yy;
  }
};
std::vector<point> P;

// scoate perechile (+-i, +-j) cu i^2 + j^2 = n
int GetSolutions(int n, std::vector<point> &v)
{
  int i, j, sol = 0;

  v.clear();
  for (i = 0; i * i <= n; i++)
  {
    j = sqrtl(n - i * i);

    if (i <= j && j * j + i * i == n)
    {
      sol += 4;
      v.push_back(point(i, j));
      v.push_back(point(-i, j));
      v.push_back(point(i, -j));
      v.push_back(point(-i, -j));

      if (i != j)
      {
        sol += 4;
        v.push_back(point(j, i));
        v.push_back(point(-j, i));
        v.push_back(point(j, -i));
        v.push_back(point(-j, -i));
      }
    }
  }

  return sol;
  /*
  signed x = 0;
  signed m = sqrtl(n / 2);
  for (signed y = sqrtl(n); y >= m; y--)
  {
    unsigned _y = y * y;
    while (x * x + _y < n)
    {
      x++;
    }
    if (x * x + _y == n)
    {
      // valid (x, y)
      v.push_back(point(x, y));
      v.push_back(point(-x, y));
      v.push_back(point(x, -y));
      v.push_back(point(-x, -y));

      if (x != y)
      {
        v.push_back(point(y, x));
        v.push_back(point(-y, x));
        v.push_back(point(y, -x));
        v.push_back(point(-y, -x));
      }
    }
  }*/
}

// Determină punctele p..N-1 pe baza p0, p1, p2. Întoarce true/false dacă e sau nu soluție
bool ComputePoints(int p)
{
  int i, j, k;
  std::vector<point> s;

  for (i = p; i < N; i++)
  {
    int d;
    bool sol = false;
    // pt orice alt P[i], luăm toate soluțiile care respectă di0 și apoi le verificăm pe cele către
    // 1..i-1

    GetSolutions(D[i][0], s);

    for (j = 0; j < s.size(); j++)
    {
      // verific dacă candidatul la soluție s[j] e valabil
      bool valid = true;
      for (k = 1; k < i; k++)
      {
        // verificare cu 1..i-1
        d = SQR(s[j].x - P[k].x) + SQR(s[j].y - P[k].y);

        if (d != D[i][k])
        {
          valid = false;
          break;
        }
      }

      if (valid)
      {
        sol = true;
        P[i] = s[j];

        // Aici e problema din care iau WA8. Mă opresc la prima soluție, când ea poate să nu fie cea bună în final
        // Când am N-1 puncte colineare, al N-lea nu mai e unic determinat deci e greșit să mă
        // opresc la prima soluție.
        break;
      }
    }

    // nicio soluție pt P[i] -> Impossible
    if (!sol)
    {
      return false;
    }
  }

  return true;
}

int Solve()
{
  int i, j;
  std::vector<point> s1, s2, sol;

  P.resize(N);
  // P[0] e mereu (0, 0)
  P[0] = point(0, 0);

  // P[1] e oricare punct care verifică d10
  GetSolutions(D[1][0], s1);

  if (N == 2)
  {
    if (s1.size() > 0)
    {
      P[1] = s1[0];
    }
    return  (s1.size() > 0);
  }

  // pentru P[2] luăm iarăși orice soluție respectă d20 și d21
  // din toate combinațiile curente de p1, p2 vedem dacă am soluție pt restul de puncte
  for (i = 0; i < s1.size(); i++)
  {
    GetSolutions(D[2][0], s2);

    for (j = 0; j < s2.size(); j++)
    {
      int d = SQR(s2[j].x - s1[i].x) + SQR(s2[j].y - s1[i].y);

      if (d == D[2][1])
      {
        P[1] = s1[i];
        P[2] = s2[j];

        // s1[i] și s2[j] sunt puncte valide
        if (ComputePoints(3))
        {    
          return 1;
        }
      }
    }
  }

  return 0;
}

void gen()
{
  int i, j, n;
  std::vector<point> p;
  
  FILE *f = fopen("input.txt", "wt");
  n = 10;

  fprintf(f, "%d\n", n);
  for (i = 0; i < n; i++)
  {
    int x = (rand() % 20) - 10;
    int y = (rand() % 20) - 10;
    y = 0;

    p.push_back(point(x, y));
    printf("P[%d] = (%d, %d)\n", i, x, y);
  }

  for (i = 0; i < n; i++, fprintf(f, "\n"))
    for (j = 0; j < n; j++)
    {
      int d = SQR(p[i].x - p[j].x) + SQR(p[i].y - p[j].y);

      if (d > 1000000000)
      {
        printf("ERROR: distance too big between %d and %d\n", i, j);
      }
      fprintf(f, "%d ", d);
    }

  fclose(f);
}

// verifică dacă punctele 0..n-1 din P sunt colineare
bool Collinear(int n)
{
  int i;

  // Primele două nu contează, pornim din al treilea.
  for (i = 2; i < n; i++)
  {
    // determinantul P[0], P[1] și P[i] tre să dea 0
    if ((P[1].x - P[0].x) * (P[i].y - P[0].y) !=
        (P[i].x - P[0].x) * (P[1].y - P[0].y))
    {
      return false;
    }
  }

  return true;
}

int back(int p)
{
  int i, j;
  bool colin = Collinear(p - 1);
  
  if (p == N)
  {
    // soluție!
    return 1;
  }
  else
  {
    if (!colin)
    {
      // non-coliniare, soluția e unică! (oare?)
      bool sol = ComputePoints(p);

      return sol;
    }
    std::vector<point> v;

    GetSolutions(D[0][p], v);

    // verific toate potențialele soluții pt punctul p cu punctele 1..p-1
    for (i = 0; i < v.size(); i++)
    {
      bool valid = true;

      for (j = 1; j < p; j++)
      {
        int d = SQR(P[j].x - v[i].x) + SQR(P[j].y - v[i].y);

        if (d != D[j][p])
        {
          valid = false;
          break;
        }
      }

      if (valid)
      {
        P[p] = v[i];

        if (back(p + 1))
        {
          return 1;
        }
      }
    }
  }

  return 0;
}

int BruteForce()
{
  P.resize(N);
  // P[0] e mereu (0, 0)
  P[0] = point(0, 0);

  return back(1);
}


int main()
{
  srand(time(NULL));

#ifndef ONLINE_JUDGE
  gen();
  freopen("input.txt", "rt", stdin);
#endif
  int i, j;

  scanf("%d", &N);

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    {
      scanf("%d", &D[i][j]);
    };

  if (BruteForce() == 0)
  {
    printf("Impossible\n");
  }
  else
  {
    for (i = 0; i < N; i++)
    {
      printf("%d %d\n", P[i].x, P[i].y);

      // probă 1 - overflow
      if (ABS(P[i].x) > 1000000 || ABS(P[i].y) > 1000000)
      {
        printf("ERROR: overflow\n");
        while (1);
      }
    }

    // probă 2 - distanțe
    for (i = 0; i < N; i++)
      for (j = i + 1; j < N; j++)
      {
        int d = SQR(P[i].x - P[j].x) + SQR(P[i].y - P[j].y);

        if (d != D[i][j])
        {
          printf("ERROR: D[%d][%d] is wrong.\n", i, j);
          while (1);
        }
      }

  }

  return 0;
}
