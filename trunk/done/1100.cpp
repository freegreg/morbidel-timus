/*
 *  ACM Online
 *  Final Standings - Problem 1100
 *
 *  solutie: baleiem descresc†tor dup† made si le afis†m Œn ordinea citit† !
 */

#include <stdio.h>

long n;
struct team
{
	long id;
	int made;
} t[150000L];


int main()
{
	long i, j;

	scanf("%ld", &n);
	for (i = 0; i < n; i++)
		scanf("%ld %d", &t[i].id, &t[i].made);

	for (i = 100; i >= 0; i--)
		for (j = 0; j < n; j++)
			if (t[j].made == i)
				printf("%ld %d\n", t[j].id, t[j].made);

	return 0;
}
