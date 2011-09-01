/*
 *  ACM Timus Online
 *  Building Towers - Problem 1148
 *
 *  Sol: simple recurence (N, H, M) = (N - M, H - 1, M - 1) + (N - M, H - 1, M + 1) with memoization and some optimizations:
 *  	- the map holds only the values for odd values for N, otherwise will get MLE
 *	- filter N carefully between N min and N max (number min of bricks for which N, H, M is vaild, and N max)
 */

#include <cstdio>
#include <map>

int N, H, M;
long long K;
std::map<long, long long> A;


int NMin(int h, int m)
{
	if (h == m)							/* M, M -1, ..., 1 */
		return m * (m + 1) / 2;
	else if (h < m)
		return m * (m + 1) / 2 - (m - h) * (m - h + 1) / 2;	/* M, M - 1, ..., M - H + 1 */
	else
		return m * (m + 1) / 2 + h - m + (h - m + 1) / 2;	/* M, M - 1, ..., 1, 2, 1, 2, ... */
}

int NMax(int h, int m)
{
	return h * m + h * (h - 1) / 2;					/* M, M + 1, ..., M + H - 1 */
}

long Hash(int n, int h, int m)
{
	return (long)h * 100 * 10000 + (long)m * 10000 + (long)n;
}

long long Solve(int n, int h, int m)
{
	if (m == 0 || n == 0 || n < m)
		return 0;
	else if (h == 1)
		return 1;
	else if (n < NMin(h, m))
		return 0;
	else
	{
		if (n > NMax(h, m))
			n = NMax(h, m);
		long hash1 = Hash(n - m, h - 1, m - 1);
		long hash2 = Hash(n - m, h - 1, m + 1);
		long long s1 = -1;
		long long s2 = -1;

		if (A.find(hash1) != A.end()) 
			s1 = A[hash1];
		if (A.find(hash2) != A.end()) 
			s2 = A[hash2];

		if (s1 == -1)
		{
			s1 = Solve(n - m, h - 1, m - 1);
			if (n & 1)
				A[hash1] = s1;
		}
		if (s2 == -1)
		{
			s2 = Solve(n - m, h - 1, m + 1);
			if (n & 1)
				A[hash2] = s2;
		}

		if (n & 1)
			A[Hash(n, h, m)] = s1 + s2;

		return s1 + s2;
	}
}

void Recurse(int n, int h, int m, long long k)
{
	if (h == 1)
		printf("\n");
	else
	{
		if (n > NMax(h, m))
			n = NMax(h, m);

		long long s1 = -1;
		long hash = Hash(n - m, h - 1, m - 1);
		
		if (A.find(hash) != A.end()) 
			s1 = A[hash];
		else
		{
			/* if n is even we don't have it in the map so recompute it */
			s1 = Solve(n - m, h - 1, m - 1);
		}

		if (s1 == -1)
		{
			printf("ERROR!");
			return;
		}
		
		if (k > s1)
		{
			/* m + 1 branch */
			printf("%d ", m + 1);
			Recurse(n - m, h - 1, m + 1, k - s1);
		}
		else
		{
			/* m - 1 branch */
			printf("%d ", m - 1);
			Recurse(n - m, h - 1, m - 1, k);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d %d %d", &N, &H, &M);

	if (N > NMax(H, M))
		N = NMax(H, M);

	long long sol = Solve(N, H, M);
	printf("%lld\n", sol);

	while (true)
	{
		scanf("%lld", &K);
		if (K == -1)
			break;
		if (K > sol)
			K = sol;

		printf("%d ", M);
		Recurse(N, H, M, K);
	}
	
	return 0;
}

