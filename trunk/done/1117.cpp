/*
 *  ACM Online
 *  Hierarchy - Problem 1117
 *
 *  solutie: arborele e unic determinat de conditii. Numar cate nr. div cu 4, 8, ... sunt in interval si le sumez...
 */

#include <stdio.h>

long a, b, sol = 0;


/* puterea maximå a lui 2 in el  */
int lev(long x) 
{
	int l = 0;

	while (x % 2 == 0)
		x /= 2, l++;
	return l;
}

int main()
{
	long pow, p1, p2, now, ind, xx = 0;

	scanf("%ld %ld", &a, &b);
	
	if (a > b)
		p1 = a, a = b, b = p1;

	if (a == b)
	{
		printf("0\n");
		return 0;
	}

	if (a % 2 == 0)
		xx += lev(a++) - 1;
	if (b % 2 == 0)
		xx += lev(b--) - 1;
	
	for (pow = 4, ind = 2; ind <= 30; ind++, pow *= 2)
	{
		p1 = a; p2 = b;
		p1 += (pow - p1 % pow); p2 -= p2 % pow;
		if (p1 > p2) break;
		now = (p2 - p1) / pow + 1;
		sol += now; 
		if (now == 1 && p1 < p2) break;
	}

	sol = (!sol) ? xx : sol * 2 + xx;

	printf("%ld\n", sol);
	
	return 0;
}

/*
	In urma ta råmân mereu frânturi de ego, as vrea så pot da timpul înapoi, perdona me ti prego, 
	tatå, în viata asta scurtå si înceatå, så fim ca altådatå amândoi...
 */
