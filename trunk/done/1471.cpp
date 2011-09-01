/*
 * ACM Timus Online
 * Tree - Problem 1471
 *
 * soluție: țin un W[i] cu costul de la nodul i la rădăcină, care-l calculez în O(N). 
 *          Apoi query(p, q) = W[p] + W[q] - 2*W[lca(p, q)]
 *          lca(p, q) cu http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor#Another easy solution in O(N logN, O(logN)
 *          (vezi și strămoși de la InfoArena pt aceeași idee dar implementată mai aiurea :)
 */

#include <cstdio>
#include <cstring>
#include <list>
#include <vector>

#define MAXN          65536
#define LOGMAXN       16
#define INF           1000000
#define min(a, b)     ((a) > (b) ? (b) : (a))
#define max(a, b)     ((a) > (b) ? (a) : (b))

struct node
{
	int w, nod;

  node(int ww, int nnod)
  {
    w = ww;
    nod = nnod;
  }
};

int N, M;
std::list<node> A[MAXN];
int W[MAXN], L[MAXN];
bool Flag[MAXN];
int P[MAXN][LOGMAXN];       // p[i][j] = 2^j strămoș al lui i
int T[MAXN];


void DF(int nod)
{
  std::list<node>::iterator it;

  Flag[nod] = true;
  for (it = A[nod].begin(); it != A[nod].end(); it++)
    if (!Flag[it->nod])
    {
      T[it->nod] = nod;
      L[it->nod] = L[nod] + 1;
      W[it->nod] = W[nod] + it->w;

      DF(it->nod);
    }
}

void Preprocess()
{
  L[0] = 0;
  T[0] = -1;

  // atârn arborele de 0 ca să obțin tată->fiu
  DF(0);

  int i, j;

  // iniț
  for (i = 0; i < N; i++)
    for (j = 0; 1 << j < N; j++)
      P[i][j] = -1;

  for (i = 0; i < N; i++)
    P[i][0] = T[i];

  for (j = 1; 1 << j < N; j++)
    for (i = 0; i < N; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}

int lca(int p, int q)
{
  int tmp, log, i;

  if (L[p] < L[q])
    tmp = p, p = q, q = tmp;

  for (log = 1; 1 << log <= L[p]; log++);
  log--;
  
  for (i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];

  if (p == q)
    return p;

  for (i = log; i >= 0; i--)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
    {
      p = P[p][i];
      q = P[q][i];
    }

  return T[p];
}


int main()
{
  int i, n1, n2, w;
  
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif
  scanf("%d", &N);

  for (i = 0; i < N - 1; i++)
  {
    scanf("%d %d %d", &n1, &n2, &w);
    A[n1].push_back(node(w, n2));
    A[n2].push_back(node(w, n1));

    Flag[n1] = Flag[n2] = false;
  }

  Preprocess();

  // query-urile
  scanf("%d", &M);

  for (i = 0; i < M; i++)
  {
    scanf("%d %d", &n1, &n2);
    //printf("lca(%d, %d) = %d\n", n1, n2, lca(n1, n2));
    printf("%d\n", W[n1] + W[n2] - 2 * W[lca(n1, n2)]);
  }

	return 0;
}
