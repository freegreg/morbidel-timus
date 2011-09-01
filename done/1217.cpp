/*
 *  ACM Timus Online
 *  Unlucky Tickets - Problem 1217
 *
 *  solutie: de la Radu...
 */

#include <stdio.h>


__int64 A[11][91][91];

#define A(i, j, k) (A[i][j][(k)+45])


void calc()
{
    int i, j, k, c;
    A(0, 0, 0) = 1;
    for (i = 0; i < 10; i++)
		for (j = 0; j <= 90; j++)
			for (k = -45; k <= 45; k++)
				for (c = 0; c < 10; c++)
					A(i + 1, j + c, (i % 2) ? k - c : k + c) += A(i, j, k);
}

__int64 get(int N)
{
    __int64 R = 0;
    int j, k;

    for (j = 0; j <= 90; j++)
        for (k = -45; k <= 45; k++)
            R += A(N / 2, j, k) * A(N / 2, j, (N / 2 % 2) ? k : -k);

    return R;
}

int N;

int main()
{
    calc();
    scanf("%d", &N);
    printf("%.I64d\n", get(N));
    return 0;
}
