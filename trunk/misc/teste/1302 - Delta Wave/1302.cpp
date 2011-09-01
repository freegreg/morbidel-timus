/*
 *  ACM Timus Online Contest 27 March 2004
 *  C - Delta Wave
 */

#include <stdio.h>
#include <math.h>

#define elem(l, p) ((l - 1) * (l - 1) + p)

long A, B, Sol, Lb;



long line(long x)
{
	double sq = sqrtl(x);
	return (sq == (long)sq) ? (long)sq : (long)sq + 1;
}

int direction(long x)  /*  incotro ?  */
{
	long l, jos;

	l = line(x);
	x -= (l - 1) * (l - 1);
	jos = elem(Lb, x + Lb - l);

	return (jos > B);
}

long left(long x)
{
	double sq = sqrtl(x - 1);
	return (sq != (long)sq) ? x - 1 : 0;
}

long right(long x)
	{
	double sq = sqrtl(x);
	return (sq == (long)sq) ? 0 : x + 1;
}

long down(long x)
{
	return x + 2 * line(x);
}

int main()
{
	long al, d, s;

	scanf("%ld %ld", &A, &B);
	if (A > B)
		al = B, B = A, A = al;

	Lb = line(B); al = line(A);

	s = (A & 1 && al & 1 || A % 2 == 0 && al % 2 == 0);
	if (al == Lb) s = 2;

	for (Sol = 0; A != B; Sol++)
	{
		al = line(A); d = direction(A);
		if (al != Lb && s)
			A = down(A);
		else
		if (!s || s == 2)
			A = d ? left(A) : right(A);

		s = (al != Lb) ? 1 - s : 2;
	}

	printf("%ld\n", Sol);

	return 0;
}
