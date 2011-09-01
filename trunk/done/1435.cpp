/*
 *  ACM Timus Online
 *  Financial Error - Problem 1435
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define input	"file.in"
#define MAXN	1500100L

long N;
long A[MAXN];
__int64 Sum, Total, Delta;


int SwitchDigits(__int64 &num, int p1, int p2)
{
	char n[32], ch;

	_ltoa(num, n, 10);

	if (p1 >= strlen(n) || p2 >= strlen(n)) 
		return 1;

	_strrev(n);

	ch = n[p1];
	n[p1] = n[p2];
	n[p2] = ch;
	
	if (n[p2] == '0' && p2 == strlen(n) - 1)
		return 1;

	_strrev(n);

	num = _atoi64(n);

	return 0;
}

int main()
{
	long i;

#ifndef ONLINE_JUDGE
	freopen(input, "rt", stdin);
#endif
	scanf("%d\n", &N);

	Total = 0;
	for (i = 0; i < N; i++)
	{
		char num[16];
		gets(num);

		A[i] = atol(num);

		//scanf("%ld", A + i);
		Total += (__int64)A[i];
	}
	scanf("%I64d", &Sum);

	Delta = Sum - Total;

	if (Delta < 0) Delta *= -1;

	if (Delta == 0)
	{
		printf("Input has no error.\n");
		return 0;
	}

	int pos;
	__int64 t1 = 9, t2 = 81;

	for (pos = 0; pos < 1000; pos++)
	{
		if (t1 <= Delta && Delta <= t2) break;
		t1 *= 10;
		t2 *= 10;
	}

	for (i = 0; i < N; i++)
	{
		__int64 elem = A[i];

		Total -= elem;

		if (!SwitchDigits(elem, pos, pos + 1))
		{
			Total += elem;
			if (Total == Sum)
			{
				printf("Error in record #%ld. Correct number is: %I64d.\n", i + 1, elem);
				return 0;
			}
			Total -= elem;

			SwitchDigits(elem, pos, pos + 1);
		}

		Total += elem;
	}

	printf("Unrecoverable error.\n");


	return 0;
}
