/*
 *  ACM Timus Online
 *  Password Search - Problem 1547
 */

#include <stdio.h>
#include <string>
#include <string.h>

#define INPUT		"input.txt"
#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define MIN(a, b)	((a) > (b) ? (b) : (a))
#define BASE		10
#define MAXN		50

using namespace std;

int M, N;
typedef int BIGINT[1024];
BIGINT Count[MAXN + 1], Pow26[MAXN + 1];



void PrintBIG(BIGINT &a)
{
	int i;

	for (i = a[0]; i > 0; i--)
		printf("%d", a[i]);
	printf("\n");
}

// a = b
void Equal(BIGINT &a, BIGINT &b)
{
	int i;

	for (i = 0; i <= b[0]; i++)
		a[i] = b[i];
}
// a = n
void MakeBig(BIGINT &a, int n)
{
	a[0] = 0;

	if (n == 0)
	{
		a[++a[0]] = 0;
	}

	while (n)
		a[++a[0]] = n % BASE, n /= BASE;
}

// ret a = a + b
void Add(BIGINT &a, BIGINT &b)
{
	int i, k = 0;

	if (b[0] > a[0])
	{
		for (i = a[0] + 1; i <= b[0]; i++)
			a[i] = 0;
		a[0] = b[0];
	}

	for (i = 1; i <= MAX(a[0], b[0]); i++)
		a[i] += (i <= b[0] ? b[i] : 0) + k, k = a[i] / BASE, a[i] %= BASE;

	if (k)
		a[++a[0]] = k;
}

// ret a = a * x
void IMul(BIGINT &a, int x)
{
	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / BASE, a[i] %= BASE;

	while (k)
		a[++a[0]] = k % BASE, k /= BASE;

	while (a[a[0]] == 0 && a[0] > 1)
		a[0]--;
}

// ret a = a - b
void Sub(BIGINT &a, BIGINT &b)
{
	int i;

	for (i = 1; i <= a[0]; i++)
	{
		if (i <= b[0])
			a[i] -= b[i];
		if (a[i] < 0)
			a[i] += BASE, a[i + 1]--;
	}

	while (a[a[0]] == 0 && a[0] > 1)
		a[0]--;
}

// ret a (> = <) b
int Cmp(BIGINT &a, BIGINT &b)
{
	if (a[0] > b[0])
		return 1;
	if (a[0] < b[0])
		return -1;

	int i;

	for (i = a[0]; i > 0; i--)
	{
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}

	return 0;
}

// ret a % x si a /= x
int IDiv(BIGINT &a, int x)
{
	int i, r = 0;

	for (i = a[0]; i > 0; i--)
	{
		r = r * BASE + a[i];
		a[i] = r / x;
		r %= x;
	}

	while (a[a[0]] == 0 && a[0] > 1)
		a[0]--;

	return r;
}

string GetStringFromIndex(BIGINT &ok)
{
	int n, i, j;
	string res;
	BIGINT unu, t1, t2;
	BIGINT k;

	Equal(k, ok);


	MakeBig(unu, 1);

	// det nr de cifre (vad intre ce puteri ale lui 26 este)
	for (n = 1; n <= N; n++)
	{
		Equal(t1, Count[n - 1]);
		Equal(t2, Count[n]);
	
		Add(t1, unu);

		if (Cmp(t2, k) >= 0)
			break;
	}
	Sub(k, Count[n - 1]);

	// acum tre sa-l cautam pe al k-lea dintre cele cu n litere
	int rez = 0;
	for (i = n - 1; i >= 0; i--)
	{
		// caut acel j cu j*26^i > k, j-ul e caracterul curent
		for (j = 1; j <= 27; j++)
		{
			Equal(t1, Pow26[i]);

			IMul(t1, j);

			if ((rez = Cmp(t1, k)) >= 0)
				break;
		}
		// k -= (j - 1) * Pow26[i]

		Add(k, Pow26[i]);
		Sub(k, t1);

		res.push_back('a' + j - 1);
	}


	return res;
}


int main()
{
	scanf("%d %d", &N, &M);
	
	int i;
	string s1, s2;
	BIGINT tmp;

	MakeBig(Count[0], 1);
	MakeBig(Pow26[0], 1);
	MakeBig(tmp, 1);

	for (i = 1; i <= N; i++)
	{
		IMul(tmp, 26);

		Equal(Count[i], tmp);
		Equal(Pow26[i], tmp);

		if (i > 1)
			Add(Count[i], Count[i - 1]);
	}
	MakeBig(Count[0], 0);

	BIGINT how, l, r;

	Equal(how, Count[N]);

	int rest = IDiv(how, M);

	MakeBig(tmp, 1);
	MakeBig(l, 0);
	MakeBig(r, 0);

	// daca am rest, il distribui uniform intre primele in loc sa-l bag la ultimul procesor
	if (rest > 0) 
		Add(how, tmp);

	for (i = 1; i <= M; i++)
	{
		if (rest > 0 && i == rest + 1)
		{
			Sub(how, tmp);
		}
		Add(r, how);

		Add(l, tmp);

		if (i == M)
		{
			// la final ia cu rest cu tot
			Equal(r, Count[N]);
		}

		// avem intervalul [l, r]

		s1 = GetStringFromIndex(l);
		if (s1 == s2)
		{
			while (1);
		}
		s2 = GetStringFromIndex(r);

		printf("%s-%s\n", s1.c_str(), s2.c_str());

		Equal(l, r);
	}


	return 0;
}
