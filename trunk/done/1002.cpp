/*
 *  ACM Online
 *  Phone Numbers - 1002
 *  solutie: dinamica: t[i] -> min.cuv cu primele i caractere din telefon 
 *  q[i] -> ultimul cuvant
 */


#include <stdio.h>
#include <string.h>

#define NCUV 50001

char tel[110], flag[256], cuv[310000L];
long n, l, pozcuv[NCUV], t[110], q[110], sol[110];


void readdata()
{
	long i, j;
	char s[300];

	scanf("%ld%s\n", &n, &s);
	pozcuv[1] = 1; pozcuv[2] = 1 + strlen(s);
	for (i = 0; i < strlen(s); i++)
		cuv[i + 1] = s[i];
	for (i = 2; i <= n; i++)
	{
		scanf("%s\n", &s);
		for (j = 0; j < strlen(s); j++)
			cuv[pozcuv[i] + j] = s[j];
		pozcuv[i + 1] = pozcuv[i] + j;
	}
}

int len(long nrc)
{
	return (pozcuv[nrc + 1] - pozcuv[nrc]);
}

void solve()
{
	long i, j, k, ok;

	for (i = 0; i <= strlen(tel); i++)
		q[i] = 0, t[i] = 30000;
	t[0] = 0; q[0] = -1; l = strlen(tel);
	for (i = 0; i <= l; i++)
		if (t[i] < 30000)
		{
			for (j = 1; j <= n; j++)
			{
				if (i + len(j) > l) continue;
				if (1 + t[i] > t[i + len(j)]) continue;
				if (1 + t[i] == t[i + len(j)] && len(j) < len(q[i + len(j)])) continue;
				ok = 1;
				for (k = 0; k < len(j); k++)
					if (flag[cuv[pozcuv[j] + k]] != tel[i + k])
					{
						ok = 0;
						break;
					}
				if (!ok) continue;
				t[i + len(j)] = t[i] + 1;
				q[i + len(j)] = j;
			}
		}
}

void writesol()
{
	long i, j, last;

	sol[0] = 0;
	if (t[l] == 30000)
		printf("No solution.");
	else
	{
		last = l;
		do
		{
			sol[++sol[0]] = q[last];
			last = last - len(q[last]);
			if (last <= 0) break;
		}
		while (1);
	}
	for (i = sol[0]; i; i--, printf(" "))
		for (j = 1; j <= len(sol[i]); j++)
			printf("%c", cuv[pozcuv[sol[i]] + j - 1]);
	printf("\n");
}

int main()
{
	flag['i'] = flag['j'] = '1'; flag['a'] = flag['b'] = flag['c'] = '2';
	flag['d'] = flag['e'] = flag['f'] = '3'; flag['g'] = flag['h'] = '4';
	flag['k'] = flag['l'] = '5'; flag['m'] = flag['n'] = '6';
	flag['p'] = flag['r'] = flag['s'] = '7'; flag['t'] = flag['u'] = flag['v'] = '8';
	flag['w'] = flag['x'] = flag['y'] = '9'; flag['o'] = flag['q'] = flag['z'] = '0';

	while (1)
	{
		scanf("%s", &tel);
		if (tel[0] == '-') break;
		readdata();
		solve();
		writesol();
	}

	return 0;
}
