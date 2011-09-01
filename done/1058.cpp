/*
 *  ACM Timus Online
 *  Chocolate - Problem 1058
 *
 *  Solution: rotate the polygon for each angle between 0..180 and then binary 
 *  		search an axis || to Oy which splits it in two equal parts
 */

#include <cstdio>
#include <math.h>
#include <string.h>

#define PI		3.14159265358979323846364338
#define ITER		1000
#define INF		1e12
#define EPS		1e-6
#define SQR(x)		((x) * (x))
#define MIN(a, b)	((a) > (b) ? (b) : (a))
#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define NORM(i, n)	((i) < 0 ? ((i) + n) : (i) % n)

int N;
double X[64], Y[64], Sol, TotalArea;

struct Point
{
	double x, y;
} P[64], OP[64];


void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%lf %lf", &P[i].x, &P[i].y);
	}
}

double Area(int n, Point *poly)
{
	int i;
	double area = 0;

	for (i = 0; i < n; i++)
		area += poly[NORM(i, n)].x * poly[NORM(i + 1, n)].y - poly[NORM(i + 1, n)].x * poly[NORM(i, n)].y;

	return fabs(area) / 2;
}


int line_segment_cross(double a1, double b1, double c1, double x1, double y1, double x2, double y2, Point &p)
{
	/* b1 is always 0 as we're intersecting segments with a line parallel to Oy */
	/* first, determine the equation of the line of the segment */
	double a2, b2, c2;

	a2 = y1 - y2;
	b2 = x2 - x1;
	c2 = x1 * y2 - x2 * y1;

	if (b2 == 0)	/* both parallel */
		return 0;

	if (a1 * b2 == a2 * b1)
		return 0;

	p.x = (c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2);
	p.y = (-c2 - a2 * p.x) / b2;

	/* check if the intersection point is on the segment */
	return (p.x >= MIN(x1, x2) - EPS && p.x <= MAX(x1, x2) + EPS && p.y >= MIN(y1, y2) - EPS && p.y <= MAX(y1, y2) + EPS);
}

void RotatePolygon(Point *poly, int n, double angle, Point origin)
{
	int i;
	double x, y;

	for (i = 0; i < n; i++)
	{
		x = origin.x + (poly[i].x - origin.x) * cos(angle) - (poly[i].y - origin.y) * sin(angle);
		y = origin.y + (poly[i].x - origin.x) * sin(angle) + (poly[i].y - origin.y) * cos(angle);

		poly[i].x = x;
		poly[i].y = y;
	}
}

/* takes a line equation and returns the area of the left polygon resulted from the line intersection with the initial poly */
void ComputeCutAreas(double a, double b, double c, double &area, Point &p1, Point &p2, int imin)
{
	int i;
	int ok = 0, i1 = -1, i2 = -1;

	for (i = 0; i < N; i++)
	{
		if (ok == 0 && line_segment_cross(a, b, c, P[NORM(i, N)].x, P[NORM(i, N)].y, P[NORM(i + 1, N)].x, P[NORM(i + 1, N)].y, p1))
		{
			i1 = i;
			/* avoid the case where the cross is at some vertex so next line will cross also */
			if (fabs(p1.x - P[NORM(i + 1, N)].x) < EPS && fabs(p1.y - P[NORM(i + 1, N)].y) < EPS)
				i++;
			ok++;
		}
		else if (ok == 1 && line_segment_cross(a, b, c, P[NORM(i, N)].x, P[NORM(i, N)].y, P[NORM(i + 1, N)].x, P[NORM(i + 1, N)].y, p2))
		{
			i2 = i;
			ok++;
			break;
		}
	}

	if (ok != 2)
	{
		printf("invalid crossings!\n");
		while(1);
	}

	int n;
	Point pts[50];
	bool good = false;/* we reached the imin vertex -> that is the one we want to be contained in the area we compute */

	/* poly1: i1+1, ..., i2, p2, p1 */
	n = 0;
	for (i = NORM(i1 + 1, N); ; i = NORM(i + 1, N))
	{
		if (i == imin)
			good = true;
		pts[n++] = P[i];
		if (i == i2)
			break;
	}
	pts[n++] = p2;
	pts[n++] = p1;

	if (good)
		area = Area(n, pts);
	else
	{
		/* p2: i2+1, ..., i1, p1, p2 */
		n = 0;
		good = false;
		for (i = NORM(i2 + 1, N); ; i = NORM(i + 1, N))
		{
			if (i == imin)
				good = true;
			pts[n++] = P[i];
			if (i == i1)
				break;
		}
		pts[n++] = p1;
		pts[n++] = p2;

		if (good)
			area = Area(n, pts);
		else
		{
			printf("ERROR! imin is wrong!\n");
		}
	}
}

double FindCut()
{
	int i, imin = 0;
	double d, xmin, xmax;

	/* first find the margins of our binary search -> compute xmin and xmax of the polygon */
	xmin = P[0].x;
	xmax = P[0].x;

	for (i = 1; i < N; i++)
	{
		if (P[i].x < xmin)
		{
			xmin = P[i].x;
			imin = i;
		}
		if (P[i].x > xmax)
			xmax = P[i].x;
	}

	/* binary search between xmin and xmax and compute the area of the part that contains the imin (left part area).
	 * It should be equal to TotalArea/2
	 * Move the sweeping line towards the point with the greater area 
	 */
	Point p1, p2;
	double l, r, x;

	l = xmin;
	r = xmax;

	/* a parallel line between [xmin, xmax] which splits the polygon in two 
	 * parts with same area should always exists, that's why while(true) because we break when we have ar1 == ar2
	 */
	while (true)
	{
		x = (l + r) / 2;

		/* compute the equation of the line || Oy. We take two random points such as (x, 1) and (x, -1) */
		double a = 2;
		double b = 0;
		double c = -2 * x;
		double area;
		
		ComputeCutAreas(a, b, c, area, p1, p2, imin);

		if (fabs(2 * area - TotalArea) < EPS)
		{
			break;
		}
		else if (2 * area > TotalArea)
		{
			r = x;
		}
		else
		{
			l = x;
		}
	}

	/* wow, we found a solution! */
	d = sqrtl(SQR(p2.x - p1.x) + SQR(p2.y - p1.y));
	return d;
}

void Solve()
{
	int i;
	Point centroid;


	TotalArea = Area(N, P);

	/* compute centroid position */
	centroid.x = centroid.y = 0;
	
	/* method #1: wikipedia formula */
/*	for (i = 0; i < N; i++)
	{
		centroid.x += (P[i].x + P[i + 1].x) * (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
		centroid.y += (P[i].x + P[i + 1].y) * (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
	}

	centroid.x /= 6 * ar;
	centroid.y /= 6 * ar;
*/
	/* method #2: average of coordinates (wrong because of colinear points give more weight to that zone) */
	for (i = 0; i < N; i++)
	{
		centroid.x += P[i].x;
		centroid.y += P[i].y;
	}
	centroid.x /= N;
	centroid.y /= N;

	/* translate all with (-centroid.x, -centroid.y) so that the centroid is in (0, 0) - for simplicity */
/*	for (i = 0; i < N; i++)
	{
		P[i].x -= centroid.x;
		P[i].y -= centroid.y;
	}*/

#ifndef ONLINE_JUDGE
	printf("Area: %.6lf\n", TotalArea);
	printf("Centroid at (%.3lf, %.3lf)\n", centroid.x, centroid.y);
	for (i = 0; i < N; i++)
		printf("point %d: (%.6lf, %.6lf)\n", i, P[i].x, P[i].y);
#endif
	Sol = INF;

	double angle;
	double epsilon = PI / ITER;
	double dist = 0;

	/* save original polygon to rotate its nodes always */
	memcpy(OP, P, sizeof(P));

	/* [0..PI) is enough, rest is symmetry */
	for (angle = 0; angle < PI; angle += epsilon)
	{
		//printf("angle = %.3lf\n", angle * 180 / PI);
		RotatePolygon(P, N, angle, centroid);

		/* find a parallel to Oy which splits the polygon in two equal parts */
		dist = FindCut();
		if (dist < Sol)
			Sol = dist;

		/* copy back original polygon */
		memcpy(P, OP, sizeof(OP));
	}

	printf("%.6lf\n", Sol);
}


int main()
{
	ReadData();
	Solve();

	return 0;
}

