/*
 *  ACM Timus Online
 *  Arirang Show - Problem 1832
 */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAXN		300001

int N;
char S[MAXN];
char Next[MAXN][26];
std::vector<int> D;
bool Impossible;


int CheckSolution()
{
	int i, j, d, n, next;

	for (i = 0; i < D.size() - 1; i++)
	{
		d = D[i];

		for (j = 1; j <= d; j++)
		{
			n = j;

			do
			{
				next = n + d;
				if (next > N)
				{
					next %= N;
					if (next == 0)
						next = 1;
				}
				if (S[n] == S[next])
				{
					return d;
				}

				n = next;
			} while (n != j);
		}
	}
	return -1;
}

int main()
{
	int i, j, k, d;


	scanf("%d", &N);

	memset(S, 'a', N + 1);
	memset(Next, 0, sizeof(Next));

	S[0] = '|';
	S[N + 1] = 0;

	for (i = 1; i * i <= N; i++)
		if (N % i == 0)
		{
			int n1 = N / i, n2 = N / n1;

			D.push_back(n1);
			D.push_back(n2);
		};

	sort(D.begin(), D.end());

	Impossible = false;
	for (i = 1; i <= N && !Impossible; i++)
	{
		/* s[i] is the first empty space in Next[i]. If none -> Impossible */
		for (j = 0; j < 26; j++)
			if (Next[i][j] == 0)
			{
				S[i] = 'a' + j;
				break;
			}
		if (j == 26)
		{
			Impossible = true;
			break;
		}

		/* compute all i's neighbours according to all N's divisors */
		for (j = 0; j < D.size() - 1; j++)
		{
			d = D[j];

			/* i is neighbour with i + d and i - d (mod N) */
			k = (i - d) % N;
			if (k <= 0)
				k += N;

			if (i + d > i && i + d <= N)
			{
				/* s[i] is fixed now, so cut it as candidate from this neighbour */
				Next[i + d][S[i] - 'a'] = 1;
			}
			if (k != i + d && k > i && k <= N)
			{
				/* s[i] is fixed now, so cut it as candidate from this neighbour */
				Next[k][S[i] - 'a'] = 1;
			}
		}
	}
	if (!Impossible)
		printf("%s\n", S + 1);
	else
		printf("Impossible\n");

	//d = CheckSolution();
	//if (d != -1)
	//{
	//	printf("ERROR: matrix for d = %d contains an error:\n", d);

	//	/* matrix with D[i] as d */
	//	char sz[1024];
	//	for (j = 0; j < N / d; j++)
	//	{
	//		memcpy(sz, S + 1 + j * d, d);
	//		sz[d] = 0;
	//		printf("%s\n", sz);
	//	}
	//}

	return 0;
}
