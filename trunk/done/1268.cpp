/*
 *  ACM Timus Online
 *  Little Chu - 1268
 *
 *  solutie: k^x = 1(mod N), x prim si div N
 *  baleiez K-ul si x-ul... si iau minimul ciclului (ooof, tot de la Radu)
 */

#include <stdio.h>

long T, K, N, Bestlen, BestK;
long Ciur[70000];


long modexp(long a, long b, long n)
{
    unsigned r;

    for (a %= n, r = 1; b; b >>= 1, a = (a * a) % n)
        if (b & 1) 
		r = (r * a) % n;

    return r;
}

void baga_mare()
{
    int len, nr;

    for (nr = len = N - 1; Ciur[nr]; nr /= Ciur[nr])
        if (power(len / Ciur[nr]) == 1)
        {
           len /= Ciur[nr];
           if (len <= Bestlen) return;
        }
    Bestlen = len, BestK = K;
}

long solve()
{
    Bestlen = 0;
    for (K = N - 1; Bestlen < N - 1 && K > 1; K--)
        baga_mare();

    return BestK;
}

int main()
{
	int i, j;

	for (i = 2; i <= 0xFFFF; i++)
		if (!Ciur[i])
			for (Ciur[i] = i, j = 2 * i; j <= 0xFFFF; j += i)
				Ciur[j] = i;

	for (scanf("%ld", &T); T--; )
	{
		scanf("%ld", &N);
		printf("%ld\n", solve());
	}

	return 0;
}
