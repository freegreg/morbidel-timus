// ACM Online
// A strange procedure - Problem 1214

// daca x si y returnati au suma impara atunci s-a introdus y si x altfel
// tot x si y

#include <stdio.h>

long x, y;

void main()
{
	long myx, myy;
	scanf("%ld %ld", &x, &y);
	if ((x + y) % 2 && x > 0 && y > 0) myx = y, myy = x; else myx = x, myy = y;
	printf("%ld %ld", myx, myy);
}