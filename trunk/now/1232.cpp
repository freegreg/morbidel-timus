/*
 *  ACM Timus Online
 *  Asteroid Landing - Problem 1232
 *
 *  solution: try to fit as many as possible straight down segments
 */

#include <cstdio>
#include <math.h>
#include <vector>

#define SQR(n)		((n) * (n))
#define ABS(n)		((n) > 0 ? (n) : -(n))
#define PI		3.14159265358979323846

int N;
double H, D, Alfa;
struct point
{
	double x, y, z;
};
std::vector<point> V;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%lf %lf %lf", &H, &D, &Alfa);

	int i;
	point p;
	double h, base = H * tan(Alfa / 2);
	double lat = sqrtl(base * base + H * H);
#ifndef ONLINE_JUDGE
	printf("lat triunghi = %.4lf\nunghi mic = %.4lf grade\nbase = %.4lf\n\n\n\n", lat, (Alfa / 2) * 57.295779506, base);
#endif

	p.x = p.y = 0;
	p.z = H;
	V.push_back(p);

	if (D > lat)
	{
		printf("-1\n");
		return 0;
	}

	if (D >= H)
	{
		double base2 = sqrtl(D * D - H * H);

		if (base2 <= base)
		{
			p.x = base2;
			p.y = 0;
			p.z = 0;

			V.push_back(p);
		} else
		{
#ifndef ONLINE_JUDGE			
			printf("base2 = %.4lf\n", base2);
#endif
			printf("case 2");
			while (1);
		}
	}
	else
	{
		N = H / D;
		if (fmod(H, D))
			N++;

		/* put straight N - 1 segments */
		for (i = 1; i < N; i++)
		{
			p.x = 0;
			p.y = 0;
			p.z = H - i * D;

			V.push_back(p);
		}

		h = H - (N - 1) * D;
		double base2 = sqrtl(D * D - h * h);

		if (base2 <= base)
		{
			/* simple case: last segment fits in the "cone" */
			p.x = base2;
			p.y = 0;
			p.z = 0;

			V.push_back(p);
		}
		else
		{
			/* we have a problem, try to change also the N-1 segments */

			if (V.size() > 1)
			{
				V.pop_back();
			}
		
			/*if (N > 2)
			{
				h = H - (N - 2) * D;
			}
			else
				h = H;
			h /= 2;

			base2 = sqrtl(D * D - h * h);
			if (base2 <= base)
			{
				p.x = base2;
				p.y = 0;
				p.z = h;

				V.push_back(p);

				p.x = 0;
				p.y = 0;
				p.z = 0;

				V.push_back(p);			
			}
			else*/
			{
				// we make segment N-1 to touch the right side and the Nth to touch the ground

				// triangle 1
				double gama = asin((N - 2) * sin(Alfa / 2));
				double delta = PI - Alfa / 2 - gama;
				double a = sin(delta) * D / sin(Alfa / 2);

				if (a > lat)
				{
					printf("a > lat !!! should not happen!\n");
					while(1);
				}

				p.x = a * sin(Alfa / 2);
				p.y = 0;
				p.z = H - a * cos(Alfa / 2);
				V.push_back(p);

				// triangle 2
				double beta = (PI - Alfa) / 2;
				double c = lat - a;

				double epsilon = asin(c * sin(beta) / D);
				double zeta = PI - beta - epsilon;
				double b = D * sin(zeta) / sin(beta);
				
				p.x = base - b;
				p.y = 0;
				p.z = 0;
				V.push_back(p);

				if (p.x < -base)
				{
					printf("Should relax 3 segments!\n");
				}
			}
		}
	}

	printf("%d\n", V.size() - 1);

	for (i = 1; i < V.size(); i++)
	{
		printf("%.4lf %.4lf %.4lf\n", V[i].x, V[i].y, V[i].z);
	}

	/* check solution */
	for (i = 0; i < V.size() - 1; i++)
	{
		double d = sqrtl(SQR(V[i].x - V[i + 1].x) + SQR(V[i].y - V[i + 1].y) + SQR(V[i].z - V[i + 1].z));
#ifndef ONLINE_JUDGE
		printf("%lf ", d);
#endif
		if (ABS(d - D) > 1e-6)
		{
			printf("ERROR, incorrect distance between points!!!\n");
			while (1);
		}
	}
	printf("\n");

	return 0;
}
