// ACM Online
// Sum of sequential numbers - problem 1120

// fie N, un long. Gasiti doua numere a si b astfel incat
// ä(i = 0; i <= b-1) din (a + i) = N si b sa fie maxim
// adica o descompunere in termeni consecutivi cu maxim de termeni a lui N

// solutie: faza aia cu divizorii, dar mult imbunatatita

#include <stdio.h>
#include <math.h>

long n, poz, count, bpoz, bc;

void try_pair(long a, long b)
{
	long p1, p2;
	if (b % 2)
	{
		p1 = a - b / 2; p2 = a + b / 2;
		poz = (p1 <= 0) ? -p1 + 1 : p1;
		count = p2 - poz + 1;
	}
}
void main()
{
	unsigned i;
	scanf("%ld", &n);
	for (i = 1; i <= (long)sqrtl(n); i++)
		if (n % i == 0)
		{
			try_pair(i, n / i);
			if (count > bc) bpoz = poz, bc = count;
			try_pair(n / i, i);
			if (count > bc) bpoz = poz, bc = count;
		}
	printf("%ld %ld\n", bpoz, bc);
}