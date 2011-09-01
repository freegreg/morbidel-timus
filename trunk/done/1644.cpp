/*
 * ACM Timus Online
 * A whole lot of walnuts - problem 1644
 */

#include <cstdio>

int N;

int main()
{
	int i, w, hun, sat;
	char r[16];

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d", &N);

	hun = 2;
	sat = 10;

	for (i = 0; i < N; i++)
	{
		scanf("%d %s\n", &w, &r);

		if (r[0] == 'h')
		{
			if (w > hun)
				hun = w;
			if (hun >= sat)
			{
				printf("Inconsistent\n");
				return 0;
			}
		}
		else if (r[0] == 's')
		{
			if (w < sat)
				sat = w;
			if (sat <= hun)
			{
				printf("Inconsistent\n");
				return 0;
			}
		}
	}

	printf("%d\n", sat);

	return 0;
}
