// ACM Online
// The time to take stones - Problem 1087
// 2 jucatori, N pietre si putem lua k1, k2, ..., km deodata. Pierd daca o
// iau pe ultima. Cine castiga la joc optim?

// solutie: fiind doar 10000 pietre, tinem in a[i] castigatorul daca sunt i
// pietre si incepe 1. Evident 3 - a[i] e win. daca incepe 2. Recurenta e:
// a[i] = 3 - a[i - k[j]] cu j = 1..m si daca e un 1 -> 1 altfel toti 2 -> 2

#include <stdio.h>

int n, m, a[10001], k[50];

void readdata()
{
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", &k[i]);
}

void solve()
{
	int i, j, s, win;

	a[0] = 1; // nu e nici o piatra -> castiga 1
	for (i = 1; i <= n; i++)
	{
		win = 2;
		for (j = 0; j < m; j++)
			{
				s = i - k[j];
				if (s < 0) continue;
				if (3 - a[s] == 1) win = 1, j = m;
			}
			a[i] = win;
		}
		printf("%d", a[n]);
}

int main()
{
	readdata();
	solve();
	return 0;
}
