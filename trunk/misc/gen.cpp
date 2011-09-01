// generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define input "file.in"

long pr[100100L];


void ciur()
{
	int i, j, nmax = 30000L;

	for (i = 2; i <= nmax / 2; i++)
		for (j = 2; j <= nmax / i; j++)
			pr[i * j] = 1;
	for (pr[0] = 0, i = 2; i <= nmax; i++)
		if (!pr[i])
			pr[++pr[0]] = i;
}

void write_numbers()
{
	long m, n;
	double a, b;

	a = rand() % 10000; a *= rand() % 10000;
	b = rand() % 10000; b *= rand() % 10000;
	a /= 10000;
	b /= 10000;

	if (rand() % 10 == 0)
		a *= -1;
	if (rand() % 10 == 0)
		b *= -1;
	n = 1 + rand() % 10000;

	freopen("file.in", "w", stdout);
	printf("%.2lf %.lf\n%ld\n", a, b, n);
}

void write_vector()
{
	char ss[5] = "AEFW";
	long i, h, m, s, pow, l1, l2;

	//scanf("%ld %ld", &l1, &l2);

	freopen("file.in", "w", stdout);

	for (i = 0; i < 4; i++)
	{
		printf("%c ", ss[i]); 
		h = rand() % 24; m = rand() % 60; s = rand() % 60; pow = 5000 + rand() % 5000;
		printf("%02d:%02d:%02d %d ", h, m, s, pow);
		h = rand() % 24; m = rand() % 60; s = rand() % 60; pow = 1 + rand() % 5000;
		printf("%02d:%02d:%02d %d ", h, m, s, pow);
		printf("\n");
	}
	l1 = 500 + rand() % 500;
	l2 = 1+rand()% 1000;
	for (i = 0; i < l1; i++)
		printf("%c", ss[rand() % 4]);
	printf("\n");

	for (i = 0; i < l2; i++)
		printf("%c", ss[rand() % 4]);
	printf("\n");
}

void write_matrix()
{
	long i, j, m, n, a;

	scanf("%ld %ld", &n, &m);

	freopen("file.in", "w", stdout);
	printf("%ld %ld\n", n, m);

	for (i = 0; i < n; i++, printf("\n"))
		for (j = 0; j < m; j++)
		{
			a = rand() % 100L;
			printf("%ld ", a);
		}
}

int main()
{
	time_t t;
	srand((unsigned) time(&t)); /*  randomize  */

	//ciur();
	//write_numbers();
	write_vector();
	// write_matrix();
	return 0;
}
