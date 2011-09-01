/*
 *  ACM Online
 *  Copying - Problem 1131
 *
 *  caut†m cea mai mare putere a lui 2 <= k si apoi mergem din k Œn k tot
 *  crescƒnd num†rul de din alea gata (de fapt e (n-curente) / k)...)
 */

#include <stdio.h>

long n, k, h, sum, now;


int main()
{
	scanf("%ld %ld", &n, &k);

	for (h = sum = 1; ; h++)
	{
		now = (long)1 << (h - 1);
		if (now > k || sum + now > n) break;
		sum += now;
	}
	h += (n - sum) / k - 1;
	if ((n - sum) % k) h++;
	printf("%ld\n", h);

	return 0;
}
