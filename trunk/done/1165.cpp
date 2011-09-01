/*
 *  ACM Online
 *  Subnumber - Problem 1165 (super belea!)
 *
 *  solutie: verific numerele cu 1, 2, 3... cifre cu niste cazuri aparte:
 *  toate 0, permutåri circulare. Formulele de id sunt:
 *  pz[k] = pz[k - 1] + 9 * (k - 1) * 10^(k - 2), poz[x] = pz[c] + (x - 10^(c - 1)) * c,
 *  (c este nr cifre al x)
 */

#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int n[210], ok = 0;
typedef int HUGE[210];
HUGE one, sol, id, id2, obak;


void readdata()
{
	char ch;
	while (scanf("%c", &ch) == 1)
		if (ch >= '0' && ch <= '9')
			n[++n[0]] = ch - '0';
		else break;
}

/*  a += x  */
void add(HUGE a, int x)
{
	int i;
	a[i = 1] += x;
	while (a[i] > 9)
		a[i + 1] += a[i] / 10, a[i] %= 10, i++;
	a[0] = a[0] + i - min(a[0], i);
}

/*  a -= x  */
void sub(HUGE a, int x)
{
	int i;
	a[i = 1] -= x;
	for (i = 1; i <= a[0]; i++)
		while (a[i] < 0)
			a[i + 1]--, a[i] += 10;
	while (!a[a[0]] && a[0] > 1) a[0]--;
}

/*  a *= x  */
void imul(HUGE a, int x)
{
	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / 10, a[i] %= 10;
	while (k)
		a[++a[0]] = k % 10, k /= 10;
}

void flip(HUGE a)
{
	int i, j;
	for (i = 1; 2 * i <= a[0]; i++)
		j = a[i], a[i] = a[a[0] - i + 1], a[a[0] - i + 1] = j;
}

int cmp(HUGE a, HUGE b)
{
	int i;
	if (a[0] > b[0]) return 1;
	if (a[0] < b[0]) return -1;
	for (i = 1; i <= a[0]; i++)
		if (a[i] > b[i]) return 1; else
		if (a[i] < b[i]) return -1;
	return 0;
}

/*  a += b  */
void add2(HUGE a, HUGE b)
{
	int i, k = 0;
	a[0] = a[0] + b[0] - min(a[0], b[0]);
	for (i = 1; i <= a[0]; i++)
		a[i] += b[i] + k, k = a[i] / 10, a[i] %= 10;
	if (k) a[++a[0]] = k;
}

/*  a = 10^k  */
void shl10(HUGE a, int k)
{
	int i;
	a[0] = k + 1;
	for (i = 1; i < a[0]; i++) a[i] = 0;
	a[a[0]] = 1;
}

/*  a -= 10^k  */
void sub2(HUGE a, int k)
{
	int i;
	a[k + 1]--;
	for (i = k + 1; i <= a[0]; i++)
		if (a[i] < 0)
			a[i + 1]--, a[i] += 10;
	while (!a[a[0]] && a[0] > 1) a[0]--;
}

/*  verificå dacå one e corect, adunå 1 si merge în dreapta pânå la capåt  */
int good(int poz, int tcif, int cif)
{
	int i, j, x = cif;

	if (cif < tcif && ok != 2)
	{
		for (id[0] = 0, i = 1; i < poz; i++)
			id[++id[0]] = n[i];
		flip(id);
		add(id, 1);
		id[0] = tcif - cif;
		flip(id);
		for (i = 1; i <= tcif - cif; i++)
			one[++one[0]] = id[i];
		memcpy(obak, one, sizeof(one));
		if (tcif == n[0]) return 1;
	}
	memcpy(obak, one, sizeof(one));
	flip(one);
	sub(one, 1);
	for (j = 1, i = poz - 1; i || j <= one[0]; i--, j++)
	{
		if (!i) break;
		if (one[j] != n[i]) return 0;
	}
	add(one, 1);
	flip(one);
	for (i = poz; i <= n[0]; i += x)
	{
		for (j = 1; j <= x; j++)
			if (one[j] != n[i + j - 1] && i + j - 1 <= n[0]) return 0;
		flip(one);
		add(one, 1);
		flip(one);
		if (x != one[0]) i--;
		x = one[0];
	}
	return 1;
}

/*  scoate pozitia în id  */
void GetId()
{
	int i, c = sol[0];
	memset(id, 0, sizeof(id));
	if (c == 1)
	{
		id[0] = 1, id[1] = sol[1];
		return;
	}
	id[0] = id[1] = 1;
	for (i = 2; i <= c; i++)
	{
		shl10(id2, i - 2);
		imul(id2, 9 * (i - 1));
		add2(id2, id);
		memcpy(id, id2, sizeof(id2));
	}
	if (!ok)
	{
		add(id, 1);
		memcpy(sol, id, sizeof(id));
		return;
	}
	flip(sol);
	sub2(sol, c - 1);
	imul(sol, c);
	add2(sol, id);
}

void solve()
{
	int i, poz, cif, pz;

	sol[0] = 0;
	for (cif = 1; cif <= n[0]; cif++)
	{
		for (poz = 1; poz <= cif; poz++)
		{
			one[0] = 0;
			if (!n[poz]) continue;
			for (i = poz; i <= min(n[0], poz + cif - 1); i++)
				one[++one[0]] = n[i];
			if (good(poz, cif, one[0]))
				if (!sol[0] || cmp(one, sol) == -1 || (!cmp(one, sol) && poz > pz))
			{
				memcpy(sol, obak, sizeof(obak));
				ok = 1; pz = poz;
			}
		}
		if (ok) break;
	}
	if (!ok)        /*  numai 0  */
		pz = 1, shl10(sol, n[0]);
	else
	/*  mai verific dacå e posibil cu o pozitie mai departe... caz 0K0K0K...  */
	for (poz = pz + 1; poz <= sol[0]; poz++)
	{
		ok = 2;
		memcpy(one, sol, sizeof(sol));
		if (good(poz, one[0], n[0] - poz + 1))
			pz = poz;
	}

	/*  acum aplicåm formula magicå pentru id  */
	GetId();
	sub(sol, pz - 1);

	for (i = sol[0]; i; printf("%d", sol[i--]));
	printf("\n");
}

int main()
{
	readdata();
	solve();
	return 0;
}
/*
 *  Fie så renascå numai cel ce har
 *  Are de-a renaste curåtit prin jar
 *  Din cenusa-i proprie si din propriul scrum
 *  Aståzi ca si mâine, pururi si acum!
 */
