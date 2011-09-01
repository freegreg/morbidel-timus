/*
 *  ACM Online
 *  Recruits - Problem 1135
 *
 *  num†r†m cele > si la < crestem sol cu nr. anterior (f†r† resetare)
 */

#include <stdio.h>

char ch;
long n, sol = 0, cnt = 0;

int main()
{
	scanf("%ld", &n);

	do
	{
		scanf("%c", &ch);
		if (ch == '>') n--, cnt++;
		if (ch == '<') n--, sol += cnt;
	}
	while (n);

	printf("%ld\n", sol);

	return 0;
}
