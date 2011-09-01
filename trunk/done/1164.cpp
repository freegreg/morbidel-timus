/*
 *  ACM Online
 *  Fillword - Problem 1164
 *
 *  solutie: banal, se bazeaz† pe faptul c† exist† mereu solutie, altfel
 *  trebuia s-o g†sim si era un back naspa... Dar asa num†r†m frecventele
 *  din careu si apoi pe cele din cuvinte si le sc†dem. Ce r†mƒne sunt alea
 *  libere
 */

#include <stdio.h>
#include <string.h>

int M, N, P, flag[300];
char cuv[200];


int main()
{
	int i, j;

	for (i = 'A'; i <= 'Z'; flag[i++] = 0);

	scanf("%d %d %d", &N, &M, &P);
	for (i = 0; i < N; i++)
		for (scanf("%s\n", &cuv), j = 0; j < M; j++)
			flag[cuv[j]]++;
	for (i = 0; i < P; i++)
		for (scanf("%s\n", &cuv), j = strlen(cuv) - 1; j >= 0; j--)
			flag[cuv[j]]--;

	for (i = 'A'; i <= 'Z'; i++)
		for (j = 0; j < flag[i]; j++)
			printf("%c", i);
	printf("\n");

	return 0;
}

/*
 *  In a cold and dark December, I decided to leave my home
 *  took a train to nowhere, far away...
 *  In the night the seawinds are calling...
 */
