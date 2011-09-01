/*
 *  ACM Online
 *	Rope - Problem 1020
 *
 *  solutie: calcul†m distantele dintre punctele consecutive si adun†m suma
 *  unghiurilor care e chiar 2 * PI * raza cui
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846264338
#define pow2(xx) ((xx) * (xx))

FILE *f;
int n;
double rad, len = 0;
struct point
{
	double x, y;
} p[110];


double dist (int i, int j)
{
	return sqrt(pow2(p[i].x - p[j].x) + pow2(p[i].y - p[j].y));
}

int main()
{
	int i;

	scanf("%d %lf", &n, &rad);
	for (i = 0; i < n; i++)
		scanf("%lf %lf", &p[i].x, &p[i].y);
	p[n] = p[0];
	for (i = 0; i < n; i++)
		len += dist(i, i + 1);
	len += 2 * PI * rad;
	printf("%.2lf\n", len);

	return 0;
}