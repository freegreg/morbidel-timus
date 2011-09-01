/*
 *  ACM Timus Online
 *  Exactness of projectile hit - Problem 1215
 *
 *  solutie: caut binar raza aia... si o pun 0 cand e in interior
 */

#include <stdio.h>
#include <math.h>

__int64 N, X, Y, PX[101], PY[101];
double R;



void readdata()
{
	int i;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	scanf("%I64d %I64d %I64d", &X, &Y, &N);
	for (i = 1; i <= N; i++)
		scanf("%I64d %I64d", PX + i, PY + i);
	PX[N + 1] = PX[1]; PY[N + 1] = PY[1];
	PX[0] = X; PY[0] = Y;
}

double Euclid(__int64 x1, __int64 y1, __int64 x2, __int64 y2)
{
	return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double arie_triunghi(__int64 p1, __int64 p2, __int64 p3)
{
	double ar = (double)((PX[p1] - PX[p2]) * (PY[p2] - PY[p3]) - (PX[p2] - PX[p3]) * (PY[p1]- PY[p2])) / 2;

	return (ar > 0) ? ar : -ar;
}

__int64 inside_golygon()
{
	int i;
	double ariep = 0, ariet = 0;

	for (i = 1; i <= N; i++)
		ariep += PX[i] * PY[i + 1] - PX[i + 1] * PY[i];
	ariep /= 2;
	if (ariep < 0)
		ariep = -ariep;

	for (i = 1; i <= N; i++)
		ariet += arie_triunghi(0, i, i + 1);

	return (abs(ariet - ariep) < 0.0001);
}

/*  verifica raza  */
int good()
{
	int i, semn;
	double a, b, c, x1, x2, y1, y2, dist;

	for (i = 1; i <= N; i++)
	{
		x1 = PX[i]; y1 = PY[i]; x2 = PX[i + 1]; y2 = PY[i + 1];
		/*  capetele in cerc  */
		if (Euclid(x1, y1, X, Y) < R || Euclid(x2, y2, X, Y) < R) return 0;

		a = y1 - y2; b = x2 - x1; c = x1 * y2 - x2 * y1;
		dist = (a * X + b * Y + c) / sqrtl(a * a + b * b);
		if (dist < 0) dist = -dist;
		
		if (dist < R)
		{
			/*  trag perp. de dreapta si vad semnul punctelor fata de ea  */
			a = x1 - x2; b = y1 - y2; c = X * (x2 - x1) + Y * (y2 - y1);
			semn = (a * x1 + b * y1 + c) * (a * x2 + b * y2 + c) < 0;
			if (y1 == y2 && y1 == Y && (x1 < X && x2 > X || x1 > X && x2 < X)) 
				semn = 1;
			if (semn) return 0;
		}
	}

	return 1;
}

void solve()
{
	double l, r, eps;

	eps = 1e-4;
	l = 0; r = 1500000;

	do
	{
		R = (l + r) / 2;
		if (good())
			l = R + eps;
		else
			r = R - eps;
	}
	while (l < r);

	if (inside_golygon())
		R = 0;

	printf("%.3lf\n", 2 * R);
}

int main()
{
	readdata();
	solve();

	return 0;
}
