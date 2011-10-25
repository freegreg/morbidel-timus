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
void GetSolutions(int n, std::vector<point> &v)
{
  int i, j;

  v.clear();
  for (i = 0; i * i <= n; i++)
  {
    j = (int) sqrtl(n - i * i);

    if (i <= j && j * j + i * i == n)
    {
      v.push_back(point(i, j));
      v.push_back(point(-i, j));
      v.push_back(point(i, -j));
      v.push_back(point(-i, -j));

      if (i != j)
      {
        v.push_back(point(j, i));
        v.push_back(point(-j, i));
        v.push_back(point(j, -i));
        v.push_back(point(-j, -i));
      }
    }
  }
}

// Determină punctele 3..N-1 pe baza p0, p1, p2. Întoarce true/false dacă e sau nu soluție
bool ComputePoints()
{
  int i, j, k;
  std::vector<point> s;

  for (i = 3; i < N; i++)
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
        if (ComputePoints())
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
  n = 100;

  fprintf(f, "%d\n", n);
  for (i = 0; i < n; i++)
  {
    int x = (rand() % 31100) - 15500;
    int y = (rand() % 200) - 100;
    x = -15500 + (double)i * 313.13131313;
    y = 1000000;

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

int main()
{
  srand(time(NULL));
  //gen();

#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif
  int i, j;

  scanf("%d", &N);

  if (N > 90)
    while(1);
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    {
      scanf("%d", &D[i][j]);
    };

  if (Solve() == 0)
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
