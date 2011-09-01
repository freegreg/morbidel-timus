// ACM Online
// se da un vector cu n elemente (10000 n, 15000 a[i])
// gasiti niste elemente din vector a caror suma e div. cu N

// solutie: se face in O(N):
// facem sumele (1..N) apoi resturile lor la N si selectam grupele cu restul
// egal si le scadem... (!)

#include <stdio.h>
#include <string.h>

#define NMAX 10000

FILE *f;
int n, p1, p2, flag[NMAX], a[NMAX];
long s[NMAX];

void main()
{
	int i;
	memset(flag, -1, sizeof(flag));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s[i] += i ? s[i - 1] + a[i] : a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (flag[s[i] % n] >= 0)
		{
			p1 = flag[s[i] % n];
			p2 = i; break;
		} else
			flag[s[i] % n] = i;
		if (flag[0] >= 0)
		{
			p1 = -1; p2 = flag[0];
			break;
		}
	}
	if (p2 - p1 == 1 && !a[p2]) printf("0"); else
	{
		printf("%d\n", p2 - p1);
		for (i = p1 + 1; i <= p2; printf("%d\n", a[i++]));
	}
}