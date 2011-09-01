/*
 *  ACM Timus Online
 *  Underground - Problem 1205
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NODS 210


int N, NSol = 0, Total = 0;
double VFeet, VTube;
double A[NODS][NODS], D[NODS];
int M[NODS][NODS], Flag[NODS];
int Tata[NODS], Sol[NODS];

struct Point
{
	double x, y;
} C[NODS];



double time(Point a, Point b, double speed) // time a -> B with speed
{
	return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) / speed;
}

void readdata()
{
	int i, j;


	#ifndef ONLINE_JUDGE
	freopen("file.in", "rt", stdin);
	#endif

	scanf("%lf %lf %d", &VFeet, &VTube, &N);
	for (i = 0; i < N; i++)
		scanf("%lf %lf", &C[i].x, &C[i].y);

	while (1)
	{
		scanf("%d %d", &i, &j);
		if (!i && !j) 
			break;
		M[--i][--j] = 1;
		A[i][j] = A[j][i] = time(C[i], C[j], VTube);
	}

	scanf("%lf %lf %lf %lf", &C[N].x, &C[N].y, &C[N + 1].x, &C[N + 1].y);
}

void build_graf()
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (!M[i][j])           // we go by feet since there's no tube
				A[i][j] = A[j][i] = time(C[i], C[j], VFeet);
}

void road(int nod)
{
	if (nod == -1) 
		return;

	road(Tata[nod]);

	if (nod < N - 2) 
		Sol[NSol++] = nod;
}


void solve()
{
	double min;
	int i, j, minp, source, dest;

	N += 2;
	source = N - 2; 
	dest = N - 1;

	build_graf();

	Flag[source] = 1; Tata[source] = -1;
	for (i = 0; i < N; i++)
	{
		if (i == source) continue;
		D[i] = A[source][i];
		Tata[i] = source;
	}

	for (i = 0; i < N; i++)
	{
		min = 1000000000.;
		for(j = 0; j < N; j++)
			if(D[j] < min && !Flag[j])
			{
				minp = j;
				min = D[j];
			}
		Flag[minp] = 1;
		for (j = 0; j < N; j++)
			if(!Flag[j] && D[j] > A[minp][j] + D[minp])
			{
				D[j] = A[minp][j] + D[minp];
				Tata[j] = minp;
			}
	}

	printf("%.7lf\n", D[dest]);
	road(dest);

	printf("%d", NSol);
	for (i = 0; i < NSol; printf(" %d", Sol[i++] + 1));
	printf("\n");
}

void main()
{
	readdata();
	solve();
}