/*
 * ACM Timus Online
 * Stacks - Problem 1220
 *
 * sol: read the input twice: first time count the number of pushes for each 
 */

#include <cstdio>
#include <string.h>

#define MAX_OPS		100000
#define MAX_STACKS	1000

int N;
int V[MAX_OPS];				/* mega-stack :) */
int Count[MAX_STACKS + 1];
int SP[MAX_STACKS + 1];			/* stack pointer for each stack */

int main()
{
	int i, st, value;
	char op[8];
	

	for (i = 0; i <= MAX_STACKS; i++)
		Count[i] = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s %d", &op, &st);

		if (op[1] == 'U')	/* PUSH operation */
		{
			scanf("%d", &value);
			Count[st] ++;
		}
	}

	SP[0] = 0;
	/* compute starting positions in the mega-stack for each stack */
	for (i = 1; i <= MAX_STACKS; i++)
		SP[i] = SP[i - 1] + Count[i - 1];

	/* re-read the input :) */
	fseek(stdin, 0, SEEK_SET);
	
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s %d", &op, &st);

		if (op[1] == 'U')	/* PUSH operation */
		{
			scanf("%d", &value);
			V[SP[st] ++] = value;
		}
		else			/* POP operation */
		{
			printf("%d\n", V[--SP[st]]);
		}
	}

	return 0;
}
