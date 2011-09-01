/*
 *  ACM Timus Online
 *  Malevich strikes back - Problem 1221
 *
 *  solutie: retinem pt. fiecare alba cate sunt albe si negre in stanga si dreapta apoi e usor...
 */

#include <stdio.h>

#define MAXN 101
#define min(a, b) ((a) > (b) ? (b) : (a))

int N, Sol;
char a[MAXN][MAXN];
struct sq
{
	char lw, lb, rw, rb;
} s[MAXN][MAXN];



void process()
{
	int i, j, k, w, b;

	/*  calculam vecinii albi si negri  */
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (!a[i][j])
			{
				w = b = 0;
				/*  stanga  */
				for (k = j - 1; k >= 0; k--)
					if (a[i][k]) b++; else
					if (!a[i][k] && !b) w++;
					else break;
				s[i][j].lb = b; s[i][j].lw = w;

				w = b = 0;
				/*  dreapta  */
				for (k = j + 1; k < N; k++)
					if (a[i][k]) b++; else
					if (!a[i][k] && !b) w++;
					else break;
				s[i][j].rb = b; s[i][j].rw = w;
				i = i;
			}
}

void solve()
{
	int i, j, k, l, lat, white, black;


	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (a[i][j] == 0) /*  consideram acest zero ca varful de sus al rombului  */
			{
				for (l = 2 * min(j, N - j) + 1; l > 0; l--)
				{
					if (l % 2 == 0) continue;
					lat = l / 2;

					/*  verific  */

					white = -1; black = lat + 1;
					for (k = i; k < i + l; k++)
					{
						if (a[k][j] == 1) break;

						if (k - i > lat)
							white--, black++;
						else
							white++, black--;

						/*  checking  */
						if (black && (s[k][j].lw != white || s[k][j].rw != white)) break;
						if (!black && (s[k][j].lw < white || s[k][j].rw < white)) break;
						if (s[k][j].lb < black || s[k][j].rb < black) break;
					}
					if (k == i + l && l > Sol)
						Sol = l;
				}
			}
}

int main()
{
	int i, j;

	//freopen("file.in", "r", stdin);

	while (1)
	{
		scanf("%d", &N);
		if (!N) break;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%d", &a[i][j]);
		Sol = 0;
		process();
		solve();

		if (Sol > 1) 
			printf("%d\n", Sol);
		else
			printf("No solution\n");
	}

	return 0;
}
