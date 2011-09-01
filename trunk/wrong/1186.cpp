/*
 *  ACM Online
 *  Chemical Reactions - Problem 1186
 *
 *  solutie: pars†m expresia aia dar e de c†cat... maro(muncitoreasc†)
 *  am luat algoritmul de la ACM  (parsatul...)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define small(x) (x >= 'a' && x <= 'z')
#define num(x) (x >= '0' && x <= '9')
#define big(x) (x >= 'A' && x <= 'Z')

int n, p, el1, el2;
typedef int sum[27][27];
sum *ap1, *ap;
char f1[110], f2[110], fel1[700][2], fel2[700][2];


long readnum()
{
	long t = 0;
	while num(f2[p])
		t = t * 10 + f2[p++] - '0';
	return t;
}

void readel(char *s)
{
	s[0] = f2[p++];
	s[1] = small(f2[p]) ? f2[p] : 0;
	if (s[1]) p++;
}

void add(sum *a1, sum *a2)
{
	int i, x, y;
	for (i = 0; i < el2; i++)
	{
		x = fel2[i][0] - 64; y = fel2[i][1] ? fel2[i][1] - 96 : 0;
		*a1[x][y] += *a2[x][y];
	}
}

void mul(sum *a1, long xx)
{
	int i, x, y;
	for (i = 0; i < el2; i++)
	{
		x = fel2[i][0] - 64; y = fel2[i][1] ? fel2[i][1] - 96 : 0;
		*a1[x][y] *= xx;
	}
}

int match()
{
	int i, x, y;

	if (el1 != el2) return 0;
	for (i = 0; i < el2; i++)
	{
		x = fel1[i][0] - 64; y = fel1[i][1] ? fel1[i][1] - 96 : 0;
		if (*ap1[x][y] != *ap[x][y])
			return 0;
	}
	return 1;
}

void goleste(sum *a1)
{
	int i, x, y;
	for (i = 0; i < el2; i++)
	{
		x = fel2[i][0] - 64; y = fel2[i][1] ? fel2[i][1] - 96 : 0;
		*a1[x][y] = 0;
	}
}

sum *readseq()
{
	char el[2];
	long t;
	sum *a1, *a2;


	a1 = (sum*) malloc(58253);
	goleste(a1);

	while (big(f2[p]) || f2[p] == '(')
	{
		if (f2[p] == '(')
		{
			p++;
			a2 = readseq();
			p++;
			t = num(f2[p]) ? readnum() : 1;
			mul(a2, t);
			add(a1, a2);
			free(a2);
		} else
		{
			readel(el);
			t = num(f2[p]) ? readnum() : 1;
			*a1[el[0] - 64][el[1] ? (el[1] - 96) : 0] += t;
		}
	}
	return a1;
}

sum *readadd()
{
	long t;
	sum *a1;

	t = num(f2[p]) ? readnum() : 1;
	a1 = readseq();
	mul(a1, t);
	return a1;
}

sum *readformula()
{
	sum *a1, *a2;

	a1 = readadd();
	while (f2[p] == '+')
	{
		p++;
		a2 = readadd();
		add(a1, a2);
		free(a2);
	}
	return a1;
}

/*  scoate elementele din f2 si le pune Œn fel2, el2  */
void get_elem()
{
	int i, j, bad;
	char el[2];

	el2 = 0;
	for (i = 0; i < strlen(f2); i++)
		if (big(f2[i]))
		{
			el[0] = f2[i]; bad = 0;
			el[1] = small(f2[i + 1]) ? f2[++i] : 0;
			for (j = 0; j < el2; j++)
				if (!strcmp(fel2[j], el)) bad = 1, j = el2;
			if (!bad)
				strcpy(fel2[el2++], el);
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("file.in", "rt", stdin);
	#endif

	scanf("%s\n%d\n", &f1, &n);
	strcpy(f2, f1);
	get_elem();
	el1 = el2;
	memcpy(fel1, fel2, sizeof(fel2));
	p = 0;
	ap1 = readformula();

	for (; n--; )
	{
		scanf("%s", &f2);
		get_elem();
		p = 0;
		ap = readformula();
		printf("%s%s=%s\n", f1, match() ? "=" : "!", f2);
		free(ap);
	}
	free(ap1);


	return 0;
}
/*
 *  Face the enemy, stay inside you,
 *  control your thoughts, destroy, destroy them all
 */
