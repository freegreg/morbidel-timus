/*
 *  ACM Online
 *  Stripies - Problem 1161
 *
 *  solutie: le sort†m...
 */

#include <stdio.h>
#include <math.h>

#define input "strip.in"
#define output "strip.out"

FILE *f;
long n, hn, v[100];
long double r;


int main()
{
	int i, j;

	f = fopen(input, "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(f, "%ld", &v[i]);
	fclose(f);

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (v[i] < v[j])
				hn = v[i], v[i] = v[j], v[j] = hn;

	r = 2 * sqrtl(v[0] * v[1]);
	for (i = 2; i < n; i++)
		r = 2 * sqrtl(r * v[i]);
	if (n == 1) r = v[0];
	fprintf(fopen(output, "w"), "%.3Lf\n", r);

	return 0;
}
