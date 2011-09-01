/*
 *  ACM Online
 *  A goat in a kitchen garden - Problem 1084
 *
 *  solutie: cercul se int. cu påtratul: 2R²*arctg((L²-2R²)/(L*sqrt(4R²-L²)))+L*sqrt(4*R²-L²)
 *  altfel e dupå caz L² sau pi*R²...
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
