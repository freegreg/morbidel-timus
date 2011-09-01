/*
 *  ACM Online
 *  Titanic - Problem 1030
 */

#include <stdio.h>
#include <math.h>

#define pow2(a) ((a) * (a))


double Dist, Alpha, Euclid;
double PI = 3.14159264358979323846264338327954, R = 3437.5;

struct point
{
	double X, Y, Z;
	double G1, M1, S1, G2, M2, S2;
	double Phi, Theta;
	int Long, Lat;
} A, B;



void readdata()
{
	int g, m, s;
	char v[100], ch;


	fgets(v, 100, stdin); fgets(v, 100, stdin); fgets(v, 100, stdin);

	/*  longitudine primul punct  */
	g = m = s = 0;
	do
	{
		scanf("%c", &ch);
		if (ch == '^') break;
		g = g * 10 + ch - '0';
	}
	while (1);
	scanf("%c", &ch); m = ch - '0'; scanf("%c", &ch); m = m * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); s = ch - '0'; scanf("%c", &ch); s = s * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); scanf("%c", &ch); A.Long = (ch == 'N') ? 1 : -1; fgets(v, 100, stdin);
	A.G1 = g; A.M1 = m; A.S1 = s; g = m = s = 0;

	/*  latitudine primul punct  */
	scanf("%s", &v); scanf("%c", &ch);
	do
	{
		scanf("%c", &ch);
		if (ch == '^') break;
		g = g * 10 + ch - '0';
	}
	while (1);
	scanf("%c", &ch); m = ch - '0'; scanf("%c", &ch); m = m * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); s = ch - '0'; scanf("%c", &ch); s = s * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); scanf("%c", &ch); A.Lat = (ch == 'E') ? 1 : -1; fgets(v, 100, stdin);
	A.G2 = g; A.M2 = m; A.S2 = s; g = m = s = 0;

	fgets(v, 100, stdin);

	/*  longitudine al doilea punct  */
	g = m = s = 0;
	do
	{
		scanf("%c", &ch);
		if (ch == '^') break;
		g = g * 10 + ch - '0';
	}
	while (1);
	scanf("%c", &ch); m = ch - '0'; scanf("%c", &ch); m = m * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); s = ch - '0'; scanf("%c", &ch); s = s * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); scanf("%c", &ch); B.Long = (ch == 'N') ? 1 : -1; fgets(v, 100, stdin);
	B.G1 = g; B.M1 = m; B.S1 = s; g = m = s = 0;

	/*  latitudine al doilea punct  */
	scanf("%s", &v); scanf("%c", &ch);
	do
	{
		scanf("%c", &ch);
		if (ch == '^') break;
		g = g * 10 + ch - '0';
	}
	while (1);
	scanf("%c", &ch); m = ch - '0'; scanf("%c", &ch); m = m * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); s = ch - '0'; scanf("%c", &ch); s = s * 10 + ch - '0'; scanf("%c", &ch);
	scanf("%c", &ch); scanf("%c", &ch); B.Lat = (ch == 'E') ? 1 : -1; fgets(v, 100, stdin);
	B.G2 = g; B.M2 = m; B.S2 = s;
}

void solve()
{
	/*  calculam coordonatele in spatiu de pe sfera  */

	A.Phi = (A.G1 + A.M1 / 60 + A.S1 / 3600) * PI / 180 * (A.Long == 1 ? 1 : -1);
	A.Theta = (A.G2 + A.M2 / 60 + A.S2 / 3600) * PI / 180 * (A.Lat == 1 ? 1 : -1);

	A.X = R * cos(A.Theta) * cos(A.Phi);
	A.Y = R * sin(A.Theta) * cos(A.Phi);
	A.Z = R * sin(A.Phi);

	B.Phi = (B.G1 + B.M1 / 60 + B.S1 / 3600) * PI / 180 * (B.Long == 1 ? 1 : -1);
	B.Theta = (B.G2 + B.M2 / 60 + B.S2 / 3600) * PI / 180 * (B.Lat == 1 ? 1 : -1);

	B.X = R * cos(B.Theta) * cos(B.Phi);
	B.Y = R * sin(B.Theta) * cos(B.Phi);
	B.Z = R * sin(B.Phi);

	/*printf("Unghiuri: %.3lf %.3lf si %.3lf %.3lf\n", A.Phi, A.Theta, B.Phi, B.Theta);
	printf("Punctele: (%.3lf, %.3lf, %.3lf) <-> (%.3lf, %.3lf, %.3lf)\n", A.X, A.Y, A.Z, B.X, B.Y, B.Z);*/

	/*  acum calculez distanta dintre cele 2 puncte pe sfera  */
	/*  calculez distanta in spatiu (directa), unghiul la centru apoi arcul dintre ele  */

	Euclid = sqrtl(pow2(A.X - B.X) + pow2(A.Y - B.Y) + pow2(A.Z - B.Z));
	/*Alpha = asin(Euclid * sqrtl(pow2(2 * R) - pow2(Euclid)) / (2 * R * R));
	if (Alpha == 0 && A.Lat * B.Lat == -1)
		Alpha = PI;
	Dist = R * Alpha;*/
	Dist = 2 * R * asin(Euclid / 2 / R);

	printf("The distance to the iceberg: %.2lf miles.\n", Dist);
	if (Dist < 99.995)
		printf("DANGER!\n");
}

int main()
{
	readdata();
	solve();

	return 0;
}
