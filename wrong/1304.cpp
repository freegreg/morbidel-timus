/*
 *  ACM Timus Online
 *  Parallelepiped - Problem 1304
 *
 *  solutie: back 6^n
 */

#include <stdio.h>

double dVolume = 0, dX, dY, dZ;
int N;
struct point
{
	double x, y, z;
} Points[1001];


void readdata()
{
}

void back(double x1, double y1, double z1, double x2, double y2, double z2)
{
	bool bNude = true;
	double dvol = (x2 - x1) * (y2 - y1) * (z2 - z1);

	if (dvol < dVolume)
		return;

	for (int i = 0; i < N; i++)
		if (Points[i].x > x1 && Points[i].x < x2 && Points[i].y > y1 && Points[i].y < y2 && Points[i].z > z1 && Points[i].z < z2)
		{
			bNude = false;
			// z
			back(x1, y1, z1, x2, y2, Points[i].z);
			back(x1, y1, Points[i].z, x2, y2, z2);
			// x
			back(Points[i].x, y1, z1, x2, y2, z2);
			back(x1, y1, z1, Points[i].x, y2, z2);
			// y
			back(x1, Points[i].y, z1, x2, y2, z2);
			back(x1, y1, z1, x2, Points[i].y, z2);
		}
	if (bNude && dvol > dVolume)
		dVolume = dvol;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("file.in", "r", stdin);
	#endif

	scanf("%lf %lf %lf %d", &dX, &dY, &dZ, &N);
	for (int i = 0; i < N; i++)
		scanf("%lf %lf %lf", &Points[i].x, &Points[i].y, &Points[i].z);

	back(0, 0, 0, dX, dY, dZ);

	printf("%.2lf\n", dVolume);


	return 0;
}
