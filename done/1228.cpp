// ACM Online
// Array - Problem 1228

// solutie: impartim pe s la p[i] pana nu mai merge...

#include <stdio.h>

long s;
int n, d[50];

void main()
{
	int i;
	scanf("%d %ld", &n, &s);
    for (i = 0; i < n; scanf("%d", &d[i++]));
    s--;
    for (i = 0; i < n; i++)
    {
        printf("%ld ", s / d[i]);
        s %= d[i];
    }
}