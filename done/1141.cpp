/*
 *  ACM Timus Online
 *  RSA Attack - Problem 1141
 *
 *  solutie: mate la greu, am luat-o de la Danet...
 */


#include <stdio.h>

int c, e, n, k, t, d, q, p, pow[100];


void gcd (int a, int b)
{
	int bx;

	if (!b)
	{
		d = 1; q = 0;
		return;
	}

	gcd(b, a % b);

	bx = d; d = q;
	q = bx - (a / b) * q;
}

int main()
{
	int i, j;

	scanf("%d", &k);
	for ( ; k--; )
	{
		scanf("%d %d %d", &e, &n, &c);
		for (i = 2; i <= n; i++)
			if (n % i == 0)
				p = i, i = n;
		q = n / p;

		t = (p - 1) * (q - 1);
		gcd(e, t);
		if (d < 0) 
			d += t;

		t = pow[0] = c;
		for (i = q = 1; i * 2 <= d; i *= 2, q++)
			t = (t * t) % n, pow[q] = t;

		for (j = i, q--; q >= 0; q--, i /= 2)
			if (j + i <= d)
				t = (t * pow[q]) % n, j += i;

		printf("%d\n", t);
	}

	return 0;
}
