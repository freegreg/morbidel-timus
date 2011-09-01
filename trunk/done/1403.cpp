/*
 *  ACM Timus - Courier
 */

#include <stdio.h>

#define MAXN 1024

int N, Best;
int Time[MAXN], Revenue[MAXN];
int Index[MAXN], Flag[MAXN];


void Readdata()
{
	int i;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d %d", &Time[i], &Revenue[i]), Index[i] = i;
}

void Solve()
{
	int count = 0;
	int i, j, time, aux, min = 1000000000;


	for (i = 1; i <= N; i++)
		for (j = i + 1; j <= N; j++)
			if (Time[i] > Time[j] || (Time[i] == Time[j] && Revenue[i] < Revenue[j]))
			{
				aux = Time[i], Time[i] = Time[j], Time[j] = aux;
				aux = Revenue[i], Revenue[i] = Revenue[j], Revenue[j] = aux;
				aux = Index[i], Index[i] = Index[j], Index[j] = aux;
			};

	Best = 0;
	for (time = 1, i = 1; i <= N; i++)
		if (time <= Time[i])
		{
			time++;
			Best += Revenue[i];
			Flag[i] = 1;
			if (Revenue[i] < min)
				min = Revenue[i];
		}
		else
		{
			for (j = i - 1; j > 0; j--)
				if (Flag[j] && Revenue[i] > min && Revenue[j] == min)
				{
					Best += Revenue[i] - Revenue[j];
					Flag[j] = 0;
					Flag[i] = 1;
					min = Revenue[i];
					break;
				}
			for (j = i - 1; j > 0; j--)
				if (Flag[j] && Revenue[j] < min)
					min = Revenue[j];
		}

	printf("%d\n", time - 1);
	for (i = 1; i <= N; i++)
		if (Flag[i])
			printf("%d ", Index[i]);
}

int main()
{
	Readdata();
	Solve();

	return 0;
}
