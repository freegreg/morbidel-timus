/*
 *  ACM Timus Online Judge
 *  Maximum. Version 2
 */

#include <stdio.h>
#include <vector>

#define MAXN			10001
#define INPUT_FILE		"input.txt"

using namespace std;

vector<long> A;
//vector<__int64> M;
long M;

long N;

void Readdata()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif

}

void Solve()
{
	long i;

	N = 100000;

	A.resize(N);

	A[0] = 0;
	A[1] = 1;

	M = 1;
	printf("0 -> 0\n1 -> 1\n");
	for (i = 2; i < N; i++)
	{
		if (i & 1)
			A[i] = A[i / 2] + A[i / 2 + 1];
		else
			A[i] = A[i / 2];

		if (A[i] > M)
		{
			M = A[i];
			printf("%d -> %ld\n", i, A[i]);
		}
	}
}

int main()
{
	Readdata();
	Solve();

	return 0;
}
