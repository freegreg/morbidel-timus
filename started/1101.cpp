/*
 *  ACM Timus Online
 *  Robot In The Field - Problem 1101
 */

#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

#define letter(ch) (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')

int N, Forks, Inverts;
int Register[32];
string Formula, ValueFormula;
char Map[256][256];

#define Map(i, j) Map[i + 100][j + 100]

void Readdata()
{
	#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
	#endif

	char ch, s[1024];
	gets(s);
	Formula = s;

	scanf("%d %d %d", &N, &Forks, &Inverts);

	int i, x, y;
	for (i = 0; i < Forks; i++)
		scanf("%d %d", &x, &y), Map(x, y) = 'f';

	for (i = 0; i < Inverts; i++)
		scanf("%d %d %c", &x, &y, &ch), Map(x, y) = ch;
}

int replace_string(string &source, string substr, string replace)
{
	int pos = -replace.size(), cnt = 0;

	while (1)
	{
		pos = source.find(substr, pos + replace.size());

		if (pos == -1) return cnt;
		cnt++;

		source.erase(pos, substr.size());
		source.insert(pos, replace);
	}
}

string Mid2(string source, int pos1, int pos2)
{
	int i;
	string res;

	res = "";

	for (i = pos1; i <= pos2; i++)
		if (i >= source.size()) break;
		else
			res.resize(res.size() + 1), res[i - pos1] = source[i];

	return res;
}


int Expression(string f)
{
	string subexpr, value;
	int i, j, res, k = 0;


	for (i = 0; i < f.size(); i++)
		if (f[i] == '(')
		{
			k = 1;
			for (j = i + 1; k && j <= f.size(); j++)
				if (f[j] == '(') k++;
				else
				if (f[j] == ')') k--;

			subexpr = Mid2(f, i + 1, j - 2);
			res = Expression(subexpr);
			value = res + '0';
			replace_string(f, "(" + subexpr + ")", value);
		}

	// completed evaluating subexpressions, now straight evaluation

	// NOT
		;
	replace_string(f, "!0", "1");
	replace_string(f, "!1", "0");

	// AND

	string andpart;
	res = k = -1;
	for (i = 0; i < f.size(); i++)
		if (f[i] == '&')
		{
			res &= f[i + 1] - '0', i++;
			if (i + 1 == f.size())
				andpart = Mid2(f, k, i), replace_string(f, andpart, value = res + '0');
		}
		else
		if (f[i] == '|')
		{
			andpart = Mid2(f, k, i - 1);
			replace_string(f, andpart, value = res + '0');
			res = -1;
			i -= andpart.size() - value.size();
		}
		else
		if (res == -1)
				res = f[i] - '0', k = i;

	// OR
	res = f[0] - '0';
	for (i = 1; i < f.size(); i++)
		if (f[i] == '|')
			res |= f[i + 1] - '0', i++;

	return res;
}

// updates formula with new values from registers
int Evaluate()
{
	ValueFormula = Formula;

	int i;
	string value;
	for (i = 0; i < 26; i++)
		replace_string(ValueFormula, value = 'A' + i, value = Register[i] + '0');

	return Expression(ValueFormula);
}

void Solve()
{
	replace_string(Formula, "AND", "&");
	replace_string(Formula, "OR", "|");
	replace_string(Formula, "TRUE", "1");
	replace_string(Formula, "FALSE", "0");
	replace_string(Formula, "NOT", "!");
	replace_string(Formula, " ", "");

	memset(Register, 0, sizeof(Register));

	int x, y, dx, dy;
	dx = 1; dy = 0;

	x = 0; y = 0;
	printf("%d %d\n", x, y);

	while (1)
	{
		if (Map(x, y) == 'f')
		{
			int res = Evaluate();
			if (!res)	// turn left
			{
				if (dx == 1 && dy == 0) dx = 0, dy = 1;
				else
				if (dx == 0 && dy == 1) dx = -1, dy = 0;
				else
				if (dx == -1 && dy == 0) dx = 0, dy = -1;
				else
				if (dx == 0 && dy == -1) dx = 1, dy = 0;
			} else		// turn right
			{
				if (dx == 1 && dy == 0) dx = 0, dy = -1;
				else
				if (dx == 0 && dy == 1) dx = 1, dy = 0;
				else
				if (dx == -1 && dy == 0) dx = 0, dy = 1;
				else
				if (dx == 0 && dy == -1) dx = -1, dy = 0;
			}
		} else
		if (Map(x, y) >= 'A' && Map(x, y) <= 'Z')
			Register[Map(x, y) - 'A'] = 1 - Register[Map(x, y) - 'A'];
		
		// move forward
			x += dx, y += dy;
		if (x < -N || x > N || y < -N || y > N)
			break;

		printf("%d %d\n", x, y);
	}
}

int main()
{
	Readdata();
	Solve();

	return 0;
}
