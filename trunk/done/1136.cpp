// ACM Online
// Parliament - Problem 1136

// se da o secventa de arbore de cautare parcurs SDV si tre' s-o afisam DSV
// solutie: sloboz vernil spre gri

#include <stdio.h>
#include <stdlib.h>



unsigned n, v[3001];
struct node
{
	unsigned x;
	node *l, *r;
} *root;


void readdata()
{
	scanf("%d", &n);
	for (int i = 0; i < n; scanf("%u", &v[i++]));
	
}
int pos(int l, int r, unsigned num)
{
	int mid;
	if (num < v[l]) return l;
	if (num > v[r]) return r + 1;
	do
	{
		if (l == r - 1 && num > v[l] && num < v[r] || l == r) return r;
		mid = (l + r) / 2;
		if (num > v[mid]) l = mid + 1;
		else r = mid;
	}
	while (1);
}
node *baga(int l, int r)
{
	if (l > r) return NULL;
	int poz = pos(l, r - 1, v[r]);
	node *p = (node*) malloc(sizeof(*p));
	if (!p)
	{
		printf("No memory!"); return NULL;
	}
	p -> x = v[r];
	if (l == r)
	{
		p -> l = p -> r = NULL;
		return p;
	}
	p -> l = baga(l, poz - 1);
	p -> r = baga(poz, r - 1);
	return p;
}
void dsv(node *p)
{
	if (p)
	{
		dsv(p -> r);
		dsv(p -> l);
		printf("%u ", p -> x);
	}
}
void solve()
{
	root = baga(0, n - 1);
	dsv(root);
	printf("\n");
}
void main()
{
	readdata();
	solve();
}