/*
 * ACM Timus
 * Werewolf - Problem 1242
 *
 * soluție: bifăm ascendenții tuturor victimelor
 */


#include <cstdio>
#include <cstring>

int N, T1[1024], T2[1024], Flag[1024];

int main()
{
	char line[100];
	int i;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d\n", &N);

	for (i = 1; i <= N; i++)
	{

	}
	memset(T1, 0, sizeof(T1));
	memset(Flag, 0, sizeof(Flag));

	while (true)
	{
		gets(line);

		if (!strcmp(line, "BLOOD"))
			break;

		int s, p;
		sscanf(line, "%d %d", &s, &p);

		T[s] = p;
	}

	int victim;
	while (scanf("%d", &victim) == 1)
	{

	}

	bool sol = false;
}
	if (!sol)
		printf("0");
}
