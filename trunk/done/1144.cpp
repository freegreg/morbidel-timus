/*
 *  ACM Timus Online
 *  Emperor's Riddle - Problem 1144
 *
 *  solutie: luate de pe forum si adaptata de Radu
 *  un greedy dubios... le sorteaza dupa marime...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10000
#define MMAX 1000
#define INF 666666666
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef int mang[NMAX+2];
typedef int mang1[NMAX+1];
typedef int mang2[NMAX+1];
typedef int mang3[15001];
typedef int mang4[NMAX+1];
typedef int heap_type[NMAX+1];

mang A, B, C, Cs, Kq, Sol;
mang1 Tt;
mang2 T;
mang3 D;
mang4 Chua;
heap_type heap;
int N, M, K, Max, Kl, S;
int Tong, Ct, Cd, Dich, Imin, Imax;
int Kt;
int S1, S2;

int _t;
#define swap(a, b) (_t = a, a = b, b = _t)

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int cmp2(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

void sort(mang a, int N, int d)
{
    int cacat[NMAX+1][2], i;
    for (i = 1; i <= N; i++)
        cacat[i-1][0] = a[i], cacat[i-1][1] = Cs[i];
    qsort(cacat, N, 2*sizeof(int), d ? cmp : cmp2);
    for (i = 1; i <= N; i++)
        a[i] = cacat[i-1][0], Cs[i] = cacat[i-1][1];
}

void init_cs()
{
    int i;
    for (i = 1; i <= N; i++) Cs[i] = i;
}

void print()
{
    int i;
    printf("%d\n", Kl);
    init_cs();
    sort(Sol, N, 0);
    for (i = 1; i <= N; i++)
    {
        printf("%d ", Cs[i]);
        if (Sol[i] != Sol[i+1]) printf("\n");
    }
}

void sort_a()
{
    memcpy(B, A, sizeof(A));
    init_cs();
    sort(A, N, 0);
    Kl = INF;
}

void init_tt()
{
    int i;
    for (i = 1; i <= M; i++) Tt[i] = i;
}
#define min(a, b) ((a) < (b) ? (a) : (b))
#define fiu (p = (2*i >= M || heap[2*i] < heap[2*i+1]) ? 2*i : 2*i+1)

void sift()
{
    int i, p;
    for (i = 1; fiu <= M && heap[p] < heap[i]; i = p)
    {
        swap(heap[i], heap[p]);
        swap(Tt[i], Tt[p]);
    }
}

void initheap()
{
    init_tt();
    memset(heap, 0, sizeof(heap));
    heap[0] = -1, Max = 0;
}


void greedy()
{
    int i;
    for (i = 1; i <= N; i++)
    {
        heap[1] += A[i];
        if (heap[1] > Max) Max = heap[1];
        Kq[Cs[i]] = Tt[1];
        sift();
    }
}

void update()
{
    if (Max - heap[1] < Kl)
    {
        Kl = Max - heap[1];
        memcpy(Sol, Kq, sizeof(Kq));
    }
}
/*
void shuffle()
{
    int i, a, b;
    for (i = 1; i <= N; i++)
    {
        a = rand()%N+1, b = rand()%N+1;
        swap(A[a], A[b]);
        swap(Cs[a], Cs[b]);
    }
}
   */
void get_t()
{
    int i;
    memset(T, 0, sizeof(T));
    for (i = 1; i <= N; i++)
        T[Sol[i]] += B[i];
}

void get_cd_ct()
{
    int i;
    Cd = INF, Ct = 0;
    for (i = 1; i <= M; i++)
    {
        if (Cd > T[i]) Cd = T[i], Imin = i;
        if (Ct < T[i]) Ct = T[i], Imax = i;
    }
    Tong = Cd+Ct;
    Dich = Tong/2;
    if (Kl > Ct-Cd) Kl = Ct-Cd;
}

void get_c()
{
    int i;
    for (S = 0, i = 1; i <= N; i++)
        if (Sol[i] == Imin || Sol[i] == Imax)
            C[++S] = B[i], Cs[S] = i;
}

void sort_c()
{
    sort(C, S, 1);
}

void meo_vat()
{
    int i;
    sort_c();
    S1 = S2 = 0;
    if (S >= 15)
    {
        for (i = S; i >= 15 /*S/20*/; i--)
            if (S1 <= S2)
                S1 += C[i], Sol[Cs[i]] = Imin;
            else
                S2 += C[i], Sol[Cs[i]] = Imax;
        S = 14; /*S/20-1*/
    }
    Dich = Tong/2 - S1;
}

void get_d()
{
    int i, j, max;
    memset(D, 0, sizeof(D));
    max = 0, D[0] = S+1;
    for (i = 1; i <= S; i++)
    {
        for (j = max; j >= 0; j--)
            if (D[j] > 0 && j+C[i] <= Dich && D[j+C[i]] == 0)
               D[j+C[i]] = i;
        max += C[i];
        if (max > Dich) max = Dich;
        if (D[Dich] == 1) break;
    }
    while (!D[Dich]) Dich--;
}

void updatekt()
{
    Kt = (Ct-Cd <= K);
}

void mumu()
{
    int i, j;
    for (i = 0; i <= NMAX; i++) Chua[i] = 1;
    i = Dich;
    do
    {
        j = D[i];
        Sol[Cs[j]] = Imin;
        Chua[j] = 0;
        i -= C[j];
    } while (D[i] != S+1);
    for (i = 1; i <= S; i++)
        if (Chua[i]) Sol[Cs[i]] = Imax;
    T[Imin] = Dich+S1;
    T[Imax] = Tong-T[Imin];
}

void cai_tien()
{
    get_t();
    do
    {
        get_cd_ct();
        get_c();
        if (Tong > 5000) meo_vat();
        get_d();
        updatekt();
        mumu();
    } while (!Kt);
}

void solve()
{
    initheap();
    greedy();
    update();
    if (Kl > K) cai_tien();
}


void read_data()
{
    int i;
    scanf("%d %d %d", &N, &M, &K);
    for (i = 1; i <= N; i++)
        scanf("%d", A+i);
}

int main()
{
//freopen("in", "rt", stdin);
    read_data();
    sort_a();
    solve();
    print();
    return 0;
}


