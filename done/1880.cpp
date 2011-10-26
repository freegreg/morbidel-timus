/*
 * ACM Timus Online Judge Contest 22 October 2011
 * Problem H - Psych Up's Eigenvalues
 */

#include <cstdio>
#include <map>

int Res;
std::map<int, int> M;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int i, n, x;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		M[x]++;
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		M[x]++;
	}

	Res = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		M[x]++;

		if (M[x] >= 3)
		{
			Res++;
		}
	}

	printf("%d", Res);

	return 0;
}