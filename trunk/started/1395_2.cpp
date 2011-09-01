/*
 *  ACM Timus Online Judge
 *  Pascal vs. C++. Version 2
 */

#include <stdio.h>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>

#define MAXN			10001
#define INPUT_FILE		"input.txt"
#define ABS(x)			((x) > 0 ? (x) : -(x))
#define MAX(a, b) 		((a) > (b) ? (a) : (b))
#define MIN(a, b) 		((a) < (b) ? (a) : (b))
#define getheight(n)	(n->height = MAX(n->l->height, n->r->height) + 1)

using namespace std;


int N, NR;
struct node	
{
    long value;
    short count;
	int height;
    node *l, *r;
} *R, *NIL;
struct elem
{
	long value;
	short index;
};

struct ratio
{
	long value;
	int count;
};

vector <elem> V, A;
vector <ratio> Ratio;
bool Flag[MAXN];
short Sol[MAXN], Opt[MAXN];



bool operator < (const elem &a, const elem &b)
{
	return a.value < b.value;
}

bool operator < (const ratio &a, const ratio &b)
{
	return a.count > b.count;
}


void Readdata()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif
	scanf("%d", &N);

	V.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &V[i].value);
		V[i].index = i;
	}
}

int Is(long value)
{
	long l, r, mid;

	l = 0;
	r = N - 1;

	while (l <= r)
	{
		mid = (l + r) / 2;

		if (A[mid].value == value)
			return A[mid].index;
		else
		if (A[mid].value > value)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return -1;
}

// AVL stuff
node *rotleft(node *k1)
{
    node *k2 = k1->l;
    k1->l = k2->r;
    k2->r = k1;
    getheight(k1);
    getheight(k2);
    return k2;
}

node *rotright(node *k2)
{
    node *k1 = k2->r;
    k2->r = k1->l;
    k1->l = k2;
    getheight(k2);
    getheight(k1);
    return k1;
}

node *avl_rotate(node *n)
{
    if (n == NIL) return n;
    if (n->l->height > n->r->height+1)
    {
        if (n->l->r->height > n->l->l->height) n->l = rotright(n->l);
        n = rotleft(n);
    } else
    if (n->r->height > n->l->height+1)
    {
        if (n->r->l->height > n->r->r->height) n->r = rotleft(n->r);
        n = rotright(n);
    }
    return n;
}

node *avl_insert(node *n, long val)
{
    if (n == NIL)
    {
        n = (node *) malloc(sizeof(node));
        n->value = val;
        n->count = 1;
		n->height = 1;
        n->l = n->r = NIL;
        return n;
    }
    if (val < n->value)
        n->l = avl_insert(n->l, val);
    else
        n->r = avl_insert(n->r, val);
    getheight(n);
    return avl_rotate(n);
}
void avl_init()
{
    NIL = (node *) malloc(sizeof(node));
	NIL->value = 0;
	NIL->count = 0;
	NIL->l = NULL;
	NIL->r = NULL;
    NIL->height = 0;
    R = NIL;
}

node *avl_find(node *n, long val)
{
	if (n != NIL && val < n->value)
		return avl_find(n->l, val);
	else
	if (n != NIL && val > n->value)
		return avl_find(n->r, val);
	else
		return n;
}

void avl_Inorder(node *R)
{
	if (R != NIL)
	{
		avl_Inorder(R->l);

		ratio x;
		x.value = R->value;
		x.count = R->count;
		Ratio.push_back(x);

		avl_Inorder(R->r);
	}
}


// Solve
void Solve()
{
	long i, j, r, k;

	// eliminate duplicates from input
	sort(V.begin(), V.end());

	A.push_back(V[0]);
	for (i = 1; i < V.size(); i++)
		if (V[i].value != V[i - 1].value)
			A.push_back(V[i]);;;
	V.clear();

	// compute all ratios and count them
	N = A.size();
	avl_init();
	long cnt = 0;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
		{
			cnt++;
			cnt = A[i].value;
			//long value = ABS(A[i].value - A[j].value);

			/*node *nod;
			nod = avl_find(R, value);
			if (nod != NIL)
			{
				nod->count++;
			} else
			{
				R = avl_insert(R, value);
			}*/
		}

	// creates a new vector with unique ratios and their freq, sort them desc
	avl_Inorder(R);

	sort(Ratio.begin(), Ratio.end());

	for (i = 0; i < MIN(4, Ratio.size()); i++)
	{
		if (Ratio[i].count <= Opt[0]) // no sense to continue
			break;
		r = Ratio[i].value;

		for (j = 0; j < MAXN; j++)
			Flag[j] = false;
		for (j = 0; j < N; j++)
			if (!Flag[A[j].index])
			{
				Flag[A[j].index] = true;

				k = 1;
				Sol[0] = 1;
				Sol[1] = A[j].index;
				while (true)
				{
					int poz = Is(A[j].value + k * r);
					if (poz == -1)
						break;
					Sol[++Sol[0]] = poz;
					Flag[poz] = true;
					k++;
				}
				if (Sol[0] > Opt[0])
					memcpy(Opt, Sol, (Sol[0] + 1) * sizeof(Sol[0]));
			}
	}
	if (Opt[0] == 0)
		Opt[++Opt[0]] = 0;
	printf("%d\n", Opt[0]);
	for (i = 1; i <= Opt[0]; i++)
		printf("%d ", Opt[i] + 1);
}


void Generate(int n)
{
	int i;


	FILE *f = fopen(INPUT_FILE, "wt");

	fprintf(f, "%d\n", n);
	for (i = 0; i < n; i++)
		fprintf(f, "%ld ", 1000000000L - i);

	fclose(f);
}

int main()
{
	//Generate(10000);
	Readdata();
	Solve();

	return 0;
}
