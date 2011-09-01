/*
 *  ACM Timus Online
 *  Bricks - Problem 1234
 */

#include <stdio.h>
#include <math.h>

#define min(a, b)	((a) > (b) ? (b) : (a))
#define Pi			3.1415926535897932384626433832795028841971
#define abs(x)		((x) > 0 ? (x) : -(x))
#define STEP		1e-4

double A, B, C, D, E, foo, c = cos(STEP), s = sin(STEP);
int Ok;
struct point
{
	double x, y;
} P[4];


void rotate(point &p)
{
	double x = p.x, y = p.y;

	p.x = x * c - y * s;
	p.y = x * s + y * c;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("file.in", "rt", stdin);
	#endif

	scanf("%lf %lf %lf %lf %lf", &A, &B, &C, &D, &E);

	if (A > B) foo = A, A = B, B = foo;
	if (A > C) foo = A, A = C, C = foo;
	if (B > C) foo = B, B = C, C = foo;
	if (D > E) foo = D, D = E, E = foo;

	if (A > D) Ok = 0;
	else
	if (A <= D && B <= E) Ok = 1;
	else
	{
		double alfa;

		P[0].x = -0.5 * B; P[0].y = -0.5 * A;
		P[1].x = -0.5 * B; P[1].y = 0.5 * A;
		P[2].x = 0.5 * B; P[2].y = 0.5 * A;
		P[3].x = 0.5 * B; P[3].y = -0.5 * A;

		for (alfa = 0; 2 * alfa < Pi; alfa += STEP)
		{
			rotate(P[0]);
			rotate(P[1]);
			rotate(P[2]); 
			rotate(P[3]);

			Ok = 1;
			for (int i = 0; i < 4; i++)
				if (2 * abs(P[i].x) > E || 2 * abs(P[i].y) > D)
					i = 5, Ok = 0;
			if (Ok) 
				break;
		}
	}

	printf("%s\n", Ok ? "YES" : "NO");

	return 0;
}
