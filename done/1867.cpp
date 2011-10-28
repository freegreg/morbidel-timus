/*
 * ACM Timus Online
 * Problem 1867 - Nanotechnologies
 *
 * Soluție: știind distanța dintre două puncte și cu un punct fixat, pot obține toate potențialele
 * soluții pentru al doilea punct (toate triunghiurile cu ipotenuza dată). Backtracking încercând
 * toate aceste soluții, cu mențiunea că atunci când am 3 puncte necolineare, nu mai am nicio axă de
 * simetrie deci pot determina restul punctelor în mod unic. Altfel, dacă am un set de puncte
 * colineare, trebuie backtracking.
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
      if (i != 0)
        v.push_back(point(-i, j));
      if (j != 0)
        v.push_back(point(i, -j));
      if (i != 0 && j != 0)
        v.push_back(point(-i, -j));

      if (i != j)
      {
        sol += 4;
        v.push_back(point(j, i));
        if (j != 0)
          v.push_back(point(-j, i));
        if (i != 0)
          v.push_back(point(j, -i));
        if (i != 0 && j != 0)
          v.push_back(point(-j, -i));
      }
    }
  }

  return sol;
}

bool Collinear(point &p1, point &p2, point &p3)
{
  return (p2.x - p1.x) * (p3.y - p1.y) == (p3.x - p1.x) * (p2.y - p1.y);
}

// verifică dacă punctele 0..n-1 din P sunt colineare
bool Collinear(int n)
{
  int i;

  // Primele două nu contează, pornim din al treilea.
  for (i = 2; i < n; i++)
  {
    // determinantul P[0], P[1] și P[i] tre să dea 0
    if (!Collinear(P[0], P[1], P[i]))
    {
      return false;
    }
  }

  return true;
}

// verifică dacă noul punct p candidat pt P[n] respectă distanțele către 0..n-1
bool Valid(point p, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (SQR(p.x - P[i].x) + SQR(p.y - P[i].y) != D[i][n])
    {
      return false;
    }
  }

  return true;
}

bool ComputePoint(int a, int b, int c, int n)
{
  int i;
  std::vector<point> v;

  // soluții valide spre pct 0
  GetSolutions(D[0][n], v);

  for (i = 0; i < v.size(); i++)
  {
    int d1, d2;

    d1 = SQR(P[b].x - v[i].x) + SQR(P[b].y - v[i].y);
    d2 = SQR(P[c].x - v[i].x) + SQR(P[c].y - v[i].y);

    if (d1 != D[b][n] || d2 != D[c][n])
    {
      v.erase(v.begin() + i);
      // continui cu i-ul curent
      --i;
    }
  }

  if (v.size() != 1)
  {
    return false;
  }

  P[n] = v[0];

  return true;
}

// Determină restul de puncte începând cu p pe baza a 3 pt fixe, necolineare (pentru ca soluția să
// fie unică, nefiind nicio axă de simetrie).
bool ComputePoints(int p)
{
  int i, k;
  std::vector<point> s;

  for (k = 2; k < p; k++)
  {
    // determinantul P[0], P[1], P[k] != 0
    if (!Collinear(P[0], P[1], P[k]))
    {
      // am găsit 3 necolineare: 0, 1, k
      break;
    }
  }

  if (k == p)
  {
    // nu ar trebui să se întâmple și să fi găsit mereu 3 pct necolineare.
    while (1);
  }

  for (i = p; i < N; i++)
  {
    // calculez P[i] funcție de P[0], P[1], P[k]. Trebuie să fie unic determinat.
    if (!ComputePoint(0, 1, k, i))
    {
      // P[i] nu e unic sau nu l-am putut determina.
      return false;
    }

    // îl verific acum contra celorlalte puncte
    if (!Valid(P[i], i))
    {
      return false;
    }
  }

  return true;
}

void ArrangePoints(std::vector<point> &v)
{
  int i, pos = 0;
  point tmp;

  for (i = 2; i < v.size(); i++)
  {
    if (Collinear(P[0], P[1], v[i]))
    {
      tmp = v[pos];
      v[pos] = v[i];
      v[i] = tmp;

      pos++;
    }
  }
}

int back(int p)
{
  int i;
 
  if (p == N)
  {
    // soluție!
    return 1;
  }

  if (!Collinear(p))
  {
    // punctele 0..p-1 nu sunt colineare deci cel putin 3 din ele nu sunt colineare. Le caut și cu
    // ajutorul lor generez soluțiile unice pt restul de puncte.
    bool sol = ComputePoints(p);
    return sol;
  }
  
  // colineare -> am încă simetrie deci soluția nu e unică. Continuăm cu backtracking...
  std::vector<point> v;

  GetSolutions(D[0][p], v);

  // Pun punctele colineare cu 0 și 1 în față în v, pentru a ajunge mai rapid la soluția când toate
  // sunt colineare (cazul cel mai defavorabil pt că trebuie să mergem adânc în back).
  if (p > 1)
  {
    ArrangePoints(v);
  }

  // verific toate potențialele soluții pt punctul p cu punctele 1..p-1
  for (i = 0; i < v.size(); i++)
  {
    bool valid = Valid(v[i], p);

    if (valid)
    {
      P[p] = v[i];
      if (back(p + 1))
      {
        return 1;
      }
    }
  }

  return 0;
}

int Solve()
{
  P.resize(N);
  
  // P[0] e mereu (0, 0)
  P[0] = point(0, 0);

  return back(1);
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
    int x = (rand() % 20000) - 10000;
    int y = (rand() % 20000) - 10000;

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
