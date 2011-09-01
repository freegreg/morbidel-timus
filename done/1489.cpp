/*
 *  ACM Timus Online
 *  Points on a Parallelepiped - Problem 1489
 *
 *  Sol: fold all faces except the middle one and convert the two points to 3d coordinates.
 */

#include <stdio.h>
#include <math.h>

#define INPUT		"input.txt"
#define OUTPUT		"output.txt"
#define SQR(x)		((x) * (x))
#define MIN(a, b)	((a) > (b) ? (b) : (a))
#define MAX(a, b)	((a) > (b) ? (a) : (b))


double A, B, C, X0, Y0, X1, Y1, D, Z0, Z1;
struct face
{
	double x1, y1;
	double x2, y2;
} Faces[7];

void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(INPUT, "r", stdin);
	#endif

	scanf("%lf %lf %lf\n%lf %lf\n%lf %lf", &A, &B, &C, &X0, &Y0, &X1, &Y1);
}

bool InRect(double x, double y, double x1, double y1, double x2, double y2)
{
	return (x >= MIN(x1, x2) && x <= MAX(x1, x2) && y >= MIN(y1, y2) && y <= MAX(y1, y2));
}

int GetFace(double x, double y)
{
	int i;

	for (i = 1; i <= 6; i++)
		if (InRect(x, y, Faces[i].x1, Faces[i].y1, Faces[i].x2, Faces[i].y2))
			return i;

	return -1;
}

void Transform(double x, double y, int face, double &_x, double &_y, double &_z)
{
	switch (face)
	{
		case 1:
			_x = x;
			_y = Faces[face].y2;
			_z = y - Faces[face].y2;
			break;
		case 2:
			_x = Faces[face].x2;
			_y = y;
			_z = Faces[face].x2 - x;
			break;
		case 3:
			_x = x;
			_y = y;
			_z = 0;
			break;
		case 4:
			_x = Faces[face].x1;
			_y = y;
			_z = x - Faces[face].x1;
			break;
		case 5:
			_x = x;
			_y = Faces[face].y1;
			_z = Faces[face].y1 - y;
			break;
		case 6:
			_x = x;
			_y = 2 * B + C - y;
			_z = C;
			break;			
	}
}

void Solve()
{
	#ifndef ONLINE_JUDGE
	freopen(OUTPUT, "w", stdout);
	#endif

	Faces[1].x1 = C; Faces[1].y1 = B + C + B + C;
	Faces[1].x2 = A + C; Faces[1].y2 = B + C + B;

	Faces[2].x1 = 0; Faces[2].y1 = B + C + B;
	Faces[2].x2 = C; Faces[2].y2 = B + C;
	
	Faces[3].x1 = C; Faces[3].y1 = B + C + B;
	Faces[3].x2 = A + C; Faces[3].y2 = B + C;
	
	Faces[4].x1 = A + C; Faces[4].y1 = B + C + B;
	Faces[4].x2 = A + C + C; Faces[4].y2 = B + C;
	
	Faces[5].x1 = C; Faces[5].y1 = B + C;
	Faces[5].x2 = A + C; Faces[5].y2 = B;
	
	Faces[6].x1 = C; Faces[6].y1 = B; 
	Faces[6].x2 = A + C; Faces[6].y2 = 0;

	int face0 = GetFace(X0, Y0);
	int face1 = GetFace(X1, Y1);

	double x0, y0, z0;
	Transform(X0, Y0, face0, x0, y0, z0);

	double x1, y1, z1;
	Transform(X1, Y1, face1, x1, y1, z1);


	D = sqrtl(SQR(x1 - x0) + SQR(y1 - y0) + SQR(z1 - z0));

	printf("%.6lf\n", D);
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
