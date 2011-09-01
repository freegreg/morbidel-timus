/*
 * ACM Timus Online
 * Pairs - Problem 1169
 *
 * solution: the problem can be reformulated as follows: find x1..xk which satisfies the first two Viete relations:
 * 		x1 + x2 + ... + xi = N
 * 		x1x2 + ... + xi-1xi = K
 * 		for some i
 *
 * 		for a value i for x1 a pair (n, k) turns in (n - i, k - i * (n - i)). 
 * 		We can recurse now: at each step we check whether we have an integer solution of degree 2 for the current pair (n, k)
 * 		If so, a solution exists with all the values for x1... until now and the 2 solutions for current (n, k)
 */

#include <cstdio>
#include <math.h>
#include <vector>

int N, K;
std::vector<int> S;


/* a (n, k) pair is valid if the equation x^2-n*x+k=0 has integer solutions */
bool Valid(int n, int k, int &x1, int &x2)
{
	double d = n * n - 4 * k;
	double dx1, dx2;

	if (d < 0)
		return false;

	dx1 = (n - sqrtl(d)) / 2;
	dx2 = (n + sqrtl(d)) / 2;

	if (dx1 == (int) dx1 && dx2 == (int) dx2)
	{
		x1 = dx1;
		x2 = dx2;

		return true;
	}
	return false;
}

void print_sol()
{
	int i, j, node = 1;
	
/*	for (i = 0; i < S.size(); i++)
		printf("%d ", S[i]);
	printf("\n------\n");*/

	if (S.size() == 0)
	{
		printf("-1");
	}
	else
	{
		int sum = 0;
		for (i = 0; i < S.size(); i++)
			for (j = i + 1; j < S.size(); j++)
				sum += S[i] * S[j];
		if (sum != K)
		{
			printf("ERROR, %d != K!\n", sum);
		}
		for (i = 0; i < S.size(); i++)
		{
			/* generate a sub-graph from each group -> simple circle graph */
			for (j = 0; j < S[i] - 1; j++)
				printf("%d %d\n", node + j, node + j + 1);

			if (j > 0)
				printf("%d %d\n", node + j, node);

			if (i != S.size() - 1)
			{
				/* tie with next group */
				printf("%d %d\n", node, node + S[i]);
				node += S[i];
			}
		}
	}
}

int back(int n, int k)
{
	int i, x1, x2;

	if (k < 0)
		return 0;

	if (Valid(n, k, x1, x2))
	{
		int sol = 0;

		if (x1 == 2 || x2 == 2)
			return 0;
		/* horray, we have a solution! */
		if (x1 > 0)
		{
			sol = 1;
			S.push_back(x1);
		}
		if (x2 > 0)
		{
			sol = 1;
			S.push_back(x2);
		}

		return sol;
	}
	else
	/* how much we can have in the current group */
	for (i = 1; i <= n; i++)
	{
		if (i == 2)
			continue;

		S.push_back(i);

		if (back(n - i, k - i * (n - i)))
			return 1;

		S.pop_back();
	}

	return 0;
}

int main()
{
	scanf("%d %d", &N, &K);

	back(N, K);
	print_sol();

	return 0;
}

