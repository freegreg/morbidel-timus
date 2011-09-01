/*
 *  ACM Timus Online
 *  Fence - Problem 1159
 */

#include <stdio.h>
#include <math.h>

#define input	"file.in"
#define MAXN	110
#define Pi		3.14159265358979323846264338327950288
#undef EPS
#define EPS		1e-9
#define min(a, b)	((a) > (b) ? (b) : (a))
#define max(a, b)	((a) > (b) ? (a) : (b))


FILE *f;
int N;
double L[MAXN];
double Angle[MAXN], Arie[MAXN];
double R, Sum = 0, AngleSum, ArieMax = 0;


void readdata()
{
	int i;

	#ifndef ONLINE_JUDGE
	freopen(input, "rt", stdin);
	#endif

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &L[i]);
		Sum += (double)L[i];
	}
}

double Find(int mode)
{	
	int i, sol = 0;
	double limit = mode ? 0 : 2 * Pi;
	double arie_totala;
	double l = 0, r = 5000;

	while (l + EPS < r)
	{
		R = (l + r) / 2;

		arie_totala = AngleSum = 0;
		if (L[0] > 2 * R + EPS)
		{
				l = R;
				continue;
		}
		else
		for (i = 0; i < N; i++)
		{
			Angle[i] = 2 * asin(min(L[i] / (2 * R), 1));
			Arie[i] = R * R * sin(Angle[i]) / 2;

			arie_totala += Arie[i];
			AngleSum += Angle[i];
		}
		if (mode)
			AngleSum -= 2 * Angle[0], arie_totala -= 2 * Arie[0];

		if (!mode)
		{
			if (AngleSum > limit + EPS) l = R;
			else
			if (AngleSum < limit - EPS) r = R;
			else 
			{
				sol = 1; break;
			}
		} else
		{
			if (fabs(AngleSum) < EPS)
			{
				sol = 1; break;
			} else
			if (AngleSum < limit + EPS) l = R;
			else
			if (AngleSum > limit - EPS) r = R;
		}
	}

	return !sol ? 0 : arie_totala;
}

void solve()
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (L[i] < L[j])
				ArieMax = L[i], L[i] = L[j], L[j] = ArieMax;

	Sum /= 2;
	for (i = 0; i < N; i++)
		if (L[i] >= Sum)
		{
			printf("0.00\n");

			return;
		}

	double a0 = Find(1);
	double a1 = Find(0);

	ArieMax = max(a0, a1);

	printf("%.2lf\n", ArieMax);
}

int main()
{
	readdata();
	solve();

	return 0;
}
