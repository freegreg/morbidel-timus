/*
 *  ACM Timus Online
 *  AntiCAPS - Problem 1601
 */

#include <stdio.h>
#include <string>

using namespace std;


#define LOWERCASE(ch)		(ch >= 'a' && ch <= 'z')
#define UPPERCASE(ch)		(ch >= 'A' && ch <= 'Z')
#define LETTER(ch)			(LOWERCASE(ch) || UPPERCASE(ch))
#define TERMINATOR(ch)		(ch == '.' || ch == '!' || ch == '?')

#define TOLOWER(ch)			(UPPERCASE(ch) ? (ch + 32) : (LOWERCASE(ch) ? ch : 0))
#define TOUPPER(ch)			(LOWERCASE(ch) ? (ch - 32) : (UPPERCASE(ch) ? ch : 0))



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	char ch;
	bool bSentence = false;

	while (scanf("%c", &ch) == 1)
	{
		if (!LETTER(ch))
			printf("%c", ch);

		if (TERMINATOR(ch))
		{
			bSentence = false;
		}

		if (LETTER(ch))
		{
			if (!bSentence)
			{
				// e prima litera
				bSentence = true;

				ch = TOUPPER(ch);
			} else
			{
				ch = TOLOWER(ch);
			}

			printf("%c", ch);
		}
	}

	return 0;
}
