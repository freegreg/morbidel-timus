/*
 *  ACM Timus Online
 *  Starship travel - Problem 1286
 *
 *  solutie: translatez sistemul in coord. (0, 0) apoi pot ajunge in (a, b) doar daca d = (p, q) divide si pe a si pe b.
 *  ma rog si ceva cu paritati...
 */

#include <stdio.h>

__int64 P, Q, SL, SC, X, Y;


__int64 cmmdc(__int64 a, __int64 b)
{
	return !b ? a : cmmdc(b, a % b);
}

int main()
{
	__int64 d;

	scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &P, &Q, &SL, &SC, &X, &Y);

	X -= SL; Y -= SC;
	if (X < 0) X = -X;
	if (Y < 0) Y = -Y;

	d = cmmdc(P, Q);

	if (X % d || Y % d) 
	{
		printf("NO\n");
		return 0;
	}

	X /= d; Y /= d; P /= d; Q /= d;

    if (!((P + Q) % 2 == 0 && (X + Y) % 2))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
