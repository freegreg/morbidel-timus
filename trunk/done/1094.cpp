/*
 *  ACM Online
 *  E-Screen - Problem 1094
 *
 *  solutie: baleiem textul si retinem pozitia curenta...
 */

#include <stdio.h>
#include <string.h>
#include <string>

char ch, sz[10001], scr[100];

std::string s;


int main()
{
	int i, p1 = 0, mp = 0;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	memset(scr, ' ', sizeof(scr));
	s = "";

	while (fgets(sz, 10000, stdin))
	{
		s += sz;
	}

	for (i = 0; i < s.size(); i++)
	{
		ch = s[i];
		if (ch == '\n') continue;
		if (ch == '>')
		{
			p1++;
			if (p1 > mp) 
				mp = p1;
			if (p1 == 80) 
				p1 = 0;
		} else
		if (ch == '<' && p1) 
			p1--;
		else
		if (ch != '<' && ch != '>')
			scr[++p1] = ch;
		
		if (p1 > mp) 
			mp = p1;
		if (p1 == 80) 
			p1 = 0;
	}

	for (i = 1; i <= 80; i++)
		printf("%c", scr[i]);

	return 0;
}
