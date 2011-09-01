/*
 *  ACM Online
 *  Chemical Reactions - Problem 1186
 *
 *  solutie: pars†m expresia aia dar e de c†cat... maro(muncitoreasc†)
 *  am luat algoritmul de la ACM (parsatul...)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define input "chem.in"
#define output "chem.out"
#define small(x) (x >= 'a' && x <= 'z')
#define num(x) (x >= '0' && x <= '9')
#define big(x) (x >= 'A' && x <= 'Z')

FILE *fi, *fo;
int n, p, el1, el2, cc = 0;
typedef int sum[30][30];
sum *ap1, *ap;
char f1[108], f2[108], fel1[680][3], fel2[680][3];


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
	memset(*a1, 0, sizeof(*a1));
	/*
	for (i = 0; i < el2; i++)
	{
		x = fel2[i][0] - 64; y = fel2[i][1] ? fel2[i][1] - 96 : 0;
		*a1[x][y] = 0;
	} */
}

sum *readseq()
{
	char el[2];
	long t;
	sum *a1, *a2;

	printf("5\n", cc++);
	if (!a1)
		a1 = (sum*) malloc(sizeof(*a1));
	goleste(a1);
	printf("6\n", cc++);

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
			delete a2;
			a2 = NULL;
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
		delete a2;
		a2 = NULL;
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
	fi = fopen(input, "r");
	fo = fopen(output, "w");

	fscanf(fi, "%s\n%d\n", &f1, &n);
	strcpy(f2, f1);
	get_elem();
	el1 = el2;
	memcpy(fel1, fel2, sizeof(fel2));
	p = 0;
	printf("1\n");
	ap1 = readformula();
	printf("2\n");

	for (; n--; )
	{
		fscanf(fi, "%s", &f2);
		get_elem();
		p = 0;
		printf("3\n", cc++);
		ap = readformula();
		printf("4\n", cc++);
		fprintf(fo, "%s%s=%s\n", f1, (el1 == el2 && match()) ? "=" : "!", f2);
		delete ap;
		delete ap1;
	}
	fclose(fo); fclose(fi);

	return 0;
}
/*
 *  Face the enemy, stay inside you,
 *  control your thoughts, destroy, destroy them all
 */
