// ACM Online
// A square problem - Problem 1073

// solutie: rucsac cu minim de obiecte

#include <stdio.h>
#include <string.h>
#include <math.h>

long n, k, v[1000];
long q[60001L], no[60001L];

void main()
{
	long i, j, max = 0;
	scanf("%ld", &k);
	n = sqrtl(k); n++;
	for (i = 1; i < n; i++) v[n - i - 1] = i * i;
	v[n - 1] = v[n] = 1; n++;
	memset(q, 0, sizeof(q));
	memset(no, 127, sizeof(no));
	for (i = 0; i < n; i++)
	{
		for (j = max; j; j--)
			if (q[j] && j + v[i] <= k && no[j] + 1 < no[j + v[i]])
			{
				q[j + v[i]] = v[i];
				no[j + v[i]] = no[j] + 1;
				if (j + v[i] > max) max = j + v[i];
			}
		if (!q[v[i]])
		{
			no[v[i]] = 1;
			q[v[i]] = v[i];
			if (v[i] > max) max = v[i];
		}
	}
	printf("%d", no[k]);
}