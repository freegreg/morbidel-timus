#include <stdio.h>


long A[20][200][20], S, Sol;


int main()
{
	int i, j, k, t;


	scanf("%ld", &S);

	for (i = 0; i < 10; i++)
		A[1][i][i] = 1;

	for (i = 0; i < 10; i++)
		for (j = 0; j < 100; j++)
			for (k = 0; k < 10; k++)
				if (A[i][j][k] != 0)
					for (t = 0; t < 10; t++)
						A[i + 1][j + t][t] += A[i][j][k];


	if (S == 1)
		Sol = 10;
	else
	{
		Sol = 0;

		for (i = 1; i < 10; i++)
			for (t = 1; t < 10; t++)
				Sol += A[i][S][t];
	}

	printf("%ld\n", Sol);


	return 0;
}
