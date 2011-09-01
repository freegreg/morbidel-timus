/*
 *  ACM Online
 *  Combinations - Problem 1055
 *
 *  solutie: O(NlogN) -> facem un ciur si apoi solutia banal† doar c† nu
 *  crestem urm†torul divizor(ar dura prea mult) ci Œi luam din ciur, Œn ordine
 */

#include <stdio.h>

long n, k, sol = 0, flag[50001];
long ciur[50001];


int main()
{
	long i, j, d, num;
	scanf("%ld %ld", &n, &k);
	if (k > n / 2) k = n - k;

	for (i = 2; i <= n; i++)
		if (!ciur[i])
			for (j = 2; i * j <= n; j++)
				ciur[i * j] = 1;
	for (i = 2; i <= n; i++)
		if (!ciur[i]) ciur[++ciur[0]] = i;

	for (i = n - k + 1; i <= n; i++)
		for (num = i, d = 1; num > 1; d++)
			while (num % ciur[d] == 0)
				flag[ciur[d]]++, num /= ciur[d];
	for (i = 2; i <= k; i++)
		for (num = i, d = 1; num > 1; d++)
			while (num % ciur[d] == 0)
				flag[ciur[d]]--, num /= ciur[d];

	for (i = 2; i <= n; i++)
		if (flag[i] > 0)
			sol++;
	printf("%ld\n", sol);

	return 0;
}
