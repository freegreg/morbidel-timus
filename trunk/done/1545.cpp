/*
 *  ACM Timus Online
 *  Hieroglyphs - Problem 1545
 */


#include <stdio.h>

int n;
char s[1024][2];
char let;

int main()
{
int i;
scanf("%d", &n);
for (i = 0; i < n; i++)
{
scanf("%s\n", &s[i]);
}
scanf("%c", &let);

for (i = 0; i < 2 * n; i += 2)
if (s[0][i] == let)
printf("%c%c\n", s[0][i], s[0][i+1]);
return 0;
}