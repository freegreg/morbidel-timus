/*
 *  Fairy tales
 */

#include <stdio.h>


__int64 Dig, N, Pow;

bool prime(__int64 x)
{
	__int64 i;

	if (x == 1) return false;

	for (i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;

	return true;
}


int main()
{
	char ch;
	int i;
	N = 0;


	scanf("%I64d", &Dig);

	for (i = 0; i < Dig; i++)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			i--;
		else
			N = N * 10 + ch - '0';
	}

	if (N == 0)
		N = 1, Dig++;

	for (Pow = 1; Dig < 12; Dig++, Pow *= 10)
		N *= 10;


	for (i = 0; i < Pow; i++)
		if (prime(N + i))
		{
			N += i;
			break;
		}

	printf("%012I64d\n", N);


	return 0;
}
