/*
 *  ACM Online
 *  Cryptography - Problem 1086
 */

#include <stdio.h>

long k, idno, n, ciur[200001L];

int main()
{
	long i, j;
	n = 200000L;
	for (i = 2; i <= n; i++)
	   	if (!ciur[i])
			for (j = 2; i * j <= n; j++)
			   	ciur[i * j] = 1;
    for (i = 2; i <= n; i++)
	   	if (!ciur[i])
		   	ciur[++ciur[0]] = i;
    scanf("%ld", &k);
	for (i = 0; i < k; i++)
    {
	 	scanf("%ld", &idno);
		printf("%ld\n", ciur[idno]);
    }

	return 0;
}
/*
	Direct si la obiect vorbesc despre orice subiect, perfect sau imperfect,
	nu menajez nici un inestet cu intelect inert.
*/
