/*
 *  ACM Online
 *  Questions - Problem 1098
 *
 *  solutie: se cere ultimul element din perm. Joseph. R†spunsul e dat de ultima
 *  valoare a expresiei l = (l + n - 1) % i + 1 deoarece... ei, las†!
 */

#include <stdio.h>

int n = 0, k, Last;
char Text[30010];


int main()
{
	int i;
	char ch;

	while (scanf("%c", &ch) == 1)
		if (ch != 10 && ch != 13 && ch != 26)
			Text[++n] = ch;

	k = 1999; Last = 1;

	for (i = 1; i <= n; i++)
		Last = (Last + k - 1) % i + 1;
	if (Text[Last] == ' ') printf("No\n"); else
	if (Text[Last] == '?') printf("Yes\n"); else
		printf("No comments\n");

	return 0;
}
