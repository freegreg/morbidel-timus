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

#define input "fillw.in"
#define output "fillw.out"

FILE *f;
int M, N, P, flag[300];
char cuv[200];


int main()
{
	int i, j;

	for (i = 'A'; i <= 'Z'; flag[i++] = 0);

	f = fopen(input, "r");
	fscanf(f, "%d %d %d", &N, &M, &P);
	for (i = 0; i < N; i++)
		for (fscanf(f, "%s\n", &cuv), j = 0; j < M; j++)
			flag[cuv[j]]++;
	for (i = 0; i < P; i++)
		for (fscanf(f, "%s\n", &cuv), j = strlen(cuv) - 1; j >= 0; j--)
			flag[cuv[j]]--;
	fclose(f);

	f = fopen(output, "w");
	for (i = 'A'; i <= 'Z'; i++)
		for (j = 0; j < flag[i]; j++)
			fprintf(f, "%c", i);
	fprintf(f, "\n");
	fclose(f);

	return 0;
}

/*
 *  In a cold and dark December, I decided to leave my home
 *  took a train to nowhere, far away...
 *  In the night the seawinds are calling...
 */
