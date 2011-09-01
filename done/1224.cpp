// ACM Online
// Spiral - Problem 1224

// solutie: a[m][n] = 0                  ,m sau n = 1
//                    (n - 1) * 2        ,m > n
//                    (m - 1) * 2        ,n >= m

#include <stdio.h>

long double m, n, sol;

void main()
{
	scanf("%Lf %Lf", &m, &n);
	sol = (n == 1 || m == 1) ? 0 : (n >= m ? (m - 1) * 2 : (n - 1) * 2);
	printf("%.0Lf", sol);
}