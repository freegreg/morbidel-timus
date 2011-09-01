/*
 * convex polygon generator
 */

#include <cstdio>
#include <math.h>

int N;
struct point
{
	double x, y;
};


int GetAngleABC(point a, point b, point c )
{
    point ab = { b.x - a.x, b.y - a.y };
    point cb = { b.x - c.x, b.y - c.y };

    // dot product  
    double dot = (ab.x * cb.x + ab.y * cb.y);

    // length square of both vectors
    double abSqr = ab.x * ab.x + ab.y * ab.y;
    double cbSqr = cb.x * cb.x + cb.y * cb.y;

    // square of cosine of the needed angle    
    double cosSqr = dot * dot / abSqr / cbSqr;

    // this is a known trigonometric equality:
    // cos(alpha * 2) = [ cos(alpha) ]^2 * 2 - 1
    double cos2 = 2 * cosSqr - 1;

    // Here's the only invocation of the heavy function.
    // It's a good idea to check explicitly if cos2 is within [-1 .. 1] range

    const double pi = 3.14159265358979323846264338;
    double alpha2 = (cos2 <= -1) ? pi : (cos2 >= 1) ? 0 : acos(cos2);
    double rslt = alpha2 / 2;
    double rs = rslt;// * 180. / pi;


    // Now revolve the ambiguities.
    // 1. If dot product of two vectors is negative - the angle is definitely
    // above 90 degrees. Still we have no information regarding the sign of the angle.

    // NOTE: This ambiguity is the consequence of our method: calculating the cosine
    // of the double angle. This allows us to get rid of calling sqrt.

    if (dot < 0)
        rs = pi - rs;

    // 2. Determine the sign. For this we'll use the Determinant of two vectors.

/*    double det = (ab.x * cb.y - ab.y * cb.y);
    if (det < 0)
        rs = -rs;
*/
    return rs;
}


void GenerateConvexPolygon(int n)
{
	/* TODO :) */
}

int main()
{
	scanf("%d", &N);

	GenerateConvexPolygon(N);

	return 0;
}

