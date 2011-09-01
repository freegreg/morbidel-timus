/*
 * ACM Timus Online
 * 1D Maze - Problem 1642
 *
 * solution: simulation on an axis
 */

#include <cstdio>

int N, X;
char V[10001];

#define V	(V + 5000)


int simulate(int dir)
{
	int d, pos, o;

	d = pos = o = 0;
	
	while (true)
	{
		if (pos == X)
		{
			break;
		}
	
		pos += dir;
		if (pos == -2000 || pos == 2000)/* reach the limits */
		{
			return -1;
		}

		d++;
	
		if (V[pos] == 1)		/* reached an obstacle */
		{
			if (o == 1)		/* second obstacle -> no solution */
			{
				return -1;
			}
			o ++;
			dir *= -1;
		}
	}

	return d;
}

int main()
{
	int i, d;
	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d %d", &N, &X);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &d);
		V[d] = 1;
	}

	int f = simulate(1);
	int b = simulate(-1);

	if (f == -1 || b == -1)
		printf("Impossible\n");
	else
		printf("%d %d\n", f, b);

	return 0;
}

