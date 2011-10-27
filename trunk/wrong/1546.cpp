/*
 *  ACM Timus Online
 *  Japanese Sorting - Problem 1546
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

#define INPUT	"input.txt"
#define OUTPUT	"output.txt"
#define LETTER(ch) (ch >= 'a' && ch <= 'z')
#define NUMBER(ch) (ch >= '0' && ch <= '9')

using namespace std;
char Sz[200001];
struct foobarbaz
{
	string szOriginal;
	string szModified;
	vector<int> poz, nr;
};
int N;
vector<foobarbaz> V;
vector<int> VMax;


void ReadData()
{
	#ifndef ONLINE_JUDGE
	freopen(INPUT, "r", stdin);
	#endif

	while (gets(Sz))
	{
		foobarbaz x;
		x.szOriginal = x.szModified = Sz;
		if (x.szModified.size() > 0 && NUMBER(x.szModified[0]))
		  {
			x.szModified = string("a") + x.szModified;
		  }

		V.push_back(x);
	}
}

bool operator < (const foobarbaz &a, const foobarbaz &b)
{
	if (a.szModified == b.szModified)
		return a.szOriginal < b.szOriginal;
	else
		return a.szModified < b.szModified;
}

void Solve()
{
	#ifndef ONLINE_JUDGE
	//freopen(OUTPUT, "w", stdout);
	#endif


	int i, j, k, max_col = 0;

	N = V.size();

	// compute maximum for each group of letters and digits
	for (i = 0; i < N; i++)
	{
		if (V[i].szModified.size() == 0)
			continue;

		bool bNum;
		bNum = NUMBER(V[i].szModified[0]);

		int cnt = 1, flip = 0;
		if (bNum)					// if first numeric, simulate a small char group
		{
			V[i].nr.push_back(0);
			flip = 1;
		}

		for (j = 1; j <= V[i].szModified.size(); j++)
		{
			char ch = (j < V[i].szModified.size()) ? V[i].szModified[j] : '-';

			if ((LETTER(ch) && !bNum) || (NUMBER(ch) && bNum))
				cnt++;
			else
			{
				flip++;
				bNum = !bNum;
				V[i].nr.push_back(cnt);

				cnt = 1;
			}
		}
		if (V[i].nr.size() > max_col)
		{
			max_col = V[i].nr.size();
		}
	}

	VMax.resize(max_col, 0);
	for (i = 0; i < N; i++)
	{
		for (j = max_col - V[i].nr.size(); j > 0; j--)
		{
			V[i].nr.push_back(0);
		};

		for (j = 0; j < max_col; j++)
			if (V[i].nr[j] > VMax[j])
			{
				VMax[j] = V[i].nr[j];
			};

		V[i].poz.resize(max_col, 0);
		V[i].poz[0] = 0;
		for (j = 1; j < max_col; j++)
		{
			V[i].poz[j] = V[i].poz[j - 1] + V[i].nr[j - 1];
		};
	}

	// convert all words to new format (add extra 'a' and '0' for each group till it reaches maximum length for each group)
	for (i = 0; i < N; i++)
	{
		for (j = V[i].nr.size() - 1; j >= 0; j--)
			for (k = 0; k < VMax[j] - V[i].nr[j]; k++)
			{
				// if number, put zeros before because we compare as a whole
				if (j & 1)
				{
					V[i].szModified.insert(V[i].poz[j], "0");
				}
				else
				// if letter, put 'a' behind because the comparison begins with first chars
				{
					if (j != V[i].nr.size() - 1)
						V[i].szModified.insert(V[i].poz[j + 1], "a");
					else
						V[i].szModified.insert(V[i].poz[j], "a");
				}
			};
	}

	sort(V.begin(), V.end());

	for (i = 0; i < V.size(); i++)
		printf("%s\n", V[i].szOriginal.c_str());
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
