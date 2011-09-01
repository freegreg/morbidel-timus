/*
 *  ACM Online
 *  The False Mirrors - Problem 1152
 *
 *  solutie: sunt doar 20 de numere asa ca generam toate alea...
 *  afiseaza si solutia... (luam TLE pt ca nu ieseam cand era > minim...)
 */

#include <stdio.h>

#define next(xx) ((xx) % N + 1)

int V[30], Flag[30], S[30], Sol[30];
int N, TSum = 0, DMin = 0x7FFF;



void readdata()
{
	int i;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", V + i), TSum += V[i];
}

void back(int lev, int damage, int left)
{
	int i, n1, n2, w1 = 0, w2;

	if (damage > DMin) return;

	for (i = 1; i <= N; i++)
	   	if (!Flag[i]) w1 = 1, i = N;

    if (!w1 && damage < DMin)
    {
    	DMin = damage;
		for (i = 1; i <= N; i++)
			Sol[i] = S[i];
	} else
	for (i = 1; i <= N; i++)
		if (!Flag[i])
		{
			S[lev] = i; w1 = w2 = 0;
			n1 = next(i); n2 = next(i + 1);
			left -= V[i] + V[n1] + V[n2];
			if (Flag[n1]) left += V[n1], w1 = 1;
			if (Flag[n2]) left += V[n2], w2 = 1;
			Flag[i] = Flag[n1] = Flag[n2] = 1;

			back(lev + 1, damage + left, left);

			left += V[i] + V[n1] + V[n2];
			Flag[i] = Flag[n1] = Flag[n2] = 0;
			if (w1) left -= V[n1], Flag[n1] = 1;
			if (w2) left -= V[n2], Flag[n2] = 1;
			S[lev] = 0;
		}
}

void solve()
{
	back(1, 0, TSum);
	printf("%d\n", DMin);
}

void writesol()
{
	int i, n1, n2;

	for (i = 0; i <= N; Flag[i++] = 0);
	for (i = 1; i <= N; i++)
		if (Sol[i])
		{
			printf("start %d -> ", Sol[i]);
			n1 = next(Sol[i]);
			n2 = next(Sol[i] + 1);
			printf("%d ", V[Sol[i]]);
			Flag[Sol[i]] = 1;
			if (!Flag[n1]) printf("%d ", V[n1]), Flag[n1] = 1;
			if (!Flag[n2]) printf("%d ", V[n2]), Flag[n2] = 1;
			printf("\n");
		}
	printf("\n\n");
}


int main()
{
	readdata();
	solve();
	//writesol();

	return 0;
}
/*
	In transee napalm maree, agilitate de puma. Trebuie sa retii, trebuie sa
	mentii, armele trebuie sa le mentii, pe toti dementii sa dea dreapta cu dreptii...
 */
