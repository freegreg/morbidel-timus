#include <stdio.h>


#define max(a, b) ((a) > (b) ? (a) : (b))

long A, A1, A2, B, B1, B2;

int main()
{
	A = A1 = A2 = 0;
	B = B1 = B2 = 0;

	freopen("file.in", "rt", stdin);
	while (true)
	{
		char ch;
		int len = 0;

		while (true)
		{
			if (scanf("%c", &ch) != 1)
			{
				if (len != 0)
				{
					A = len + max(A2, B2);				// pun
					B = max(A1, B1);					// nu pun
				}

				printf("%d\n", max(A, B));
				return 0;
			}

			if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
				len++;
			else
				break;
		}

		if (len == 0)
			continue;

		A = len + max(A2, B2);				// pun
		B = max(A1, B1);					// nu pun

		A2 = A1; A1 = A;
		B2 = B1; B1 = B;
	}


	return 0;
}

