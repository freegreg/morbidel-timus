/*
 * ACM Timus Online Contest - 18 September 2011
 * Problem F - GCD 2010
 */

#include <cstdio>

int N, GCD;
struct node
{
    int val;
	int count;
    int height;
    struct node *l, *r;
} *R;

struct node *NIL;

#undef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#define getheight(n) (n->height = max(n->l->height, n->r->height)+1)


int gcd(int a, int b)
{
	int t;

	while (b)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

struct node *rotleft(struct node *k1)
{
    struct node *k2 = k1->l;
    k1->l = k2->r;
    k2->r = k1;
    getheight(k1);
    getheight(k2);
    return k2;
}

struct node *rotright(struct node *k2)
{
    struct node *k1 = k2->r;
    k2->r = k1->l;
    k1->l = k2;
    getheight(k2);
    getheight(k1);
    return k1;
}

struct node *rotate(struct node *n)
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

struct node *insert(struct node *n, int val)
{
    if (n == NIL)
    {
        n = new node;
        n->val = val;
        n->height = 1;
		n->count = 1;
        n->l = n->r = NIL;
        return n;
    }

    if (val < n->val)
        n->l = insert(n->l, val);
    else
        n->r = insert(n->r, val);

    getheight(n);
    return rotate(n);
}

struct node *erase(struct node *n, int val)
{
    struct node *t;
    if (n == NIL) return n;
    if (n->val == val)
    {
        if (n->l == NIL || n->r == NIL)
        {
            t = (n->l == NIL) ? n->r : n->l;
            delete n;
            return t;
        }
        for (t = n->r; t->l != NIL; t = t->l);
        n->val = t->val;
		n->count = t->count;
        n->r = erase(n->r, n->val);
    } else
    if (val < n->val)
        n->l = erase(n->l, val);
    else
        n->r = erase(n->r, val);
    getheight(n);
    return rotate(n);
}

struct node* find(struct node *n, int val)
{
	if (n == NIL || n->val == val)
		return n;

	if (val < n->val)
        return find(n->l, val);
    else
        return find(n->r, val);
}

void init()
{
    NIL = new node;
    NIL->height = 0;
	NIL->count = NIL->val = -1;

    R = NIL;
}

void ComputeGCD(struct node* n)
{
	if (n != NIL)
	{
		if (n->count > 0)
		{
			//V.push_back(n->val);
			GCD = (GCD == -1) ? n->val : gcd(GCD, n->val);
		}
		ComputeGCD(n->l);
		ComputeGCD(n->r);
	}
}

int main()
{
	//gen();

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
    init();

	scanf("%d\n", &N);

	int i, n;
	char ch;

	GCD = -1;
	for (i = 0; i < N; i++)
	{
		scanf("%c %d\n", &ch, &n);

		node *x = find(R, n);

		if (ch == '+')
		{
			if (x != NIL)
				x->count++;
			else
			{
				R = insert(R, n);

				// n is new, recalculate the gcd
				GCD = (GCD == -1) ? n : gcd(GCD, n);
			}
		} else if (x != NIL)
		{
			x->count--;
			if (x->count == 0)
			{
				R = erase(R, n);
				// n was erased completely, gcd should be recalculated 
				GCD = -1;
				ComputeGCD(R);
				if (GCD == -1)
					GCD = 1;
			}
		}

		printf("%d\n", GCD);
	}
    
    return 0;
}
