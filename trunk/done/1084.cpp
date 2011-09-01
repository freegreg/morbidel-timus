/*
 *  ACM Online
 *  A goat in a kitchen garden - Problem 1084
 *
 *  solutie: cercul se int. cu p�tratul: 2R�*arctg((L�-2R�)/(L*sqrt(4R�-L�)))+L*sqrt(4*R�-L�)
 *  altfel e dup� caz L� sau pi*R�...
 */

#include <stdio.h>
#include <math.h>

long L, R;
long double ar, PI = 3.141592652589793238462643383279;


int main()
{
	scanf("%ld %ld", &L, &R);
	/*  cerc inclus in patrat  */
	if (2 * R <= L) ar = PI * R * R; else
	/*  patrat inclus in cerc  */
	if (sqrtl(2) * R >= L) ar = L * L; else
	/*  se intersecteaza  */
		ar = 2 * R * R * atan((L * L - 2 * R * R) / (L * sqrtl(4 * R * R - L * L))) + L * sqrtl(4 * R * R - L * L);

	printf("%.3Lf\n", ar);
	return 0;
}
