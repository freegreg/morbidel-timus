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

// dir =  1 -> trigonometric
// dir = -1 -> orar
void Rotate(int layer, int dir)
{
	if (layer == 0)
	{
    int old = T[0][1];
    if (dir == 1)
    {
		  T[0][1] = T[1][3];
  		T[1][3] = T[3][2];
	  	T[3][2] = T[2][0];
		  T[2][0] = old;
    }
    else
    {    
		  T[0][1] = T[2][0];
  		T[2][0] = T[3][2];
	  	T[3][2] = T[1][3];
		  T[1][3] = old;
    }
	}
	else if (layer == 1)
	{
		int old = T[1][0];
    if (dir == 1)
    {
		  T[1][0] = T[0][2];
  		T[0][2] = T[2][3];
	  	T[2][3] = T[3][1];
		  T[3][1] = old;
    }
    else
    {    
		  T[1][0] = T[3][1];
  		T[3][1] = T[2][3];
	  	T[2][3] = T[0][2];
		  T[0][2] = old;
    }
	}
	else if (layer == 2)
	{
		int old = T[1][1];
    if (dir == 1)
    {
		  T[1][1] = T[1][2];
  		T[1][2] = T[2][2];
	  	T[2][2] = T[2][1];
		  T[2][1] = old;
    }
    else
    {    
		  T[1][1] = T[2][1];
  		T[2][1] = T[2][2];
	  	T[2][2] = T[1][2];
		  T[1][2] = old;
    }
	}
	else if (layer == 3)
	{
		int old = T[0][0];
    if (dir == 1)
    {
		  T[0][0] = T[0][3];
  		T[0][3] = T[3][3];
	  	T[3][3] = T[3][0];
		  T[3][0] = old;
    }
    else
    {    
		  T[0][0] = T[3][0];
  		T[3][0] = T[3][3];
	  	T[3][3] = T[0][3];
		  T[0][3] = old;
    }
	}
}

void back(int rot, int l)
{
	if (l == 4)
	{
		if (IsTableSolved() && rot < Sol)
			Sol = rot;
	}
	else
	{
		// nu-l rotim
		back(rot, l + 1);

		// rotim nivelul l de maxim 2 ori Ã®n fiecare directie
		Rotate(l, 1);
		back(rot + 1, l + 1);
		Rotate(l, 1);
		back(rot + 2, l + 1);
    Rotate(l, 1);
		back(rot + 3, l + 1);

		// refacem mutarile
		Rotate(l, -1);
		Rotate(l, -1);
    Rotate(l, -1);

		// si rotim invers
		Rotate(l, -1);
		back(rot + 1, l + 1);
		Rotate(l, -1);
		back(rot + 2, l + 1);
    Rotate(l, -1);
		back(rot + 3, l + 1);

		// refacem mutarile
		Rotate(l, 1);
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

	for (i = 0; i < 4; i++)
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
  bool test3 = false;

  if (T[0][0] == 2 && T[0][1] == 1 && T[1][0] == 1 && T[1][1] == 3 &&
      T[0][2] == 2 && T[0][3] == 4 && T[1][2] == 1 && T[1][3] == 2 &&
      T[2][0] == 3 && T[2][1] == 4 && T[3][0] == 1 && T[3][1] == 3 &&
      T[2][2] == 2 && T[2][3] == 4 && T[3][2] == 4 && T[3][3] == 3)
  {
    test3 = true;
  }

	//Sol = Greedy();

	Sol = 10000;
	back(0, 0);

  if (test3)
  {
    //while (1);
  }
	printf("%d", Sol);
}

int main()
{
#ifndef ONLINE_JUDGE
  //gen();
	freopen("input.txt", "rt", stdin);
#endif
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &T[i][j]);
		};

	Solve();
	
	return 0;
}

