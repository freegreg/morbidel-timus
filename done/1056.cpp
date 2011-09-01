/*
 *  ACM Online
 *  Computer Net - Problem 1056
 *
 *  solutie: trebuie nodurile din mijlocul drumului cel mai lung din arbore
 *  care Œl facem in O(N) astfel: bottom up recursiv si retinem si fiul optim
 *  si Œn†ltimea. Apoi calcul†m pt. fiecare r†d†cin† drumul cel mai lung cu fii
 *  s†i maximi si-i retinem apoi construim drumul...
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define NODS 10010

int n, road[NODS], h[NODS], tata[NODS], root[NODS];
struct tree
{
	int fiu;
	tree *next;
} *a[NODS];


void readdata()
{
	int i;
	tree *q;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%d", &tata[i]);
		tata[i]--;
		q = (tree*) malloc(sizeof(*q));
		q -> fiu = i; q -> next = a[tata[i]]; a[tata[i]] = q;
	}
}

int height(int nod)
{
	int max = 0, rut = -1;
	tree *q;
	for (q = a[nod]; q; q = q -> next)
		if ((h[nod] = 1 + height(q -> fiu)) > max)
			max = h[q -> fiu] + 1, rut = q -> fiu;
	root[nod] = rut;
	return h[nod] = max;
}

void solve()
{
	tree *q;
	int i, rad, l1, l2, now, max1, max2, f1, f2;

	h[0] = height(0);
	now = 0; l1 = l2 = tata[0] = -1;
	for (i = 0; i < n; i++)
	{
		max1 = max2 = 0; f1 = f2 = -1;
		for (q = a[i]; q; q = q -> next)
		{
			if (h[q -> fiu] + 1 > max1)
				max2 = max1, f2 = f1, max1 = h[q -> fiu] + 1, f1 = q -> fiu;
			else
			if (h[q -> fiu] + 1 > max2)
				max2 = h[q -> fiu] + 1, f2 = q -> fiu;
		}
		if (max1 + max2 > now)
			rad = i, now = max1 + max2, l1 = f1, l2 = f2;
	}
	now++;
	while (root[l1] != -1 && l1 >= 0) l1 = root[l1];
	while (root[l2] != -1 && l2 >= 0) l2 = root[l2];
	/*
		acum l1 si l2 sunt capetele celui mai lung drum din arbore
		refacem traseul si afis†m nodu(ri)l(e) din mijloc
	*/
	if (l2 == -1) l2 = rad;
	for (f1 = 0, i = l1; i != rad; i = tata[i]) road[f1++] = i;
	road[f1] = rad;
	for (f1 = 1, i = l2; i != rad; i = tata[i]) road[now - f1++] = i;

	l1 = road[now / 2 - 1] + 1; l2 = road[now / 2] + 1;
	if (now % 2 == 0)
		printf("%d %d\n", l1 + l2 - max(l1, l2), max(l1, l2));
	else printf("%d\n", l2);
}

int main()
{
	readdata();
	solve();
	return 0;
}
/*
	Ce-ai studiat Œn c†rti nu-i adev†rat,
	Gravitatia, timpul si spatiul,
	e nu-i egal cu mc p†trat, mint populatia
	De mii de ani Œncoace, conspiratii secrete
	Dar al saselea simt, al treilea ochi le vede...
*/
