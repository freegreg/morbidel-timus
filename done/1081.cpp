// ACM Online
// Problem 1081 - Binary Lexicographic Sequence

// solutie: sunt fibo[n + 2] maxim de din alea si le generam usor...

#include <stdio.h>

long n, k, fibo[50];
int s[50];

void rec(int nn, int kk)
{
	int f1 = fibo[nn + 1];
	if (!nn) return;
	printf(kk > f1 ? "1" : "0");
	rec(nn - 1, kk - (kk > f1 ? f1 : 0));
}

void main()
{
	int i;
	scanf("%ld %ld", &n, &k);
	fibo[0] = 0; fibo[1] = 1;
	for (i = 2; i <= n + 2; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	if (k > fibo[n + 2]) printf("-1"); else
		rec(n, k);
}