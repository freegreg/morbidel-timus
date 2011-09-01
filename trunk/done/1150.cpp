// ACM Online
// Number of Digits - Problem 1150

// de cate ori apare fiecare cifra de la 1 la N (N < 2mld.)
// solutie: rezolvam o problema mai simpla: de cate ori apare cifra x (0..9)
// in intervalul 1..N ?

#include <stdio.h>
#include <string.h>

long n, flag[500], nr[500], cat[500], l1, l2;
struct set
{
	long a, b;
} s1[500], s2[500];


void crash()
{
	memset(NULL, 0, -666);
}

void baga(long l, long r)
{
	long i, x, bl = l, br = r, prod = 1;
	
	l2 = 0;
	while (bl && br)
	{
		s2[l2].a = bl % 10; s2[l2].b = br % 10;
		bl /= 10; br /= 10;
		cat[l2++] = s2[l2].b - s2[l2].a + 1;
		prod *= cat[l2 - 1];
	}
	for (x = 0; x < 10; x++)     // cifra
		for (i = 0; i < l2; i++)
			if (s2[i].a <= x && x <= s2[i].b)
				flag[x] += prod / cat[i];   // in sfarsit!
}

int main()
{
	long i, j, n1, n2;

	scanf("%ld", &n);

	memset(flag, 0, sizeof(flag));
	i = n; nr[0] = 0;
	while (i)
		nr[++nr[0]] = i % 10, i /= 10;
	for (i = 1; 2 * i <= nr[0]; i++)
		j = nr[i], nr[i] = nr[nr[0] - i + 1], nr[nr[0] - i + 1] = j;
	for (l1 = i = 0; i < nr[0] - 1; i++)
		s1[l1].a = i ? (s1[l1 - 1].b + 1) : 1, s1[l1].b = s1[l1++].a * 10 - 1;
	for (n2 = i = 1; i <= nr[0]; i++)
	{
		n1 = n2 = 0;
		for (j = 1; j <= i - 1; j++)
			n1 = n1 * 10 + nr[j];
		if (i == 1) 
			n1 = 1;
		for (j = 0; j <= nr[0] - i; j++, n1 *= 10);
		if (i == 1) 
			n1 /= 10;
		for (j = 1; j <= i; j++)
			n2 = n2 * 10 + nr[j];
		for (j = 0; j < nr[0] - i; j++, n2 *= 10);
		if (n1 == n2 && i != nr[0]) 
			continue;
		s1[l1].a = n1; s1[l1++].b = --n2;
	}
	s1[l1 - 1].b++;

	for (i = 0; i < l1; i++)
		baga(s1[i].a, s1[i].b);

	for (i = 0; i < 10; i++)
		printf("%ld\n", flag[i]);

	return 0;
}



