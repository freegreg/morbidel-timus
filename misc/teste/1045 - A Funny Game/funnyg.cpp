/*
 *  ACM Online
 *  A funny game - Problem 1045
 *
 *  solutie: a[i] -> cine castiga in subarborele lui i daca incepe 1 si b[i] daca incepe 2 (b[i] = 3 - a[i])
 *  a[i] = 1 daca exista un fiu x al lui i cu b[x] = 1 altfel e 2
 */

#include <stdio.h>
#include <stdlib.h>

#define input "funnyg.in"
#define output "funnyg.out"
#define NODS 1010


FILE *f;
int n, root, airport = 6666;
int gr[NODS], flag[NODS], tata[NODS], win[NODS];
struct graf
{
	int nod;
	graf *next;
} *a[NODS];


void readdata()
{
	int i, j, k;
	graf *q;

	f = fopen(input, "r");
	fscanf(f, "%d %d", &n, &root);
	for (k = 0; k < n - 1; k++)
	{
		fscanf(f, "%d %d", &i, &j);
		q = (graf*) malloc(sizeof(*q));
		q -> nod = i; q -> next = a[j]; a[j] = q;
		q = (graf*) malloc(sizeof(*q));
		q -> nod = j; q -> next = a[i]; a[i] = q;
		gr[i]++; gr[j]++;
	}
	fclose(f);
}

void df(int nod)
{
	graf *q;
	flag[nod] = 1;
	for (q = a[nod]; q; q = q -> next)
		if (!flag[q -> nod])
			tata[q -> nod] = nod, df(q -> nod);
}

void solve()
{
	graf *q;
	int i, j, nod = -1, next, ok;

	df(root);

	for (i = 1; i <= n; i++)
		if (i != root)
		{
			if (gr[i] == 1 && nod == -1) 
				nod = i;
			gr[i]--;
		}

	for (j = 0; j < n; j++)
	{
		/*  avem frunza nod  */
		for (ok = 0, q = a[nod]; q; q = q -> next) 
			if (q -> nod != tata[q -> nod] && win[q -> nod] == 2)
			{ ok = 1; break; }
		win[nod] = ok ? 1 : 2;

		for (next = 10000, i = nod + 1; i <= n; i++)
			if (!gr[i] && (i != root || j == n - 2))
				next = i, i = n;
		if (--gr[tata[nod]] == 0 && tata[nod] < next && (tata[nod] != root || j == n - 2)) 
			next = tata[nod];
		gr[nod] = -1; nod = next;
	}

	for (q = a[root]; q; q = q -> next)
		if (win[q -> nod] == 2 && q -> nod < airport) 
			airport = q -> nod;

	f = fopen(output, "w");
	if (airport == 6666)
		fprintf(f, "First player loses\n");
	else
		fprintf(f, "First player wins flying to airport %d\n", airport);
	fclose(f);
}

int main()
{
	readdata();
	solve();
	return 0;
}

/*
 *  Cu ape de rosu-n ochi, valuri mari de alb, mov si verde zboara cald, pe chipul tau drag, esarfa-n dar...
 */