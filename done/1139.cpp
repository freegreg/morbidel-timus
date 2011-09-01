// ACM Online
// City Blocks - Problem 1139

// formula este: (x - 1) + (y - 1) - cmmdc(x - 1, y - 1) (ia demonstreaz-o!)

#include <stdio.h>

unsigned x, y, rez;

int cmmdc(int a, int b)
{
	if (!b) return a;
	else return cmmdc(b, a % b);
}

void main()
{
	scanf("%d %d", &x, &y);
	rez = x + y - 2 - cmmdc(x - 1, y - 1);
	printf("%u", rez);
}
