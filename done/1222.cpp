// ACM Online
// Cernobyl's eagles -> 1222
// afisati produsul maxim dintr-o descompunere a lui N
// ex: 13 = 2 + 2 + 3 + 3 + 3 -> maxim produs = 2*2*3*3*3 = 4*27 = 108

// solutie: ceva belea: e evident ca suma este formata doar din 2 si 3, altfel
// as descompune acel x > 3 intr-o suma de 2 si 3 cu produs >=.
// deci T(n) = 3^(n/3)           , n mod 3 = 0
//             4 * 3^([n/3]-1)   , n mod 3 = 1
//             2 * 3^[n/3]       , n mod 3 = 2
// unde [x] e partea intreaga...

#include <stdio.h>

int n, a[10000];

void imul(int x)
{
	int i, k = 0;
	for (i = 1; i <= a[0]; i++)
	{
		a[i] = a[i] * x + k;
		k = a[i] / 10;
		a[i] %= 10;
	}
	while (k)
		a[++a[0]] = k % 10, k /= 10;
}
void main()
{
	int i;
	a[0] = a[1] = 1;
	scanf("%d", &n);
	if (n > 1)
	switch (n % 3)
	{
		case 0: for (i = 1; i <= n / 3; imul(3), i++); break;
		case 1: for (i = 1; i <= (int)(n / 3) - 1; imul(3), i++); imul(4); break;
		case 2: for (i = 1; i <= (int)(n / 3); imul(3), i++); imul(2); break;
	}
	for (i = a[0]; i; printf("%d", a[i--]));
}