/*
 *  ACM Timus
 *  J - Penguin-Avia
 */

#include <stdio.h>
#include <math.h>

int T;
__int64 N, K;


bool Sol(__int64 k)
{
	if (k <= 1)
		return false;


	__int64 x = N / k;

	if (N / (k + 1) != x) return false;

	if (N / (k - 1) <= x) return false;

	return true;
}

void Solve()
{
	int i, c = sqrtl(N);
	for (i = -1000; i <= 1000; i++)
	//for (K = 2; K <= 1000000; K++)
	{
		K = c + i;

		if (Sol(K))
			break;
	}

	if (N == 1) K = 2;
	printf("%I64d\n", K);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	scanf("%d", &T);

	while (T--)
	{
		scanf("%I64d", &N);

		Solve();
	}

	return 0;
}
