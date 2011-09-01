/*
 *  ACM Timus Online
 *  Collective Guarantee - Problem 1211
 */

#include <stdio.h>

#define MAXN 25001

int N, NT, V[MAXN], Val[MAXN];


void readdata()
{
	int i;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", V + i);
}

void solve()
{
	int i, j;


	for j = 0, i = 1; i <= N; i++)
		j += (!V[i]), Val[i] = 0;

	if (j > 1 || j== 0) /*  au recunoscut mai multi sau niciunul  */
	{
		printf("NO\n");
		return;
	}

	for (i = 1; i <= N; i++)
		if (!Val[i])
		{
			/*  bifam cu i-uri ciclul  */
			for (j = i; Val[j] == 0 && V[j] != 0; j = V[j])
				Val[j] = i;

			if (Val[j] == i) /*  e ciclu, s-a rupt filmul :D  */
			{
				printf("NO\n");
				return;
			}
		}

	printf("YES\n");
}


int main()
{
	//freopen("file.in", "r", stdin);

	for (scanf("%d", &NT); NT--; )
	{
		readdata();
		solve();
	}

	return 0;
}
