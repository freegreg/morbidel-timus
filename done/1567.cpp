/*
 *  ACM Timus Online
 *  SMS-spam - Problem 1567
 */


#include <stdio.h>
#include <string.h>

char alfa[256];
char s[1024];


int main()
{
	gets(s);
	int i, n = strlen(s), cost = 0;

	memset(alfa, 0, sizeof(alfa));

	alfa['a'] = alfa['d'] = alfa['g'] = alfa['j'] = alfa['m'] = alfa['p'] = alfa['s'] = alfa['v'] = alfa['y'] = alfa['.'] = alfa[' '] = 1;
	alfa['b'] = alfa['e'] = alfa['h'] = alfa['k'] = alfa['n'] = alfa['q'] = alfa['t'] = alfa['w'] = alfa['z'] = alfa[','] = 2;
	alfa['c'] = alfa['f'] = alfa['i'] = alfa['l'] = alfa['o'] = alfa['r'] = alfa['u'] = alfa['x'] = alfa['!'] = 3;

	for (i = 0; i < n; i++)
		cost += alfa[s[i]];
	printf("%d\n", cost);

	return 0;
}
