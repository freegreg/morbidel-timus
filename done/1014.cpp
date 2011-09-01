// ACM Online
// The Product of Digits - Problem 1014

// solutie: il descompunem pe N in factori primi si apoi: daca are un factor
// prim > 7 atunci nu e solutie. Deci trebuie sa manevram grupurile de 2 si 3
// in aceasta ordine: 222 -> 8, 33 -> 9, 23 -> 6, 22 -> 4

#include <stdio.h>

long n;
int flag[100], sol = 0;

void primi(long num)
{
	int d;
	for (d = 2; num > 1; d++)
	{
		if (d > 7 && num > 1)
		{ sol = 1; break; }
		while (num % d == 0)
			num /= d, flag[d]++;
	}
}

void main()
{
	int i, j;
	scanf("%ld", &n);
	if (n < 2)
	{
		printf(n ? "1" : "10");
		return;
	}
	primi(n);

	flag[8] += flag[2] / 3; flag[2] %= 3;                // 222
	flag[9] += flag[3] / 2; flag[3] %= 2;                // 33
	if (flag[2] && flag[3])
		flag[6]++, flag[2] -= flag[3], flag[3] = 0;      // 23
	flag[4] += flag[2] / 2; flag[2] %= 2;                // 22

	if (sol) printf("-1"); else
	for (i = 0; i < 100; i++)
		for (j = 0; j < flag[i]; j++)
			printf("%d", i);
}