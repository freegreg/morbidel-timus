/*
 *  ACM Timus Online
 *  Genie Bomber - Problem 1332
 */

#include <stdio.h>
#include <math.h>

#define sqr(x) ((x) * (x))
#define min(a, b) ((a) > (b) ? (b) : (a))


int N, Sol = 0;
double R, r;
struct point
{
	double x, y;
} P[101];



void readdata()
{
	int i;


	#ifndef ONLINE_JUDGE
		freopen("file.in", "r", stdin);
	#endif

	for (scanf("%d", &N), i = 0; i < N; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);

	scanf("%lf %lf", &R, &r);
}

double Euclid_Distance(point p1, point p2)
{
	return sqrtl(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));
}

void compute_circles(point p1, point p2, point &c1, point &c2)
{
	double sin_alpha, cos_alpha, deltax, deltay, d, x, midx, midy;


	x = Euclid_Distance(p1, p2);
	d = sqrt(R * R - x * x / 4);

	midx = (p1.x + p2.x) / 2;
	midy = (p1.y + p2.y) / 2;

	if (d <= 0.0001)
	{
		c1.x = c2.x = midx;
		c1.y = c2.y = midy;

		return;
	}

	if (p1.x <= p2.x && p1.y <= p2.y || p1.x >= p2.x && p1.y >= p2.y)
	{
		c1.x = midx - 2 * d * (midy - min(p1.y, p2.y)) / x;
		c1.y = midy + d * sqrtl(1 - 4 * sqr(midy - min(p1.y, p2.y)) / x / x);

		c2.x = midx + fabs(midx - c1.x);
		c2.y = midy - fabs(midy - c1.y);
	} else
	{
		c1.x = midx + d * sqrtl(1 - 4 * sqr(midx - min(p1.x, p2.x)) / x / x);;
		c1.y = midy + 2 * d * (midy - min(p1.x, p2.x)) / x;

		c2.x = midx - fabs(midx - c1.x);
		c2.y = midy - fabs(midy - c1.y);
	}
}

void solve()
{
	point c1, c2;
	int i, j, k, now1, now2;


	if (R < r)
		Sol = 0;
	else
	if (R == r)
		Sol = 1;

	R -= r;

	if (R > 0)
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
		{
			if (2 * R < Euclid_Distance(P[i], P[j])) 
				continue;

			compute_circles(P[i], P[j], c1, c2);
		
			now1 = now2 = 0;
			for (k = 0; k < N; k++)
			{
				if (Euclid_Distance(P[k], c1) <= R)
					now1++;
				if (Euclid_Distance(P[k], c2) <= R)
					now2++;
			}
			if (now1 > Sol)
				Sol = now1;
			if (now2 > Sol)
				Sol = now2;
		}
	if (R > 0 && Sol == 0)
		Sol = 1;

	printf("%d\n", Sol);
}


int main()
{
	readdata();
	solve();

	return 0;
}
