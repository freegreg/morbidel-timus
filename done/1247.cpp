/*
 *  ACM Online
 *  Check a sequence - Problem 1247
 *
 *  solutie: verific†m doar secventele 1..k, k = 1..N
 */

#include <stdio.h>

long now, n, s, sum = 0;


int main()
{
	int i, ok = 0;
	scanf("%ld %ld", &n, &s);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &now);
		if (!sum && !now) continue;
		sum += now - 1;
		if (sum > s) ok = 1, i = n;
	}
	printf("%s\n", ok ? "NO" : "YES");

	return 0;
}
