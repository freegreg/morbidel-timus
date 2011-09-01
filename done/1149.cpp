// ACM Online
// Sinus Dances - Problem 1149

// An=sin(1-sin(2+sin(3-sin(4+...sin(n))...)
// Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
// Print Sn for N <= 200

// asta-i problem†? zi m†? ce rƒzi asa?

#include <stdio.h>

int n;

void print_ax(int x)
{
	int i;
	char sgn;
	for (i = 1; i < x; i++)
	{
		sgn = (i % 2) ? '-' : '+';
		printf("sin(%d%c", i, sgn);
	}
	printf("sin(%d)", x);
	for (i = 1; i < x; i++, printf(")"));
}

void print_sx(int x)
{
	int i;
	for (i = 1; i < x; i++, printf("("));
	for (i = 1; i < x; i++)
	{
		print_ax(i);
		printf("+%d)", x - i + 1);
	}
	print_ax(x);
	printf("+1");
}

int main()
{
	scanf("%d", &n);
	print_sx(n);
	return 0;
}
