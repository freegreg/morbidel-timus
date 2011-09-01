/*
 * ACM Online
 * Anniversary Party - Problem 1039
 *
 * solutie: dinamica, 	p[i] -> suma cu i radacina si participa și i
 * 			q[i] -> suma cu i rad. si nu part.
 * p[i] = suma(q[j]), j fiu; q[i] = suma(max(p[j], q[j])), j fiu
 * merge O(N) cu șmenul de la codul Pruffer
 */

#include <stdio.h>
#include <string.h>

#define NODS 		6001
#define INF		999999999
#define MAX(a, b)	((a) > (b) ? (a) : (b))

int n;
long c[NODS], p[NODS], q[NODS], t[NODS], g[NODS];


void readdata()
{
	int i, j;
	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%ld", &c[i]);
		t[i] = -1;
	}

	while (true)
	{
		scanf("%d %d", &i, &j);  // j e tata lui i
		if (!i && !j) 
			break;
		t[i] = j; 
		g[j]++;	/* not really the node's degree, but number of sons */
	}
}

void solve()
{
	int i, next, old;
	long vmax;
	bool optimize = false;


	memset(p, 0, sizeof(p));
	memset(q, 0, sizeof(q));
	
	next = 1;
	old = -1;

	for (i = 0; i < n; i++)
	{
		/* search for next leaf */
		while (g[next] != 0 && next <= n)
			next++;

		//printf("%d\n", next);
		p[next] += c[next];

		q[t[next]] += MAX(p[next], q[next]);
		p[t[next]] += q[next];

		g[next]--;
		g[t[next]]--;

		if (g[t[next]] == 0 && ((t[next] < old && old != -1) || t[next] < next))
		{
			if (optimize)	/* keep oldest value from the while beside */
				old = next;
			next = t[next];

			optimize = true;
		}
		else
		{
			optimize = false;
			if (old != -1)	/* cannot optmize anymore, go back to old value */
			{
				next = old;
			}
			next++;
		}
	}

	vmax = 0;
	for (i = 1; i <= n; i++)
		if (t[i] == -1 && MAX(p[i], q[i]) > vmax)
			vmax = MAX(p[i], q[i]);
	printf("%ld\n", vmax);
}

int main()
{
	readdata();
	solve();

	return 0;
}
