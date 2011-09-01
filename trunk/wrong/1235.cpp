/*
 *  ACM Timus Online
 *  Cricket field - Problem 1235
 *
 *  solutie: caut binar latura patratului care are 2 puncte pe contur: le testez pe toate apoi vad daca se potriveste
 *  patratul. Pentru niste cazuri testez si din colturi (toate coliniare...)
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

int N, X, Y, L, Lmax, Px, Py, Fx, Fy;
struct point
{
	int x, y;
} P[101];



void readdata()
{
	int i;

	freopen("file.in", "r", stdin);
	scanf("%d %d %d", &N, &X, &Y);
	for (i = 1; i <= N; i++)
		scanf("%d %d", &P[i].x, &P[i].y);
}

int inbox(int x1, int y1, int x2, int y2, point p)
{
	return (p.x > min(x1, x2) && p.x < max(x1, x2) && p.y > min(y1, y2) && p.y < max(y1, y2));
}

int check(int n1, int n2)
{
	int i, x1, y1, x2, y2, mx, my, Mx, My, ok = 0;
	int c1, c2, c3, c4;

	c1 = c2 = c3 = c4 = 1;

	x1 = P[n1].x; x2 = P[n2].x; 
	y1 = P[n1].y; y2 = P[n2].y;
	mx = min(x1, x2); my = min(y1, y2);
	Mx = max(x1, x2); My = max(y1, y2);

	if (mx == Mx || my == My) return 0;

	/*  2 diagonale, 2 sensuri -> 4 cazuri  */
	c1 = (x1 == mx && y1 == my || x1 == Mx && y1 == My) && (mx + L <= X && My - L >= 0);
	c2 = (x1 == mx && y1 == my || x1 == Mx && y1 == My) && (Mx - L >= 0 && my + L <= Y);

	c3 = (x1 == mx && y1 == My || x1 == Mx && y1 == my) && (Mx - L >= 0 && My - L >= 0);
	c4 = (x1 == mx && y1 == My || x1 == Mx && y1 == my) && (mx + L <= X && my + L <= Y);

	for (i = 1; i <= N; i++)
	{
		if (c1 && inbox(mx, My, mx + L, My - L, P[i])) 
			c1 = 0;
		if (c2 && inbox(Mx, my, Mx - L, my + L, P[i])) 
			c2 = 0;
		if (c3 && inbox(Mx, My, Mx - L, My - L, P[i]))
			c3 = 0;
		if (c4 && inbox(mx, my, mx + L, my + L, P[i]))
			c4 = 0;
	}

	if (c1)
		Px = mx, Py = My - L;
	if (c2)
		Px = Mx - L, Py = my;
	if (c3)
		Px = Mx - L, Py = My - L;
	if (c4)
		Px = mx, Py = my;

	return c1 || c2 || c3 || c4;
}

void solve()
{
	int i, j, l, r, ok;

	Lmax = 0;
	l = 1; r = min(X, Y);
	do
	{
		ok = 0;
		L = (l + r) / 2;
		for (i = 1; i <= N; i++)
			for (j = i + 1; j <= N; j++)
			{
				ok = check(i, j);
				if (ok) 
					i = j = N;
			}

		/*  testam si din colturi  */
		int c1, c2, c3, c4;

		if (!ok)
		{
			for (c1 = c2 = c3 = c4 = i = 1; i <= N; i++)
			{
				if (c1 && inbox(0, Y, L, Y - L, P[i])) c1 = 0;
				if (c2 && inbox(X, 0, X - L, L, P[i])) c2 = 0;
				if (c3 && inbox(X, Y, X - L, Y - L, P[i])) c3 = 0;
				if (c4 && inbox(0, 0, L, L, P[i])) c4 = 0;
			}
			if (c1)
				Px = 0, Py = Y - L;
			if (c2)
				Px = X - L, Py = 0;
			if (c3)
				Px = X - L, Py = Y - L;
			if (c4)
				Px = 0, Py = 0;

			ok = c1 || c2 || c3 || c4;
		}

		if (ok)
			l = L + 1, Lmax = L, Fx = Px, Fy = Py;
		else
			r = L - 1;
	}
	while (l <= r);

	//printf("%d %d %d\n", Fx, Fy, Lmax);
	printf("Best: %d,%d si %d --> ", Fx, Fy, Lmax);

	for (i = 1; i <= N; i++)
		if (inbox(Fx, Fy, Fx + Lmax, Fy + Lmax, P[i]))
		{
			printf("WRONG! obiectul %d e inauntru!\n", i);
			return;
		}

	printf("ok\n");
}

void brute()
{
	int i, j, k, l, m;

	L = 0;

	for (i = 0; i <= X; i++)
		for (j = 0; j <= Y; j++)
			for (k = 1; k <= min(X - i, Y - j); k++)
			{
				for (l = 0, m = 1; m <= N; m++)
						if (inbox(i, j, i + k, j + k, P[m])) 
							l = 1, m = N;
				if (!l && k > L)
					L = k, Px = i, Py = j;
			}
	

	printf("Brut: %d,%d si %d\n", Px, Py, L);
	//if (L != Lmax) getch();
}

void generate()
{
	int i, x, y;
	time_t t;
	srand((unsigned) time(&t));

	FILE *f = fopen("file.in", "w");
	X = rand() % 10 + 1;
	Y = rand() % 10 + 1;
	N = rand() % min(10, (X * Y)) + 1;
	//scanf("%d %d", &X, &Y); N = 5;
	fprintf(f, "%d %d %d\n", N, X, Y);
	for (i = 0; i < N; i++)
	{
		x = rand() % X;
		y = rand() % Y;
		fprintf(f, "%d %d\n", x, y);
	}
	fclose(f);
	printf("Am generat o matrice cu X = %d si Y = %d. Am pus %d obstacol(e).\n", X, Y, N);
}

int main()
{
	//generate();
	readdata();
	solve();
	brute();

	return 0;
}
