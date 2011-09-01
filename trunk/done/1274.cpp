/*
 *  ACM Timus Online Contest, 8 November 2003
 *  Problem 1 -> Fractional Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define abs(x) ((x) > 0 ? (x) : -(x))

char line[100], oper;
string foo;
__int64 s1, j1, s2, j2, sf, jf;



__int64 gcd(__int64 a, __int64 b)
{
	return b ? gcd(b, a % b) : a;
}

void parse_frac(string input, __int64 &up, __int64 &down)
{
	int pos, pos2;
	__int64 pint, psus, pjos;


	pos = input.find_first_of(" ", 0);
	pos2 = input.find_first_of("/", 0);

	if (pos == -1 && pos2 == -1)
		pint = atol(input.c_str());

	if (pos != -1) /*  e spatiul deci are partea intreaga  */
	{
		pint = atol(input.substr(0, pos).c_str());
		input.erase(0, pos + 1);
	} else
	if (pos2 != -1)
		pint = 0;

	if (pos2 != -1) /*  e fractie  */
	{
		pos = input.find_first_of("/", 0);
		psus = atol(input.substr(0, pos).c_str());
		input.erase(0, pos + 1);
		pjos = atol(input.c_str());
	} else
		psus = 0, pjos = 1;

	up = pint * pjos + ((pint >= 0) ? psus : -psus);
	down = pjos;

	pint = gcd(abs(up), abs(down));

	up /= pint; down /= pint;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	gets(line);
	foo = line;
	parse_frac(foo, s1, j1);

	scanf("\n%c\n", &oper);

	gets(line);
	foo = line;
	parse_frac(foo, s2, j2);

	switch (oper)
	{
		case '+': sf = s1 * j2 + s2 * j1, jf = j1 * j2; break;
		case '-': sf = s1 * j2 - s2 * j1, jf = j1 * j2; break;
		case '*': sf = s1 * s2, jf = j1 * j2; break;
		case '/': sf = s1 * j2, jf = s2 * j1; break;

		default: for(;;) printf("ba boilor"); break;
	}	

	s1 = gcd(abs(sf), abs(jf));

	sf /= s1; jf /= s1;
	if (jf < 0)
		jf = -jf, sf = -sf;

	s2 = sf / jf; sf %= jf;

	if (s2 || !sf)
		printf("%I64d", s2), sf = abs(sf);

	if (sf && jf)
	{
		if (s2) printf(" ");
		printf("%I64d/%I64d", sf, jf);
	}
	printf("\n");

	return 0;
}
