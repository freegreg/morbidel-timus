/*
 * ACM Timus Online Judge Contest 22 October 2011
 * Problem I - Long problem statement
 */

#include <cstdio>
#include <cstring>

int H, W, N, Pages;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int i, len, symbols, lines;
	char word[128];

	scanf("%d %d %d", &H, &W, &N);

	Pages = 0;
	symbols = 0;
	lines = 1;
	for (i = 0; i < N; i++)
	{
		scanf("%s\n", word);
		len = strlen(word);

		// pot sa-l pun pe randul actual?
		if (len + 1 > W - symbols && symbols != 0)
		{
			symbols = len;
			lines++;
		}
		else
		{
			symbols += (symbols == 0) ? len : len + 1;
		}
	}

	Pages = lines / H;
	if (lines % H)
		Pages++;

	printf("%d", Pages);

	return 0;
}