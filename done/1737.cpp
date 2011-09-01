#include <stdio.h>
#include <string.h>

int N, Sol;
char S[20001];


void back(int l)
{
	char ch;

	if (l == N)
	{
		Sol += strlen(S);
		printf("%s\n", S);
		return;
	}

	for (ch = 'a'; ch <= 'c'; ch ++)
	{
		if (l > 0 && ch == S[l - 1])
			continue;
		if (l > 1 && ch == S[l - 2])
			continue;

		S[l] = ch;
		back (l + 1);
		S[l] = 0;
	}
}

int main()
{
	scanf("%d", &N);

	if (N >= 16667)
	{
		printf("TOO LONG");
		return 0;
	}

	memset(S, 0, sizeof(S));
	Sol = 0;
	back(0);

	//printf("total lengths: %d\n", Sol);

	return 0;
}
