/*
 *  ACM Online
 *  Square root - Problem 1132
 *
 *  solutie: sloboz, am gasit-o pe Net...
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long K, N, A;


/* Euclid extins */
long long euclid(long long a, long long b, long long &x, long long &y)
{
	long long bakx, ret;

	if (b == 0) 
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		ret = euclid(b, a % b, x, y);

		bakx = x; 
		x = y;
		y = bakx - (long long)(a / b) * y;

		return ret;
	}
}

long long modexp(long long a, long long b, long long n)
{
	long long r;

	a %= n;
	for (r = 1; b; b >>= 1, a = (a * a) % n)
		if (b & 1)
			r = (r * a) % n;

	return r;
}

long long inverse(long long a, long long n)
{
	long long x, y;

	euclid(a, n, x, y);

	while (y < 0)
		y += n;

	return y % n;
}

long long Legendre(long long a, long long n)
{
	return modexp(a, (n - 1) / 2, n);
}

long long square_root(long long a, long long n)
{
	long long b, l, s, t, ainv, c, r, p2, i, d;


	if (n == 2 || a == 1)
		return 1;
	if (n == 1)
		return 0;
	
	a %= n;
	l = Legendre(a, n);
	if (l == -1)
		return -1;
	
	/* find a quadratic non-residue */
	do
	{
		b = 1 + (rand() % (n - 1));
	}
	while (Legendre(b, n) != -1);

	/* n - 1 = 2^s * t, t odd */
	s = 0;
	t = n - 1;
	while ((t & 1) == 0)
		s++, t /= 2;

	/* compute inverse of a */
	ainv = inverse(a, n);

	c = modexp(b, t, n);
	r = modexp(a, (t + 1) / 2, n);

	p2 = (long long)1 << (s - 1);

	for (i = 1; i < s; i++)
	{
		p2 /= 2;
		d = (r * r) % n;
		d = (d * ainv) % n;
		d = modexp(d, p2, n);

		if (d == n - 1)
			r = (r * c) % n;
		c = (c * c) % n;
	}

	return (r > n - r) ? (n - r) : r;
}

long long SquareRoot_brute(long long A, long long N)
{
	long long i;

	for (i = 0; 2 * i <= N; i++)
		if ((i * i) % N == A)
			return i;
	return -1;
}

int main()
{
	long long sol;
	time_t t;
	srand((unsigned)time(&t));

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%lld", &K);
	for (; K--; )
	{
		scanf("%lld %lld", &A, &N);
		sol = square_root(A, N);
		
		if (sol == -1) 
			printf("No root\n"); 
		else
		if (sol != N - sol) 
			printf("%lld %lld\n", sol, N - sol);
		else
			printf("%lld\n", sol);
	}

	return 0;
}

