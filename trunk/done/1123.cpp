/*
 *  ACM Online
 *  Salary - Problem 1123
 *
 *  solutie: Œl scriem simetric cu primele n/2 si dac† e mai mic le crestem pe
 *  alea din mijloc. Dac† dep†sim 9 mergem lateral si punem 0...
 */

#include <stdio.h>
#include <string.h>

int n = 0, mid;
char a[2010], b[2010];


int main()
{
	int i, l, r;

	scanf("%s", &a);
	n = strlen(a);
	strcpy(b, a);

	for (i = 0; i < (n + 1) / 2; i++)
		if (b[n - 1 - i] != b[i])
			b[n - 1 - i] = b[i];

	if (strcmp(b, a) < 0)
	{
		l = n / 2 - 1 + n % 2; r = n - 1 - l;
		while (b[l] == '9')
			b[l--] = b[r++] = '0';
		if (l >= 0)
		{
			b[l]++;
			if (r > l) b[r]++;
		}
	}
	printf("%s\n", b);

 	return 0;
}
