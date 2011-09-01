/*
 *  ACM Online
 *  Hopscotch - Problem 1125
 *
 *  solutie: dac† e impar marc†m alea cu dist Œntreag†...
 *  tinem s[i] 1 dac† e p. perfect.
 */

#include <stdio.h>

int m, n, s[5500];
char mat[60][60];


void mark(int l, int c)
{
	int i, j, dist;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			dist = (l - i) * (l - i) + (c - j) * (c - j);
			if (s[dist])
				mat[i][j] = 153 - mat[i][j];
		}
}

int main()
{
	long i, j, how;

	scanf("%d %d\n", &m, &n);
	for (i = 0; i < m; i++)
		scanf("%s\n", mat + i);

	/*  p†tratele perfecte  */
	for (s[j = 0] = i = 1; j < 5000; i += 2)
		s[j += i] = 1;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			scanf("%ld", &how);
			if (how & 1) mark(i, j);
		}

	for (i = 0; i < m; i++)
		printf("%s\n", mat[i]);

	return 0;
}

/*
 *  Se Œntƒmpl† multe lucruri bizare sau mi se pare...
 *  Imi permit o Œntrebare: care-i originea virusului HIV oare? Imi permit si-un
 *  r†spuns: laboratoare de cercetare, secrete, folosesc sectoare din Africa
 *  ca teren de testare, sustin c† banii-s puterea dar cu banii-n conturi
 *  bancare, e-un ban care ne cuprinde pe toti, rƒzi dac† poti!
 */
