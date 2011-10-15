/*
 * ACM Timus Online Contest - 18 September 2011
 * Problem F - GCD 2010
 */

#include <ctime>
#include <cstdlib>
#include <cstdio>

int N;
int Flag[100000];

struct node
{
  int gcd;      // gcd for all subtree (!)
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
  while (b > 0)
  {
    t = a;
    a = b;
    b = t % b;
  }
  return a;
}

void inorder(node *n)
{
  if (n != NIL)
  {
    int proba = n->val;
    if (n->l->gcd != -1)
      proba = gcd(proba, n->l->gcd);
    if (n->r->gcd != -1)
      proba = gcd(proba, n->r->gcd);

    if (proba != n->gcd)
    {
      printf("ERROR: nodul %d nu are gcd-ul valid (%d față de %d)\n", n->val, n->gcd, proba);
    }

    inorder(n->l);
    inorder(n->r);
  }
}


int computegcd(struct node *n)
{
	if (n == NIL)
		return -1;
    // actualizăm gcd-ul pt fiecare nod
    n->gcd = n->val;
    if (n->l != NIL && n->l->gcd != -1)
      n->gcd = gcd(n->gcd, n->l->gcd);
    if (n->r != NIL && n->r->gcd != -1)
      n->gcd = gcd(n->gcd, n->r->gcd);

    return n->gcd;
}

struct node *rotleft(struct node *k1)
{
    struct node *k2 = k1->l;
    k1->l = k2->r;
    k2->r = k1;
    getheight(k1);
    getheight(k2);

    // recompute gcd's
    computegcd(k1);
    computegcd(k2);

    return k2;
}

struct node *rotright(struct node *k2)
{
    struct node *k1 = k2->r;
    k2->r = k1->l;
    k1->l = k2;
    getheight(k2);
    getheight(k1);

    // recompute gcd's
    computegcd(k1);
    computegcd(k2);

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

    computegcd(n);
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
        n->gcd = n->val;
        n->l = n->r = NIL;
        return n;
    }
    else if (n->val == val)
    {
      n->count++;
      return n;
    }

    if (val < n->val)
	{
        n->l = insert(n->l, val);
		computegcd(n->l);
	}
    else
	{
        n->r = insert(n->r, val);
		computegcd(n->r);
	}

    getheight(n);
    return rotate(n);
}

struct node *erase(struct node *n, int val)
{
    struct node *t;

    if (n == NIL) 
      return n;
    
    if (n->val == val)
    {
        if (n->count > 1)
        {
          n->count--;
        }
        else
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
		  computegcd(n->r);
        }
    } else
    if (val < n->val)
	{
        n->l = erase(n->l, val);
		computegcd(n->l);
	}
    else
	{
        n->r = erase(n->r, val);
		computegcd(n->r);
	}
    getheight(n);
    return rotate(n);
}

void init()
{
  NIL = new node;
  NIL->height = 0;
	NIL->count = NIL->val = -1;
  NIL->gcd = -1;

  R = NIL;
}


void gen()
{
	srand(time(NULL));
	FILE *f = fopen("input.txt", "wt");
	int i, x, n = 10000;

	fprintf(f, "%d\n", n);

	for (i = 0; i < n; i++)
	{
		x = 1 + rand() % (100 - 1);

		if (rand() % 3 == 0 || Flag[x] == 0)
		{
			fprintf(f, "+ %d\n", x);
			Flag[x]++;
		}
		else
		{
			fprintf(f, "- %d\n", x);
			Flag[x]--;
		}
	}
	fclose(f);
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

	for (i = 0; i < N; i++)
	{
		scanf("%c %d\n", &ch, &n);

  		R = (ch == '+') ? insert(R, n) : erase(R, n);

		if (R->gcd == -1)
  			printf("1\n");
		else
  			printf("%d\n", R->gcd);

		inorder(R);
	}
    
  return 0;
}