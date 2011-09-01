/*  ACM Online
 *  A Tethered dog - Problem 1246
 *
 *  solutie: verificåm doar semnul primelor trei puncte. Nu merge decât la poligon convex dar merge!
 */


#include <stdio.h>

long n;
long double s, x1, y1, x2, y2, x3, y3;

int main()
{
    scanf("%ld %Lf %Lf %Lf %Lf %Lf %Lf", &n, &x1, &y1, &x2, &y2, &x3, &y3);
	s = (x1 - x2) * (y2 - y3) - (x2 - x3) * (y1 - y2);   
    printf(s > 0 ? "ccw\n" : "cw\n");

	return 0;
}
