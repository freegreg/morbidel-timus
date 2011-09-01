/*
 *  ACM Online
 *  Weird Permutations - Problem 1174 (ßy Mugurel)
 *
 *  solutie: id[n] = (id[n - 1] - 1) * n + poz[n]         , id[n - 1] par
 *                                         n - poz[n] + 1 , id[n - 1] impar
 *  id[1] = 1
 */

#include <stdio.h>

int N, P[101], Poz[101];
typedef int HUGE[160];
HUGE Id;


void out(int poz)
{
	int i;
	for (i = poz; i < Poz[0]; i++)
		P[i] = P[i + 1];
	P[Poz[0]--] = 0;
}

void imul(HUGE a, long x)
{
	long i, k = 0;
	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / 10, a[i] %= 10;
	while (k)
		a[++a[0]] = k % 10, k /= 10;
	if (!x) a[0] = 1, a[1] = 0;
}

void sub(HUGE a, int x)
{
	long i;

	a[1] -= x;
	for (i = 1; i <= a[0]; i++)
		if (a[i] < 0)
			a[i] += 10, a[i + 1]--;
	while (!a[a[0]] && a[0] > 1) a[0]--;
}

void add(HUGE a, int x)
{
	int i, k = 0;
	a[1] += x;
	for (i = 1; i <= a[0]; i++)
		k = a[i] / 10, a[i + 1] += k, a[i] %= 10;
	if (k) a[++a[0]] = k;
}

int main()
{
	int i, j, x;

	scanf("%d", &N);
	for (i = 1; i <= N; scanf("%d", P + i++));

	Poz[0] = N;
	for (j = N; j; j--)
		for (i = 1; i <= Poz[0]; i++)
			if (P[i] == j)
				Poz[j] = i, out(i), i = Poz[0];

	Id[0] = Id[1] = 1;
	for (i = 2; i <= N; i++)
	{
		x = Id[1] & 1; sub(Id, 1); imul(Id, i);
		add(Id, x ? i - Poz[i] + 1 : Poz[i]);
	}

	for (i = Id[0]; i; printf("%d", Id[i--]));
	printf("\n");

	return 0;
}

/*
 *  Am apelat la sentimente dar aveau telefonul închis...
 */
