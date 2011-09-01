/*
 *  ACM Online
 *  Ball in a dream - Problem 1192
 *
 *  solutie: am luat-o de pe forum (prea mult† fizic†). Probabil se egalau
 *  energiile la coborƒre si urcare...
 */

#include <stdio.h>
#include <math.h>

long double Speed, Angle, K, Sol;
long double PI = 3.14159265358979323846264338;


int main()
{
	scanf("%Lf %Lf %Lf", &Speed, &Angle, &K);

	Angle = Angle * PI / 180.;
	Sol = 0.2 * sin(Angle) * cos(Angle) * Speed * Speed / (1 - 1 / K);
	printf("%.2Lf\n", Sol);

	return 0;
}
