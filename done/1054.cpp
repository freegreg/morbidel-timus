/*
 *  ACM Online
 *  Hanoi Tower - Problem 1054
 *
 *  solutie: ceva belea, dar am g†sit-o super greu, nu stiu de ce are doar
 *  30 dificultate. Se observ† (?) c† coloanele cu aceeasi paritate cu N sunt formate
 *  din secventa 122331122331 concatenata iar cele cu paritatea diferit†
 *  din secventa 133221133221 si contruim teoretic arborele binar complet
 *  si mergem prin noduri iar solutia e pozitia in ultimul nivel... Belea nu?
 */

#include <stdio.h>

int n, s[50], s1[] = {0, 1, 2, 2, 3, 3, 1, 1, 2, 2, 3, 3, 1},
              s2[] = {0, 1, 3, 3, 2, 2, 1, 1, 3, 3, 2, 2, 1};


int is(int lev, long pos)
{
	if (pos % 12 == 0) pos++;
	return (lev & 1) ? s1[pos % 12] : s2[pos % 12];
}

long baga_mare(int lev, long pos)
{
	long fiu;
	if (lev == n) return pos;
	fiu = 2 * pos - 1;
	if (s[n - lev] == is(lev + 1, fiu))
		return baga_mare(lev + 1, fiu);
	fiu = 2 * pos;
	if (s[n - lev] == is(lev + 1, fiu))
		return baga_mare(lev + 1, fiu);
	return 0;
}

int main()
{
	int i;

	scanf("%d", &n);
	for (i = 1; i <= n; scanf("%d", s + i++));

	printf("%ld\n", baga_mare(0, 1) - 1);

	return 0;
}
/*
 *  Noapte si zi, viata o invoc, ea e speranta faceti loc.
 *  E secunda de iubire si de noroc, ea ni-i dat† mereu
 *  S-aprind† Œn piept mult visata garoaf† de foc...
 */
