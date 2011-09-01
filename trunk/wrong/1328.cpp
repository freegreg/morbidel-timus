/*
 *  ACM Timus Online
 *  Fireball - Problem 1328
 */

#include <stdio.h>
#include <math.h>

#define input		"file.in"
#define INF			1000000
#define PI			3.1415926535897932384626433832795028841971
#define	EPS			0.0001
#define min(a, b)	((a) > (b) ? (b) : (a))
#define max(a, b)	((a) > (b) ? (a) : (b))
#define sqr(x)		((double)(x) * (x))


struct point
{
	double x, y;
} A, B, P[5];

long N, W, H, Alpha;
double Angle;



// outputs line equation by two points
void ABC(point p1, point p2, double &a, double &b, double &c)
{
	a = p1.y - p2.y; 
	b = p2.x - p1.x;
	c = p1.x * p2.y - p2.x * p1.y;
}


// point inside a box
bool InBox(point p1, point p2, point p3)
{
	return ((p3.x >= min(p1.x, p2.x) && p3.x <= max(p1.x, p2.x)) && 
			(p3.y >= min(p1.y, p2.y) && p3.y <= max(p1.y, p2.y)));
}


// segment intersection
bool Cross(point p1, point p2, point p3, point p4, point &c)
{
	double a1, b1, c1, a2, b2, c2, numit;

	ABC(p1, p2, a1, b1, c1);
	ABC(p3, p4, a2, b2, c2);

	numit = a1 * b2 - a2 * b1;
	if (numit == 0)
		return false;

	c.x = (b1 * c2 - b2 * c1) / numit;
	c.y = -(a1 * c2 - a2 * c1) / numit;

	return (InBox(p1, p2, c) && InBox(p3, p4, c));
}


//  returns the wall and coordinates of intersection for one line (p1p2)
short Wall(int shit, point p1, point p2, point &c)
{
	int wall;

	for (wall = 0; wall < 4; wall++)
		if (wall != shit && Cross(P[wall], P[wall + 1], p1, p2, c))
			return wall;

	return -1;
}

// p3 is on the segment p1p2
bool OnLine(point p1, point p2, point p3)
{
	double a, b, c;

	ABC(p1, p2, a, b, c);

	return (fabs(a * p3.x + b * p3.y + c) < EPS) && InBox(p1, p2, p3);
}


bool solve(double angle)
{
	point p1, p2, cross;
	int i, sx, sy, wall = -1;

	if (2 * angle <= PI)
		sx = 1, sy = 1;
	else
	if (angle <= PI)
		sx = -1, sy = 1, angle -= PI / 2;
	else
	if (2 * angle <= 3 * PI)
		sx = -1, sy = -1, angle -= PI;
	else
	if (angle <= 2 * PI)
		sx = 1, sy = -1, angle -= 3 * PI / 2;

	double tang = (angle * 2 == PI) ? INF : tan(angle);
	for (p1 = A, i = 0; i <= N; i++, p1 = (i <= N) ? cross : p1)
	{
		p2.x = p1.x + INF * sx;
		p2.y = p1.y + tang * INF * sy;
		if (tang == INF)
			p2.x = p1.x, p2.y = INF * sy;

		wall = Wall(wall, p1, p2, cross);

		if (OnLine(p1, p2, P[0]) || OnLine(p1, p2, P[1]) || OnLine(p1, p2, P[2]) || OnLine(p1, p2, P[3]))
			i++, sx *= -1, sy *= -1;
		else
		switch (wall)
		{
			case 0: sy *= -1; break;
			case 1: sx *= -1; break;
			case 2: sy *= -1; break;
			case 3: sx *= -1; break;
		}
	}

	// we've done N + 1 bumps. We check if B is on this last line
	double a, b, c;
	ABC(p1, p2, a, b, c);


	return (fabs(a * B.x + b * B.y + c) < EPS) && InBox(p1, p2, B);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
#endif

	scanf("%d %d %d", &W, &H, &N);
	scanf("%lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y);


	P[0].x = W; P[0].y = H;
	P[1].x = 0; P[1].y = H;
	P[2].x = 0; P[2].y = 0;
	P[3].x = W; P[3].y = 0;
	P[4] = P[0];

	for (Alpha = 0; Alpha < 360; Alpha++)
		for (Angle = 0; Angle < 1; Angle += 0.01)
			if (solve(((double)Alpha + Angle) * PI / 180))
			{
				printf("%.2lf\n", (double)Alpha + Angle);
				Alpha = 1000;
				break;
			}

	return 0;
}
