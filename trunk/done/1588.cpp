/*
 *  ACM Timus Online
 *  Problem 1588 - Jamaica
 */

#include <stdio.h>
#include <math.h>

#define MAXN	300
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

int N;
struct City
{
	int x, y;
} C[MAXN];
double Total;
bool Map[MAXN][MAXN];


double Dist(City a, City b)
{
	return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void ReadData()
{
	int i;

	//freopen("input.txt", "rt", stdin);
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &C[i].x, &C[i].y);
	}
	//fclose(stdin);
}

bool Coliniare(int i, int j, int k)
{
	return ((C[i].x - C[k].x) * (C[j].y - C[k].y) - (C[i].y - C[k].y) * (C[j].x - C[k].x)) == 0;
}

void Solve()
{
	int i, j, k;


	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			Map[i][j] = true;
		};

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
		{
			for (k = 0; k < N; k++)
				if (k != i && k != j)
				{
					if (C[k].x >= min(C[i].x, C[j].x) && C[k].x <= max(C[i].x, C[j].x) &&
						C[k].y >= min(C[i].y, C[j].y) && C[k].y <= max(C[i].y, C[j].y) && Coliniare(i, j, k))
					{
						// k e intre i si j deci i k si k j nu mai trebuie
						Map[i][k] = Map[k][i] = false;
						Map[j][k] = Map[k][j] = false;
					}
				};
		};


	Total = 0;

	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (Map[i][j])
			{
				Total += Dist(C[i], C[j]);
			};


	printf("%.0lf\n", Total);
}


int main()
{
	ReadData();
	Solve();
}
