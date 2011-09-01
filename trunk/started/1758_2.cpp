/*
 *  ACM Timus Online
 *  Bald Spot Revisited 2 - Problem 1758
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXN	128

int N, MaxLen, NSol;
int S[MAXN], Flag[MAXN], Best[MAXN], BestV[4000][MAXN];
int Not[MAXN], Fact[MAXN];
int Prime[1000];
int Divisors[MAXN][64];
int iter = 0;
int pos = 0;
long start, now;
bool out = false;

void back(int l)
{
	int i;

	iter++;

	if (l == 0)
		return;
	/*if (out)
		return;
	now = clock();
	if (now - start > 950)
	{
		out = true;
		return;
	}*/

	if (l > MaxLen)
	{
		pos = iter;
		memcpy(Best, S, sizeof(S));
		MaxLen = l;
		NSol = 1;
		memcpy(BestV[0], S, sizeof(S));
	} else
	if (l == MaxLen)
	{
		memcpy(BestV[NSol++], S, sizeof(S));
	}

	int last = S[l - 1];
	for (i = 1; i <= Divisors[last][0]; i++)
	{
		int nr = Divisors[last][i];
		if (!Flag[nr])
		{
			Flag[nr] = 1;
			S[l] = nr;

			back(l + 1);

			Flag[nr] = 0;
			S[l] = 0;
		}
	}
}


int main()
{
	int i, j;

	Prime[2] = 1;
	Prime[3] = 1;
	Prime[5] = 1;
	Prime[7] = 1;
	Prime[11] = 1;
	Prime[13] = 1;
	Prime[17] = 1;
	Prime[19] = 1;
	Prime[23] = 1;
	Prime[29] = 1;
	Prime[31] = 1;
	Prime[37] = 1;
	Prime[41] = 1;
	Prime[43] = 1;
	Prime[47] = 1;

	// compute divisors for each number
	

	while (true)
	{
		printf("\n\n\nN = ");
		scanf("%d", &N);
		//if (N == 0)break;

		memset(Divisors, 0, sizeof(Divisors));
		for (i = 1; i <= N; i++)
			for (j = 2; j <= N; j++)
			{
				if (i == 1 && 2 * j > N + 1 && N > 3) continue;
				if ((i % j == 0 || j % i == 0) && i != j)
					Divisors[i][++Divisors[i][0]] = j;
			};;


		iter = pos = 0;
		NSol = 0;
		MaxLen = 0;
		S[0] = 1;
		Flag[1] = 1;

		out = false;
		start = clock();
		back(1);

		//printf("Len = %d\n", MaxLen);
		printf("%d\n", MaxLen);
		for (int j = 0; j < NSol; j++)
		{
			memset(Not, 0, sizeof(Not));
			memset(Fact, 0, sizeof(Fact));

			printf("S = ");
			for (i = 0; i < MaxLen; i++)
			{
				printf("%2d ", BestV[j][i]);
				Not[BestV[j][i]] = 1;
			}
			printf("Not: ");
			for (i = 1; i <= N; i++)
				if (Not[i] == 0 && !(Prime[i] && i > N / 2))
					printf("%2d ", i);
			printf("\n");
		}

		printf("\n\nThe solution was found at iteration %d out of %d (%.3lf%%)", pos, iter, ((double)pos / (double)iter) * 100);
	}

	return 0;
}
