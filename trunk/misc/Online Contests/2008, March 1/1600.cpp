/*
 *  ACM Timus Online
 *  Airport - Problem 1600
 */

#include <stdio.h>
#include <float.h>
#include <math.h>

#define input	"input.txt"
#define MAXN	500
#define EPS		10e-9

int N, pairI, pairJ;
double Dist, Time, minTime;

struct Device
{
	double x, y, z;
	double vx, vy, vz;
} D[MAXN];


void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	int i;

	scanf("%d %lf", &N, &Dist);

	for (i = 0; i < N; i++)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &D[i].x, &D[i].y, &D[i].z, &D[i].vx, &D[i].vy, &D[i].vz);
	}
}

void Solve()
{
	int i, j;


	minTime = DBL_MAX;
	pairI = pairJ = -1;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (i != j)
			{
				double deltaX = D[i].x - D[j].x;
				double deltaY = D[i].y - D[j].y;
				double deltaZ = D[i].z - D[j].z;
				
				double deltaVX = D[i].vx - D[j].vx;
				double deltaVY = D[i].vy - D[j].vy;
				double deltaVZ = D[i].vz - D[j].vz;

				// formam coef ecuatiei de gr 2

				double a = deltaVX * deltaVX + deltaVY * deltaVY + deltaVZ * deltaVZ;
				double b = deltaX * deltaVX + deltaY * deltaVY + deltaZ * deltaVZ;
				double c = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;

				if (a == 0 && b == 0)
				{
				} else
				if (a == 0)
				{
					// bx + c = Dist * Dist;

					c = c - Dist * Dist;
					Time = -c / b;
					if (Time >= -EPS && Time < minTime)
					{
						minTime = Time;
						pairI = i;
						pairJ = j;
					}
				} else
				{
					// ecuatia este: a*t^2 + 2*b*t + c - Dist^2 = 0

					double discr = 4 * b * b - 4 * a * (c - Dist * Dist);
					if (discr >= -EPS)
					{
						discr = sqrt(discr);
						Time = (-2 * b - discr) / (2 * a);
						if (Time >= -EPS && Time < minTime)
						{
							minTime = Time;
							pairI = i;
							pairJ = j;
						}

						Time = (-2 * b + discr) / (2 * a);
						if (Time >= -EPS && Time < minTime)
						{
							minTime = Time;
							pairI = i;
							pairJ = j;
						}
					}
				}

			};

	if (minTime != DBL_MAX && pairI != -1 && pairJ != -1)
	{
		printf("ALARM!\n%.3lf %d %d\n", minTime, pairI + 1, pairJ + 1);
	} else
	{
		printf("OK\n");
	}
}

int main()
{
	ReadData();
	Solve();

	return 0;
}
