/*
 *  ACM Timus Contest, 15 Aprilie 2004
 *  Problem F - Spy
 */

#include <stdio.h>
#include <string.h>

#define MAXN 200010
#define pozi(no, cnt) (Miu[no - 1] + cnt - 1) /*  pozitia aparitiei count a lui no pe prima coloana  */

long N, C, Col[MAXN], Poz[MAXN], How[300], Miu[300];
char S[MAXN], Text[300], Text2[300], Flag[MAXN];



int main()
{
	long i, j, x;

	strcpy(Text, "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz");

	//freopen("file.in", "r", stdin);
	scanf("%ld %s", &C, &S);

	for (i = 0; i < 53; i++)
		Text2[Text[i]] = i;

	N = strlen(S);
	for (i = 0; i < N; i++)
		Col[i] = Text2[S[i]], How[Col[i]]++;

	Miu[0] = How[0];
	for (i = 1; i <= 100; i++)
		Miu[i] = Miu[i - 1] + How[i];

	/*  Poz[i] -> al catelea din tipul sau este elementul de pe pozitia i in ultima coloana  */
	for (i = 0; i < N; i++)
		Poz[i] = Flag[Col[i]] + 1, Flag[Col[i]]++;


	/*  algoritmul propriu-zis, al lui Burrows Wheeler parca...  */

	for (x = C - 1, i = 0; i < N; i++, x = pozi(Col[x], j))
		Flag[i] = Col[x], j = Poz[x];

	for (i = N - 1; i >= 0; i--)
		printf("%c", Text[Flag[i]]);
	printf("\n");

	return 0;
}
