/* 
 *  ACM Online
 *  The Pruffer Code - Problem 1069
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODS 16000

long n, how[NODS], flag[NODS], sum[NODS], sol[NODS], s[NODS], oflag[NODS];


int main()
{
	long i, j, k, next, lev = 0;

	n = 0;
	while (scanf("%ld", &s[n++]) == 1)
		flag[--s[n - 1]]++;
	memcpy(oflag, flag, sizeof(flag));

	// calculez gradele
	for (i = 0; i < n; i++)
		if (!flag[i])
			next = i, i = n;
	for (i = 0; i < n - 1; i++)
	{
		// muchie de la k la next
		k = s[i];
		how[k]++;
		how[next]++;
		flag[k]--; flag[next]--;
		while (flag[++next]);
		if (k < next && !flag[k]) next = k;
	}
	for (sum[0] = 0, i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + how[i - 1], how[i - 1] = 0;

	memcpy(flag, oflag, sizeof(oflag));
	// inca o data
	for (i = 0; i < n; i++)
		if (!flag[i])
			next = i, i = n;
	for (i = 0; i < n - 1; i++)
	{
		// muchie de la k la next
		k = s[i];
		sol[sum[k] + how[k]++] = next; 
		sol[sum[next] + how[next]++] = k;
		flag[k]--; flag[next]--;
		while (flag[++next]);
		if (k < next && !flag[k]) next = k;
	}
	for (sum[0] = 0, i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + how[i - 1];
	/* sortarea  */
	for (i = 0; i < n; i++)
		for (k = sum[i]; k < sum[i] + how[i]; k++)
			for (j = k + 1; j < sum[i] + how[i]; j++)
				if (sol[k] > sol[j])
					next = sol[k], sol[k] = sol[j], sol[j] = next;

	for (i = 0; i < n; i++, printf("\n"))	
	{
		printf("%ld: ", i + 1);
		for (k = sum[i]; k < sum[i] + how[i]; k++)
			printf("%ld ", sol[k] + 1);
	}
	return 0;
}
