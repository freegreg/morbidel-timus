/*
 *  ACM Timus Online
 *  Genie bomber 2 - Problem 1333
 *
 *  solutie: baleiem din 0.0001 si verific daca e in vreun cerc :)
 */

#include <stdio.h>
#include <math.h>

#define EPS		1e-4
#define EPS2	1e-2
#define sqr(x) ((x) * (x))


double dArea = 0;
int N;
struct circle
{
	double x, y, rad;
} C[50];




void readdata()
{
	#ifndef ONLINE_JUDGE
		freopen( "file.in", "r", stdin);
	#endif

	scanf( "%d", &N);

	for ( int i = 0; i < N; i++)
		scanf( "%lf %lf %lf", &C[i].x, &C[i].y, &C[i].rad);
}

double Euclid(double dx1, double dy1, double dx2, double dy2)
{
	return sqrtl(sqr(dx2 - dx1) + sqr(dy2 - dy1));
}

void solve()
{
	bool bInside;
	double dx, dy;
	int i;

	for (dx = EPS; dx < 1; dx += EPS2)
		for (dy = EPS; dy < 1; dy += EPS2)
		{
			bInside = false;
			for (i = 0; i < N; i++)
				if (Euclid(dx, dy, C[i].x, C[i].y) <= C[i].rad)
				{
					bInside = true;
					break;
				}

			if (!bInside)
				dArea += EPS;
		}

	printf("%.7lf\n", 100 - dArea * 100);
}


int main()
{
	readdata();
	solve();

	return 0;
}
