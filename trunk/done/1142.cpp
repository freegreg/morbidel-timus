/*
 *  ACM Online
 *  Relation - Problem 1142
 *
 *  solutie: constante dar f†cusem un super back...
 */

#include <stdio.h>

long N, sol[] = {0, 0, 3, 13, 75, 541, 4683, 47293L, 545835L, 7087261L, 102247563L};

int main()
{
	do
	{
		scanf("%ld", &N);
		if (N == -1) break;
		printf("%ld\n", sol[N]);
	}
	while (1);

	return 0;
}
