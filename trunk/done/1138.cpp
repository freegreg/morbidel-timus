/*
 *  ACM Online
 *  Integer Percentage - Problem 1138
 */

#include <stdio.h>

int A, B, V[20001];


int main()
{
	int i, j, nou;

	scanf("%d %d", &B, &A);

	for (V[j = A] = 1; j <= B; j++)
		if (V[j])
			for (i = 1; i <= 100; i++)
				if (j * i % 100 == 0 && V[j] + 1 > V[nou = j + j * i / 100] && nou <= B)
					V[nou] = V[j] + 1;

	for (nou = 0, i = B; i >= A; i--)
		if (V[i] > nou)
			nou = V[i];
	printf("%d\n", nou);

	return 0;
}
