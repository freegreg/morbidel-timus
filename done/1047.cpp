// ACM Online
// Simple Calculations - Problem 1047

// solutie: formula este:
// a[1] = (a[n + 1] + n * a[0] - 2 * ‰C[i] * (n - i + 1)) / (n + 1)

#include <stdio.h>

int n;
float a0, an1;
double rez = 0;

void main()
{
	int i;
	float ci;
	scanf("%d %f %f", &n, &a0, &an1);
	for (i = 1; i <= n; i++)
	{
		scanf("%f", &ci);
		rez += ci * (n - i + 1);
	}
	rez = (an1 + n * a0 - 2 * rez) / (n + 1);
	printf("%.2lf", rez);
}