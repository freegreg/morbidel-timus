/*
 *  ACM Timus Online
 *  Squares - Problem 1111
 */

#include <stdio.h>
#include <math.h>

#define input		"file.in"
#define INF			999999
#define EPS			1e-14
#define Pi			3.1415926535897932384626433832795028841971
#define Rad2		1.4142135623730950488016887242097
#define MAXN		101
#define min(a, b)	((a) > (b) ? (b) : (a))

int N;
struct point
{
	double x, y;
} S[MAXN][5], P;
double D[MAXN];
int Index[MAXN];




double dist(point A, point B)
{
	return sqrtl((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int AcuteTriangle(point A, point B, point C)
{
	double a, b, c;

	a = dist(B, C);
	b = dist(C, A);
	c = dist(A, B);
	if (a >= b + c || b >= a + c || c >= a + b)
		return 0;

	if (b * b + c * c < a * a) return 0;
	if (c * c + a * a < b * b) return 0;

	return 1;
}

void MakePoints(point p1, point &p2, point p3, point &p4)
{
	double dx, dy;
	point po;

	po.x = (p1.x + p3.x) / 2;
	po.y = (p1.y + p3.y) / 2;
	dx = p1.x - po.x;
	dy = p1.y - po.y;

	p2.x = po.x - dy;
	p2.y = po.y + dx;

	p4.x = po.x + dy;
	p4.y = po.y - dx;
}

void readdata()
{
	int i;


	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%lf %lf %lf %lf", &S[i][0].x, &S[i][0].y, &S[i][2].x, &S[i][2].y);
		MakePoints(S[i][0], S[i][1], S[i][2], S[i][3]);
		S[i][4] = S[i][0];
	}
	scanf("%lf %lf", &P.x, &P.y);
}

double arie(point p1, point p2, point p3)
{
	return fabs(0.5 * ((p1.x - p2.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p2.y)));
}

int cross(point s1, point s2, point d1, point d2)
{
	double a, b, c;

	a = d2.y - d1.y;
	b = d1.x - d2.x;
	c = -d1.x * d2.y + d2.x * d1.y;
	int sgn1 = (s1.x * a + s1.y * b + c) < EPS;
	int sgn2 = (s2.x * a + s2.y * b + c) < EPS;
	
	a = s2.y - s1.y;
	b = s1.x - s2.x;
	c = -s1.x * s2.y + s2.x * s1.y;
	int sgn3 = (d1.x * a + d1.y * b + c) < EPS;
	int sgn4 = (d2.x * a + d2.y * b + c) < EPS;

	return sgn1 != sgn2 && sgn3 != sgn4;
}

double Final_dist(point p, int k)
{
	point P2;
	int i, crs = 0, acute = 0;
	double ar, sol = INF, d = dist(S[k][0], S[k][1]);

	if (S[k][0].x == S[k][2].x && S[k][0].y == S[k][2].y)
		return dist(p, S[k][0]);

	P2.x = p.x; P2.y = INF;
	for (i = 0; i < 4; i++)
	{
		crs += cross(S[k][i], S[k][i + 1], p, P2);
		ar = arie(S[k][i], S[k][i + 1], p);
		if (AcuteTriangle(S[k][i], S[k][i + 1], p))
		{
			acute = 1;
			if (d * sol > 2 * ar)
				sol = 2 * ar / d;
		}
	}

	if (!acute) // obtuse
		for (i = 0; i < 4; i++)
			sol = min(sol, dist(p, S[k][i]));

	if (crs & 1)
		sol = 0;

	return sol;
}

void solve()
{
	int i, j, k;

	for (i = 0; i < N; i++)
	{
		Index[i] = i;
		D[i] = Final_dist(P, i);
	}

	double aux;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (D[i] > D[j])
			{
				k = Index[i]; Index[i] = Index[j]; Index[j] = k;
				aux = D[i]; D[i] = D[j]; D[j] = aux;
			} else 
			if (fabs(D[i] - D[j]) <= EPS && Index[i] > Index[j])
				k = Index[i], Index[i] = Index[j], Index[j] = k;


	for (i = 0; i < N; i++)
		printf("%d ", Index[i] + 1);
}


int main()
{
	readdata();
	solve();

	return 0;
}
