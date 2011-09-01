/*
 * ACM Timus Online
 * Cipher Grille - Problem 1712
 *
 * solution: simulate the rotations...
 */

#include <cstdio>
#include <string.h>
#include <string>

typedef char matrix[8][8];
matrix Mask, Grill;
std::string Pass;

void Rotate90(matrix &a)
{
	int i, j;
	matrix t;

	memcpy(t, a, sizeof(a));

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			a[j][3 - i] = t[i][j];
		};
}


int main()
{
	int i, j, k;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	for (i = 0; i < 4; i++)
		scanf("%s\n", &Mask[i]);
	for (i = 0; i < 4; i++)
		scanf("%s\n", &Grill[i]);

	Pass = "";
	/* original + 3 rotations */
	for (k = 0; k < 4; k++)
	{
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (Mask[i][j] == 'X')
					Pass += Grill[i][j];
		Rotate90(Mask);
	}

	printf("%s\n", Pass.c_str());


	return 0;
}
