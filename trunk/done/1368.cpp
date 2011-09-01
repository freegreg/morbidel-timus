/*
 *  ACM Timus Online
 *  Goat in the garden
 */

#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int N, NN, C = 0, Left;



void fill_side(int &sl, int &sc, int how, int incl, int incc)
{
	int i;

	for (i = 0; i < how; i++, sl += incl, sc += incc)
		printf("%d %d\n", sl, sc);
	sl -= incl; sc -= incc;
}

int main()
{
	int i, lat, Len, pl, pc;


	scanf("%d", &N);


	NN = (long)(1 + sqrtl(2 * N - 1)) / 2;

	// avem romb complet de inaltime NN, au ramas Left piese de pus
	Left = N - (NN - 1) * (NN - 1) - NN * NN;
	C = 4 * NN;

	// avem pe laturi NN - 1, NN, NN, NN + 1, caut latura incompleta
	int v[5] = {0, NN - 1, 2 * NN - 1, 3 * NN - 1, 4 * NN};
	for (i = lat = 0; Left && i <= 4; i++, lat++)
		if (Left - v[i] <= 0)
			break;
	C += lat;
	Left -= v[lat - 1];

	printf("%d\n", C);

	int dirl, dirc, how, sl, sc;
	for (i = 1; i <= 4; i++)
	{
		Len = (i <= lat) ? NN + 1 : NN;
		how = Len + ((i == 1) ? -1 : (i == 2 || i == 3) ? 0 : 1);

		pl = (i == 1 ? 1 : (i == 3 ? -1 : 0));
		pc = (i == 2 ? 1 : (i == 4 ? -1 : 0));

		if (i == 1)
			dirl = 1, dirc = -1, sl = -Len + 1, sc = -1;
		if (i == 2)
			dirl = 1, dirc = 1, sc = -Len, sl = 0;
		if (i == 3)
			dirl = -1, dirc = 1, sl = Len, sc = 0;
		if (i == 4)
			dirl = -1, dirc = -1, sc = Len, sl = 0;

		if (i == lat)
		{
			fill_side(sl, sc, Left + 1, dirl, dirc);
			fill_side(sl += pl, sc += pc, how - Left - 1, dirl, dirc);
		} else
			fill_side(sl, sc, how, dirl, dirc);
	}


	return 0;
}
