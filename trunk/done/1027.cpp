/*
 *  ACM Timus Online
 *  D++ Again - Problem 1027
 *
 *  sloboz de cacat de problema, bine ca am avut testele (he he he...)
 */

#include <stdio.h>

#define INPUT	"input.txt"

#define gata { ok = 0; break; }


int ch, ooch, och, aritm = 0, comment = 0, ok = 1, cp = 0, pa, para = 0, index = 0;


int arit(char c)
{
	return ((c >= '0' && c <= '9') || c == '=' || c == '+' || c  == '-' || c == '*' || c == '/' || c == ')' || c == '(');
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(INPUT, "r", stdin);
	#endif

	scanf("%c", &och);
	if (och == '(') 
		aritm = para = 1;
	if (och == ')')
	{
		printf("NO\n");
		return 0;
	}
	while (scanf("%c", &ch) == 1)
	{
		index++;
		if (ch == '\n') continue;
		cp++;
		if (comment && ch != ')' && och != '*') 
		{
			ooch = och; och = ch;
			continue;
		} 
		if (ch == '(' && !aritm && !comment) 
		{
			para = aritm = 1; pa = cp;
			ooch = och; och = ch;
			continue;
		} 

		if ((ch == '(' || ch == ')') && !comment && !aritm) 
			gata;
		if (aritm && ch == '(' && !comment) para++; else
		if (ch == ')' && aritm && !comment) 
		{
			para--;
			if (!para) 
				aritm = 0;
		}
		if (aritm && !comment && !arit(ch)) 
			gata;

		if (ch == ')' && och == '*')  /*  comentariu inchis  */ 
		{
			// caz pentru (*), verific daca comentariul fusese deschis acum 2 caractere sau mai demult
			if (ooch == '(' && index - comment < 2) gata else
			if (comment) 
				comment = 0, para--;
		} else
		if (ch == '*' && och == '(' && !comment) /*  comentariu deschis  */
		{
			comment = index;
			if (aritm && pa == cp - 1 && para == 1)
				aritm = 0, para = 1;
		}

		ooch = och; och = ch;
	}
	if (comment || aritm || para) 
		ok = 0;

	printf("%s\n", ok ? "YES" : "NO");

	return 0;
}
