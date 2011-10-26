/*
 * ACM Timus Online Judge Contest 22 October 2011
 * Problem F - Rubinchik's Cube
 */

#include <cstdio>
#include <ctime>
#include <cstdlib>

#define ABS(n)		((n) > 0 ? (n) : -(n))

int T[4][4];
int R[4];			// orientarea (0, 1, 2, 3) fata de cfg initiala
int Sol;

bool IsTableSolved()
{
	return (T[0][0] == T[0][1] && T[0][0] == T[1][0] && T[0][0] == T[1][1]);
}

// 1 2 4 3
int Next(int value, int dir)
{
	if (value == 1)
		return (dir == 1) ? 2 : 3;
	if (value == 2)
		return (dir == 1) ? 4 : 1;
	if (value == 3)
		return (dir == 1) ? 1 : 4;
	if (value == 4)
		return (dir == 1) ? 3 : 2;
}

void Rotate(int layer, int dir)
{
	if (layer == 0)
	{
		T[0][1] = Next(T[0][1], dir);
		T[1][3] = Next(T[1][3], dir);
		T[2][0] = Next(T[2][0], dir);
		T[3][2] = Next(T[3][2], dir);
	}
	else if (layer == 1)
	{
		T[0][2] = Next(T[0][2], dir);
		T[1][0] = Next(T[1][0], dir);
		T[2][3] = Next(T[2][3], dir);
		T[3][1] = Next(T[3][1], dir);
	}
	else if (layer == 2)
	{
		T[1][1] = Next(T[1][1], dir);
		T[1][2] = Next(T[1][2], dir);
		T[2][1] = Next(T[2][1], dir);
		T[2][2] = Next(T[2][2], dir);
	}
	else if (layer == 3)
	{
		T[0][0] = Next(T[0][0], dir);
		T[0][3] = Next(T[0][3], dir);
		T[3][0] = Next(T[3][0], dir);
		T[3][3] = Next(T[3][3], dir);
	}
}

void back(int rot, int l)
{
	if (l == 5)
	{
		if (IsTableSolved() && rot < Sol)
			Sol = rot;
	}
	else
	{
		// nu-l rotim
		back(rot, l + 1);

		// rotim nivelul l de maxim 2 ori în fiecare directie
		Rotate(l, 1);
		back(rot + 1, l + 1);

		Rotate(l, 1);
		back(rot + 2, l + 1);

		// refacem mutarile
		Rotate(l, -1);
		Rotate(l, -1);

		// si rotim invers
		Rotate(l, -1);
		back(rot + 1, l + 1);

		Rotate(l, -1);
		back(rot + 2, l + 1);

		// refacem mutarile
		Rotate(l, 1);
		Rotate(l, 1);
	}
}

int Greedy()
{
	// pt fiecare din cele 4 configuratii finale calculez nr de mutari per fiecare strat. E minim oricum.
	if (T[0][1] == 1) R[0] = 0;
	else if (T[0][1] == 2) R[0] = 1;
	else if (T[0][1] == 4) R[0] = 2;
	else if (T[0][1] == 3) R[0] = 3;

	if (T[1][0] == 1) R[1] = 0;
	else if (T[1][0] == 2) R[1] = 1;
	else if (T[1][0] == 4) R[1] = 2;
	else if (T[1][0] == 3) R[1] = 3;

	if (T[1][1] == 1) R[2] = 0;
	else if (T[1][1] == 2) R[2] = 1;
	else if (T[1][1] == 4) R[2] = 2;
	else if (T[1][1] == 3) R[2] = 3;

	if (T[0][0] == 1) R[3] = 0;
	else if (T[0][0] == 2) R[3] = 1;
	else if (T[0][0] == 4) R[3] = 2;
	else if (T[0][0] == 3) R[3] = 3;

	// calculez distanta in modul a fiecarui R[i] catre solutie (0 0 0 0), (1 1 1 1), (2 2 2 2), (3 3 3 3)
	// toate fetele trebuie rotite spre aceasi directie pentru solutie.
	int i, min = 10000, d, j;
	for (i = 0; i < 4; i++)
	{
		d = 0;
		for (j = 0; j < 4; j++)
		{
			int moves = ABS(R[j] - i);
			if (moves == 3)
				moves = 1;

			d += moves;
		}
		if (d < min)
			min = d;
	}

	//printf("%d", min);

	return min;
}

void gen()
{
	srand(time(NULL));

	FILE *f = fopen("input.txt", "wt");
	int i, j;

	T[0][0] = T[0][1] = T[1][0] = T[1][1] = 1;
	T[0][2] = T[0][3] = T[1][2] = T[1][3] = 2;
	T[2][0] = T[2][1] = T[3][0] = T[3][1] = 3;
	T[2][2] = T[2][3] = T[3][2] = T[3][3] = 4;

	for (i = 0; i < 10; i++)
	{
		int lev = rand() % 4;
		int dir = (rand() % 2) ? 1 : -1;

		Rotate(lev, dir);
	}

	for (i = 0; i < 4; i++, fprintf(f, "\n"))
		for (j = 0; j < 4; j++)
			fprintf(f, "%d ", T[i][j]);
	fclose(f);
}

void Solve()
{
	int sol1 = Greedy();

	Sol = 10000;
	back(0, 0);
	//printf("%d", Sol);

	if (sol1 != Sol)
	{
		printf("ERROR");
		while(1);
	}
}

int main()
{
	do
	{
		gen();
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
	#endif
		int i, j;

		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
			{
				scanf("%d", &T[i][j]);
			};

		Solve();
	}
	while (true);
	
	return 0;
}