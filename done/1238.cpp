/*
 * ACM Timus Online
 * Folding - Problem 1238
 *
 * soluție: PD -> A[i][j] = minim de caractere pt a foldui secvența [i, j]
 */

#include <cstdio>
#include <cstring>
#include <list>
#include <string>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int N;
char S[101];
int A[101][101];
struct grupa
{
  // k caractere, g grupe
  int k, g;

  grupa()
  {
    k = g = 0;
  }
  grupa(int kk, int gg)
  {
    k = kk;
    g = gg;
  }
};
std::list<grupa> P[101];  // P[i] -> listă cu perechi valide de (k, g) pt poziția i
grupa Sol[101][101];


int cifre(int n)
{
  int c = 0;

  while (n > 0)
  {
    c++;
    n /= 10;
  }
  return c;
}

std::string Recurse(int l, int r)
{
  std::string s = "";
  grupa x = Sol[l][r];
  int i;

  if (l > r)
  {
    return s;
  }

  // caractere la început?
  int cnt = r - l + 1 - x.k * x.g;
  int start_gr = l + cnt;

  if (l == r)
  {
    s += S[r];
    return s;
  }
  
  // ce e negrupat
  if (x.k == 1 && x.g == 1)
  {
    s += Recurse(l, r - 1) + S[r];
    return s;
  }
  else if (cnt > 0)
  {
    s += Recurse(l, l + cnt - 1);
  }

  // acum grupele
  if (x.g == 1)
  {
    // grupa a fost sub-folduită?
    if (A[start_gr][start_gr + x.k - 1] < x.k)
    {
      s += Recurse(start_gr, start_gr + x.k - 1);
    }
    else
    for (i = start_gr; i < start_gr + x.k; i++)
    {
      s += S[i];
    }

  } else
  {
    char sz[16];

    sprintf(sz, "%d", x.g);

    // recursiv pt grupa 1 din set
    s += std::string(sz) + '(' + Recurse(start_gr, start_gr + x.k - 1) + ')';
  }

  return s;
}

void Solve()
{
  int i, j, k, m;

  // preprocesare - calculez P[1..N - 1]
  P[0].clear();
  for (i = 1; i < N; i++)
  {
    for (k = 1; 2 * k <= i + 1; k++)
    {
      int c, g = 100000;                              // g e minimul lungimilor ciclurilor

      for (j = i; j >= i - k + 1; j--)                // pt fiecare caracter din cele k văd câte în spate din k în k sunt egale
      {
        c = 0;                                        // lungimea ciclului curent
        for (m = j; m >= 0; m -= k, c++)
          if (S[m] != S[j])
          {
            break;
          }
        if (c < g)
        {
          g = c;
        }
      }
      if (g > 1 && k * g >= 5)                        // len 5 e min pt care merită să fold (aaaa -> 4(a) - tot 4 char, dar aaaaa -> 5(a) - 4 char)
      {
        P[i].push_back(grupa(k, g));
      }
    }
  }

  // PD
  memset(A, sizeof(A), 0);

  // init: A[i][i] = 1
  for (i = 0; i < N; i++)
  {
    A[i][i] = 1;
  }

  for (i = 1; i < N; i++)
    for (j = 0; j + i < N; j++)
    {
      // calculez a[j][j+i]
      // merg prin lista de (k, g) pt poziția j+i
      std::list<grupa>::iterator it;

      int sol = 10000, val1, val2, cost;

      for (it = P[i + j].begin(); it != P[i + j].end(); it++)
      {
        int g;
        grupa x = *it;

        // verific pt fiecare grupă, dacă nu iese înafara intervaluli [j, j+i] adică dacă nu iese sub j
        // nu are sens să testez g = 1 deoarece nu implică folding, iar fără folding testez oricum
        for (g = 1; g <= x.g; g++)
        {
          if (j + i - x.k * g < j - 1)                // g grupe e prea mult?
          {
            break;
          }

          int lim = j + i - x.k * g;                  // cât se întind cele g grupe

          // cele x.k caractere poate au fost la rândul lor restrânse la ceva optim -> verifică
          int cost2 = A[j + i - x.k + 1][j + i];      // hah!

          if (cost2 == 0)                             // nesetat, probabil se calculează acum și am g == 1
          {
            cost2 = x.k;
          }

          // am varianta să strâng x.k * g caractere în cifre(g) + 2 + x.k => e mai bine?
          val1 = cifre(g) + 2 + cost2;                // fold
          val2 = cost2 * g;                           // kein fold

          cost = MIN(val1, val2);
          if (lim >= 0)
          {
            cost += A[j][lim];
          }

          if (cost < sol)                             // <= :)
          {
            Sol[j][j + i] = grupa(x.k, g);          // grupa cu care am optimizat aici
            sol = cost;
          }
        }
      }

      // pe lângă grupe, poate e mai optim să nu-l combin de loc
      if (A[j][j + i - 1] + 1 < sol || sol == 10000)
      {
        sol = A[j][j + i - 1] + 1;
        Sol[j][j + i] = grupa(1, 1);
      }
      A[j][j + i] = sol;
    }

  // soluția
  std::string sol = Recurse(0, N - 1);
#ifndef ONLINE_JUDGE
  printf("sol.size() = %d\nA[0][N-1] = %d\n", sol.size(), A[0][N - 1]);
#endif

  printf("%s\n", sol.c_str());
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif
  scanf("%s", &S);
  N = strlen(S);

  Solve();

  return 0;
}

