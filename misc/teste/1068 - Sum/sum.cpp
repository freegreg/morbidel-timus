// ACM Online
// Sum - Problem 1068

#include <stdio.h>

#define input "sum.in"
#define output "sum.out"

long n, sum;


int main()
{
	fscanf(fopen(input, "r"), "%ld", &n);

	if (n <= 0) n = -n, sum = n * (n + 1) / 2 - 1, sum *= -1;
	else sum = sum = n * (n + 1) / 2;

	fprintf(fopen(output, "w"), "%ld", sum);

	return 0;
}
