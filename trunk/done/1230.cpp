/*
 *  ACM Online
 *  An introspective program - Problem 1230
 *
 *  am luat-o de pe forum...
 */

#include <stdio.h>

int main()
{
	printf("X='%c';Y=%c'%c;", 34, 34, 34);
	printf("?'X='+Y+X+Y+';Y='+X+Y+X+';';");
	printf("A=%c?'X='+Y+X+Y+';Y='+X+Y+X+';';?$(A,1,28);?'A='+X+A+X+';';?$(A,29,38)%c;", 34, 34);
	printf("?$(A,1,28);?'A='+X+A+X+';';?$(A,29,38)");

	return 0;
}
