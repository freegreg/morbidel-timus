/*
 *  ACM Timus Online
 *  Decoding Task  - Problem 1236
 */

#include <stdio.h>
#include <string.h>

#define input "file.in"
#define MAXN 10010

short N;
short E1[MAXN], E2[MAXN], Key[MAXN];
char s[MAXN * 2], D[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


void readdata()
{
	int i, l;


	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%s\n", &s);
	for (i = 0, l = strlen(s); i < l; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			s[i] -= '0';
		else
			s[i] = s[i] - 'A' + 10;
		if (i & 1)
			E1[i / 2] += s[i];
		else
			E1[i / 2] = s[i] << 4;
	}


	N = l / 2;

	scanf("%s\n", &s);
	for (i = 0, l = strlen(s); i < l; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			s[i] -= '0';
		else
			s[i] = s[i] - 'A' + 10;
		if (i & 1)
			E2[i / 2] += s[i];
		else
			E2[i / 2] = s[i] << 4;
	}

}

void solve()
{
	int i;


	Key[0] = E2[0] ^ 32;

	for (i = 0; i < N; i++)
		Key[i + 1] = E2[i + 1] ^ E1[i] ^ Key[i];


	for (i = 0; i <= N; i++)
		printf("%c%c", D[Key[i] >> 4], D[Key[i] % 16]);

	printf("\n");
}

int main()
{
	readdata();
	solve();

	return 0;
}
