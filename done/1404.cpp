/*
 *  ACM Timus - Easy to Hack!
 */

#include <stdio.h>
#include <string.h>

char S[128];
int N, Cost[128];



int main()
{
	scanf("%s", &S);
	N = strlen(S);

	int i;

	for (i = 0; i < N; i++)
		Cost[i] = S[i] - 'a';

	for (i = 1; i < N; i++)
		while (Cost[i] < Cost[i - 1])
			Cost[i] += 26;

	for (i = N - 1; i > 0; i--)
		Cost[i] -= Cost[i - 1];
	Cost[0] -= 5;
	while (Cost[0] < 0)
		Cost[0] += 26;

	for (i = 0; i < N; i++)
		printf("%c", Cost[i] + 'a');
	printf("\n");

	return 0;
}
