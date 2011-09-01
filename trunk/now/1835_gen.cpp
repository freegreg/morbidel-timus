/*
 * ACM Timus Online
 * Swamp Doctor - Problem 1835
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <ctime>

#define INPUTSIZE	1100000
#define MIN(a, b)	((a) > (b) ? (b) : (a))

int N, Sol;
char Raw[INPUTSIZE];
struct entry
{
	std::string left, right;
};
std::vector<entry> A;
std::map<std::string, int> Hash;


void Brute()
{
	int i, j, k;


	for (i = 0; i < A.size(); i++)
	{
		std::string email = "";

		for (j = 1; j <= A[i].left.size(); j++)
			for (k = 1; k <= A[i].right.size(); k++)
			{
				if (A[i].left[j - 1] == '.' || A[i].right[k - 1] == '.')
					continue;
				email = A[i].left.substr(0, j); 
				std::reverse(email.begin(), email.end());
				email += "@" + A[i].right.substr(0, k);
				Hash[email] = 1;
			}
	}
	std::map<std::string, int>::iterator it;

	printf("%d\n", Hash.size());
	/*for (it = Hash.begin(); it != Hash.end(); it++)
		printf("%s\n", it->first.c_str());*/
}

void Process()
{
	int i;

	for (i = 0; i < N; i++)
		if (Raw[i] == '@')
		{
			entry e;
			e.left.clear();
			e.right.clear();

			// go to the left (get the string reversed to easily compare it)
			int l = i - 1;
			
			while (l >= 0)
			{
				char ch = Raw[l];

				if (!(ch >= 'a' && ch <= 'z') && ch != '.')
				{
					if (e.left.size() > 0 && e.left[e.left.size() - 1] == '.')
						e.left.erase(e.left.size() - 1, 1);
					break;
				}

				if (ch >= 'a' && ch <= 'z')
					e.left = e.left + ch;
				else if (ch == '.')
				{
					// '.' near the @
					if (e.left.size() == 0)
						break;
					// consecutive '.'
					else if (e.left[0] == '.')
					{
						// delete also the previous .
						e.left.erase(0, 1);
						break;
					}
					else
						e.left = e.left + ch;
				}
				l--;
			}

			// go to the right
			int r = i + 1;
			
			while (r < N)
			{
				char ch = Raw[r];

				if (!(ch >= 'a' && ch <= 'z') && ch != '.')
				{
					if (e.right.size() > 0 && e.right[e.right.size() - 1] == '.')
						e.right.erase(e.right.size() - 1, 1);
					break;
				}

				if (ch >= 'a' && ch <= 'z')
					e.right = e.right + ch;
				else if (ch == '.')
				{
					// '.' near the @
					if (e.right.size() == 0)
						break;
					// consecutive '.'
					else if (e.right[e.right.size() - 1] == '.')
					{
						// delete also the previous .
						e.right.erase(e.right.size() - 1, 1);
						break;
					}
					else
						e.right = e.right + ch;
				}
				r++;
			}

			if (e.left.size() > 0 && e.right.size() > 0)
			{
				// valid email
				A.push_back(e);
				//printf("email found: %s@%s\n", e.left.c_str(), e.right.c_str());
			}
		};
}

bool operator < (const entry &a, const entry &b)
{
	int c1 = strcmp(a.left.c_str(), b.left.c_str());

	if (c1 != 0)
		return c1 < 0;

	int c2 = strcmp(a.right.c_str(), b.right.c_str());
	
	return c2 < 0;
}

void Solve()
{
	// get all maximal valid addresses (go around a @ and seek for valid characters)
	Process();

	//Brute();
	//return;

	// sort the strings
	sort(A.begin(), A.end());

	int i, j;

	Sol = 0;
	for (i = 0; i < A.size(); i++)
	{
		int cnt, cl, cr;

		// count the solutions from the e-mail A[i]:
		// count characters from the left and right -> there are cl * cr possibilities then
		cl = 0;
		for (j = 0; j < A[i].left.size(); j++)
			if (A[i].left[j] >= 'a' && A[i].left[j] <= 'z')
				cl++;
		cr = 0;
		for (j = 0; j < A[i].right.size(); j++)
			if (A[i].right[j] >= 'a' && A[i].right[j] <= 'z')
				cr++;
		cnt = cl * cr;

		if (i > 0)
		{
			// now we should subtract the common ones with the email beside (because we sorted and reversed the email, this should be enough)
			cl = 0;
			for (j = 0; j < MIN(A[i - 1].left.size(), A[i].left.size()); j++)
				if (A[i - 1].left[j] != A[i].left[j])
					break;
				else if (A[i].left[j] != '.')
					cl++;
			cr = 0;
			for (j = 0; j < MIN(A[i - 1].right.size(), A[i].right.size()); j++)
				if (A[i - 1].right[j] != A[i].right[j])
					break;
				else if (A[i].right[j] != '.')
					cr++;

			cnt -= cl * cr;
		}

		Sol += cnt;
	}


	printf("%d\n", Sol);

	//for (i = 0; i < A.size(); i++) printf("%s@%s\n", A[i].left.c_str(), A[i].right.c_str());
}


void gen()
{
	time_t t;
	srand((unsigned) time(&t)); /*  randomize  */

	FILE *f = fopen("input.txt", "wt");
	int i, lim = 100000;

	for (i = 0; i < lim; i++)
	{
		if (rand
	}

	fclose(f);
}

int main()
{
	gen();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	N = fread(Raw, sizeof(char), INPUTSIZE, stdin);

	Solve();

	return 0;
}
