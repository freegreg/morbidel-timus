/*
 *  ACM Timus
 *  G. Salary for Robots
 */

#include <stdio.h>
#include <math.h>

#define MAXN	1024
#define BASE	10

typedef int BIGINT[10000];

int N, K;
__int64 P, Sol;
int S[1024];
BIGINT A;

void back(int lev)
{
	int i;


	if (lev == N)
	{
		int cnt = 0;
		for (i = 0; i < N - 1; i++)
			if (S[i] > S[i + 1])
				cnt++;

		if (cnt == N - 1)
			return;
		Sol++;
		//for (i = 0; i < N; i++)
		//	printf("%d ", S[i]);
		//printf("\n");
	}
	else
	for (i = 1; i <= K; i++)
	{
		S[lev] = i;
		back(lev + 1);
		S[lev] = 0;
	}
}


// ret a = a * x
void IMul(BIGINT &a, int x)
{
	int i, k = 0;

	for (i = 1; i <= a[0]; i++)
		a[i] = a[i] * x + k, k = a[i] / BASE, a[i] %= BASE;

	while (k)
		a[++a[0]] = k % BASE, k /= BASE;

	while (a[a[0]] == 0 && a[0] > 1)
		a[0]--;
}

// ret a % x si a /= x
int IDiv(BIGINT &a, int x)
{
	int i, r = 0;

	for (i = a[0]; i > 0; i--)
	{
		r = r * BASE + a[i];
		a[i] = r / x;
		r %= x;
	}

	while (a[a[0]] == 0 && a[0] > 1)
		a[0]--;

	return r;
}


int main()
{
	scanf("%d %d %I64d", &N, &K, &P);

	//back(0);
	//printf("%I64d\n", (Sol % P) + 1);

	// solution is K^N - Comb(K, N), all modulo P

	Sol = 1;
	int i;
	for (i = 0; i < N; i++)
	{
		Sol = Sol * K;
		Sol %= P;
	}

	if (K >= N && N != 1)
	{
		if (N < K - N)
			N = K - N;

		A[0] = 1;
		A[1] = 1;

		for (i = N + 1; i <= K; i++)
		{
			IMul(A, i);
		}

		for (i = 1; i <= K - N; i++)
		{
			IDiv(A, i);
		}

		__int64 up = IDiv(A, P);

		Sol = Sol - up;
		Sol %= P;
	}

	printf("%I64d\n", Sol + 1);


	return 0;
}