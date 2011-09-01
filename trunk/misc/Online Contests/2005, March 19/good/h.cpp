#include <stdio.h>
#include <string.h>

#define MAXN 10001


typedef char cuv[MAXN];

int N;
cuv S, IS;


void reverse(cuv &rev)
{
	char ch;
	int n = strlen(rev);

	for (int i = 0; i < n / 2; i++)
		ch = rev[i], rev[i] = rev[n - i - 1], rev[n - i - 1] = ch;
}

int main()
{
	int i, j, ok;

	/*FILE *f = fopen("file.in", "w");
	for (i = 0; i < 10000; i++)
		fprintf(f, "a");
	fclose(f);*/


	#ifndef ONLINE_JUDGE
	//freopen("file.in", "r", stdin);
	#endif

	scanf("%s", &S);
	strcpy(IS, S);
	reverse(IS);

	N = strlen(S);

	for (i = 1; i < N; i++)
	{
		ok = 1;

		for (j = i; j < N; j++)
			if (S[j] != IS[j - i])
				ok = 0, j = N;

		if (ok)
			break;
	}

	for (j = i; j < i + N; j++)
		S[j] = IS[j - i];

	if (!N)
		S[0] = 'a';
	printf("%s\n", S);


	return 0;
}
