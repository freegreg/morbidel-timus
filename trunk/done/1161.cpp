/*
 *  ACM Online
 *  Stripies - Problem 1161
 */

#include <stdio.h>
#include <math.h>

long n, hn, v[100];
long double r;


int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%ld", &v[i]);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (v[i] < v[j])
				hn = v[i], v[i] = v[j], v[j] = hn;

	r = 2 * sqrt(v[0] * v[1]);
	for (i = 2; i < n; i++)
		r = 2 * sqrt(r * v[i]);
	if (n == 1) r = v[0];
	printf("%.2Lf\n", r);
	return 0;
}
