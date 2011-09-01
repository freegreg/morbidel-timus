/*
 *  ACM Timus Online
 *  Tips - Problem 1261
 */

#include <stdio.h>

__int64 M, N, NN, Pow3[100];
short Base3[3][100], Len = 0;


int main()
{
	int i, k;


	scanf("%I64d", &N);

	NN = N;

	while (N)
		Base3[0][Len++] = N % 3, N /= 3;

	for (i = k = 0; i < Len; i++)
		switch (Base3[0][i] + k)
		{
			case 0: Base3[1][i] = Base3[2][i] = 0; break;
			case 1: Base3[1][i] = 0; Base3[2][i] = 1; k = 0; break;
			case 2: Base3[1][i] = 1; Base3[2][i] = 0; k = 1; break;
		}

	if (k) 
		Base3[2][Len++] = 1;

	for (Pow3[0] = i = 1; i <= Len; i++)
		Pow3[i] = Pow3[i - 1] * 3;

	M = 0;

	for (i = 0; i < Len; i++)
		M += Base3[2][i] * Pow3[i];

	if (M == NN)
		M += Pow3[Len];

	printf("%I64d %I64d\n", M, M - NN);


	return 0;
}
