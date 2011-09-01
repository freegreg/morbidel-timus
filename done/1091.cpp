/*
 *  ACM Online
 *  Tmutarakan exams - Problem 1091
 *
 *  solutie: vedem cƒte x se Œmpart la 2, 3, 5... si facem comb de x luate k
 *  si Œn final sc†dem dublurile...
 *  (ex: 6 12 apare si la 2 si la 3, 10 20 la 2 si 5...)
 */

#include <stdio.h>

int s, c, pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
long double t = 0;


long double comb(int n, int k)
{
	int i;
	long double rez = 1;
	if (2 * k >= n) k = n - k;
	for (i = n - k + 1; i <= n; i++) rez *= (double) i;
	for (i = 2; i <= k; i++) rez /= (double) i;
	return rez;
}

int prim(int num)
{
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return 0;
	return 1;
}

int main()
{
	int i, j, nr, how;

	scanf("%d %d", &c, &s);

	for (i = 2; 2 * i <= s; i++)
	{
		if (!prim(i)) continue;
		how = s / i;
		if (how < c) break;
		t += comb(how, c);
	}
	/*  elimin†m dublurile...  */
	for (i = 0; i < 15; i++)
		for (j = i + 1; j < 15; j++)
		{
			nr = pr[i] * pr[j];
			how = s / nr;
			if (how < c) break;
			t -= comb(how, c);
		}

	printf("%.0Lf\n", t < 10000.0 ? t : 10000);

	return 0;
}
/*  Galbin, vƒn†t si pembe
 *  S† se uste ramul...
 *  Hei, la Edi-Kule...
 *  Sfat de tain† tin colo la cel han
 *  Han de toti uitat si de Genghis-Han
 *  In care o zi-i mai mare de-un an
 *  Si anu-i un veac si veacul noian...
 */
