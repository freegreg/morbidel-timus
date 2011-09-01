/*
 *	ACM Timus Online
 *	Sorting the tombstones - Problem 1252
 *	
 *	solutie: sortez numerele si retin permutarea pozitiilor. Apoi pentru fiecare element vad distanta pe 
 *	care trebuie s-o parcurga pana la pozitia sa finala, fie ea (distanta) x. Evident ca pot ajunge acolo
 *	facand pasi de lungime y, y divizor al lui x (clar!). Cresc pe un vector toti divizorii si solutia este
 *	cel mai mare numar bifat de N ori.
 */

#include <stdio.h>

#define MAXN 130500

long N, Sol1, Sol2;
long Flag[MAXN];


long cmmdc(long a, long b)
{
	return b ? cmmdc(b, a % b) : a;
}

int main()
{
	long i, x, num;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	scanf("%ld", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%ld", &x);
		Flag[x] = i;
	}

	Sol1 = Sol2 = 0;
	for (x = i = 0; i < MAXN; i++)
		if (Flag[i])
		{
			num = ++x - Flag[i];
			if (num < 0) num = -num;
			if (!num) continue;

			Sol1 = Sol1 ? cmmdc(Sol1, num) : num;
		}

	Sol1--;

	for (x = 0, i = MAXN; i >= 0; i--)
		if (Flag[i])
		{
			num = ++x - Flag[i];
			if (num < 0) num = -num;
			if (!num) continue;

			Sol2 = Sol2 ? cmmdc(Sol2, num) : num;
		}

	Sol2--;

	if (Sol1 < 0)
		Sol1 = N - 1;
	if (Sol2 < 0)
		Sol2 = N - 1;
	printf("%ld\n", (Sol1 > Sol2) ? Sol1 : Sol2);

	return 0;
}
