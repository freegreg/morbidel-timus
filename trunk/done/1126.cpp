// ACM Online
// Magnetic Storms - Problem 1126

// solutie: ceva belea, ideea lui Morbid...
// tinem un vector permanent descrescator si pozitiile in vector ale elem. ei
// inseram in el cu cautare binara... deci total ar fi NlogM

#include <stdio.h>

int m, n, p1, len, pr = 0, p[40000L];
long s[40000L];


void baga(int poz, int l, int r, long num)
{
	int mid, pos;
	do
	{
		mid = (l + r) / 2;
		if (num < s[mid]) l = mid + 1; else r = mid;
		if (l >= r)
			pos = r;
	}
	while (l < r);
	s[pos] = num; p[pos] = poz;
	if (pos >= len) len++;
}

int main()
{
	long i, x;

	scanf("%d", &m);
	p1 = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%ld", &x);
		baga(i, pr, pr + len, x);
		n++;
	}
	printf("%ld ", s[pr]);

	while (scanf("%ld", &x) == 1 && x != -1)
	{		
		p1++;
		if (p[pr] < p1) p[pr] = s[pr++] = -1;
		baga(n++, pr, pr + len, x);
		printf("%ld ", s[pr]);
	}

	return 0;
}
