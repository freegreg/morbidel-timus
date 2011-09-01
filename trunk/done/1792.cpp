/*
 * ACM Timus Online
 * Hamming Code - Problem 1792
 *
 * solution: change every integer and check if the code becomes Hamming (if it's not in the first place)
 */

#include <cstdio>

int A[8];

bool IsHamming()
{
	int petal1 = (A[1] + A[2] + A[3]) % 2;
	int petal2 = (A[0] + A[2] + A[3]) % 2;
	int petal3 = (A[0] + A[1] + A[3]) % 2;

	return (petal1 == A[4] && petal2 == A[5] && petal3 == A[6]);
}

int main()
{
	int i;

	for (i = 0; i < 7; i++)
		scanf("%d", A + i);

	if (!IsHamming())
	{
		for (i = 0; i < 7; i++)
		{
			A[i] = 1 - A[i];

			if (IsHamming())
				break;

			A[i] = 1 - A[i];
		}
	}

	for (i = 0; i < 7; i++)
		printf("%d ", A[i]);

	return 0;
}
