/*
 *  ACM Online
 *  A binary apple tree - Problem 1018
 *
 *  solutie: dinamic†: s[i][j] -> costul maxim al subarborelui de r†d. i cu
 *  j muchii r†mase. Solutia e s[0][Q]
 *  O(N^3)
 */

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define NODS 110

int n, q, h = 0, flag[NODS], tata[NODS], gr[NODS], ord[NODS], m[NODS];
long s[NODS][NODS], a[NODS][NODS];


void readdata()
{
	long i, n1, n2, c;

	for (i = 0; i < 110; i++)
		for (c = 0; c < 110; c++)
			a[i][c] = -1, s[i][c] = -1e9;

	scanf("%d %d", &n, &q);
	for (i = 0; i < n - 1; i++)
	{
		scanf("%ld %ld %ld", &n1, &n2, &c);
		if (!c) q--;
		n1--; n2--;
		a[n1][n2] = a[n2][n1] = c;
	}
}

void df(int nod)
{
	int i;
	for (flag[nod] = 1, i = 0; i < n; i++)
		if (!flag[i] && a[nod][i] >= 0)
			tata[i] = nod, df(i);
}

void solve()
{
	int i, j, k, nod, fs, fd;
	long opt, now;

	/*  calcul†m tatzii  */
	tata[0] = -1;
	df(0);

	/*  calcul†m gradele  */
	for (i = 0; i < n; i++)
		if (tata[i] >= 0) gr[tata[i]]++;

	/*  ordinea Œn care lu†m nodurile  */
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (!gr[j])
				ord[h++] = j, gr[tata[j]]--, gr[j] = -1;

	/*  m[i] -> cƒte muchii sunt Œn subarborele de r†d†cin† i  */
	for (i = 0; i < n; i++)
		for (nod = ord[i], j = 0; j < n; j++)
			if (a[nod][j] >= 0 && j != tata[nod])
				m[nod] += m[j] + 1;

	/*  dinamica propriu-zis†  */
	for (i = 0; i < n; i++)
	{
		nod = ord[i]; fs = fd = -1;
		/*  caut fii  */
		for (j = 0; j < n; j++)
			if (a[nod][j] >= 0 && j != tata[nod])
			{
				if (fs < 0) fs = j;
				else fd = j, j = n;
			}
		/*  cazuri speciale...  */
		s[nod][0] = 0;
		s[nod][1] = max(a[nod][fs], a[nod][fd]);
		for (j = 2; j <= m[nod]; j++)
		{
			opt = now = -1e9;
			/*  verific†m mereu s† nu dep†sim nr. maxim de muchii...  */
			if (m[fs] >= j - 1)
				opt = s[fs][j - 1] + a[nod][fs];
			if (m[fd] >= j - 1)
				now = s[fd][j - 1] + a[nod][fd];
			if (now > opt) opt = now;
			for (k = 0; k <= j - 2; k++)
			{
				now = -1e9;
				if (m[fs] >= j - 2 - k && m[fd] >= k)
					now = a[nod][fs] + a[nod][fd],
					now += s[fs][j - 2 - k] + s[fd][k];
				if (now > opt) opt = now;
			}
			s[nod][j] = opt;
		}
	}

	printf("%ld\n", s[0][q]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
