/*
 *  ACM Timus Online
 *  Good Gnusmas - Dead Gnusmas - Problem 1351
 */

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795028841971
#define sqr(a) ((a) * (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))


struct point
{
	double x, y;
} A, B, C;

double D, AngleA, AngleB, MyAngle;
long N;



double Angle(point c)
{
	double phi;

	if (c.x == 0)
		phi = (c.y > 0) ? (PI / 2) : (3 * PI / 2);
	else
	{
		phi = atan(abs(c.y / c.x));

		if (c.x < 0 && c.y >= 0)
			phi = PI - phi;
		else
		if (c.x < 0 && c.y < 0)
			phi += PI;
		else
		if (c.x >= 0 && c.y < 0)
			phi = 2 * PI - phi;
	}

	return phi * 180 / PI;
}


int inside(point c)
{
	if (c.x * c.x + c.y * c.y > D * D) return 0;

	MyAngle = Angle(c);

	if (MyAngle == 0 && AngleB == 360)
		return 1;

	return (MyAngle >= AngleA && MyAngle <= AngleB);
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	scanf("%lf %lf %lf %lf %lf", &D, &A.x, &A.y, &B.x, &B.y);


	AngleA = Angle(A);
	AngleB = Angle(B);
	if (AngleB == 0 && AngleA != 0)
		AngleB = 360;

	if (AngleA > AngleB)
		MyAngle = AngleA, AngleA = AngleB, AngleB = MyAngle;

	for (scanf("%d", &N); N--; )
	{
		scanf("%lf %lf", &C.x, &C.y);

		printf("%s\n", inside(C) ? "YES" : "NO");
	}


	return 0;
}
