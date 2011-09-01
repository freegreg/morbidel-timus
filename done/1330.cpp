/*
 *  ACM Timus Online
 *  Intervals - Problem 1330
 *
 *  Solutie: arbori indexati binar
 */

#include <stdio.h>

#define input "file.in"

long N, M, S[10001];


int getk(long x)
{
	int k;

	if (!x) return 1;
	for (k = 0; !(x & 1); k++, x >>= 1);

	return k;
}

void pay(long x, long y)
{
	do
	{
		S[x] -= y;
		x += 1 << getk(x);
	}
	while (x <= N);
}

long sum(long x, long y)
{
	long sum1, sum2;

	sum1 = sum2 = 0;
	x--;
	do 
	{
		sum1 += S[x], x -= 1 << getk(x);
	}
	while (x > 0);

	do {
		sum2 += S[y]; y -= 1 << getk(y);
	}
	while (y > 0);

	return sum2 - sum1;
}

int main()
{
	long x, y;

	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%ld", &N);
	for (x = 1; x <= N; x++)
		scanf("%ld", &y), pay(x, -y);

	for (scanf("%ld", &M); M--; )
	{
		scanf("%ld %ld", &x, &y);
		printf("%ld\n", sum(x, y));
	}

	return 0;
}
