/*
 *  ACM Online
 *  Cards - Problem 1134
 *
 *  le sort†m apoi le distribuim c†tre cea mai mic† pozitie
 */

#include <stdio.h>

int n, m, v[1010], flag[1010];

int main()
{
	int i, j, k = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", &v[0]), flag[v[0]]++;

	for (i = 0; i <= n; flag[i++] = 0)
		for (j = 0; j < flag[i]; j++)
			v[k++] = i;
	for (i = 0; i < m; i++)
	{
		if (!flag[v[i]] && v[i] <= n && v[i])
			flag[v[i]] = 1; else
		if (!flag[v[i] + 1] && v[i] + 1 <= n)
			flag[v[i] + 1] = 1;
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}
