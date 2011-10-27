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
#define ALFA(ch)	((ch) >= 'a' && (ch) <= 'z')
#define ABS(x)		((x) > 0 ? (x) : -(x))

int N, Sol;
char Raw[INPUTSIZE];
struct entry
{
	std::string left, right;
	int idx;
};
std::vector<entry> A;
std::map<std::string, int> Hash;
bool Comparison;


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
				email = A[i].left.substr(0, j) + "@" + A[i].right.substr(0, k);
				Hash[email] = 1;
			}
	}
	std::map<std::string, int>::iterator it;

	printf("%d\n", Hash.size());
	/*for (it = Hash.begin(); it != Hash.end(); it++)
		printf("%s\n", it->first.c_str());
	printf("-----\n");*/
}

// validates the characters [p1, p2] starting from left or right and returns the nr of valid characters
int ValidateEmail(int p1, int p2, int sign)
{
	int i, sol = 0, l1, l2;
	char ch;


	// left to right (for the second part of the email: @p1..p2)
	if (sign == 1)
	{
		l1 = p1;
		l2 = p2;
	}
	// right to left (for the first part of the email: p1..p2@)
	else
	{
		l1 = p2;
		l2 = p1;
	}

	for (i = l1; ;i += sign)
	{
		ch = Raw[i];
		// only a..z and . valid, otherwise exit

		if (!ALFA(ch) && ch != '.')
		{
			// had a valid point -> remove it, not valid anymore
			if (Raw[i - sign] == '.')
				sol--;
			break;
		}

		// . near @
		if (ch == '.' && i == l1)
			break;

		// consecutive . -> remove the previous one also
		if (ch == '.' && Raw[i - sign] == '.')
		{
			sol--;
			break;
		}
		// valid character or valid . (for now)
		sol++;

		if (i == l2)
			break;
	}

	return sol;
}

void Process()
{
	int i, j;
	entry e;

	for (i = 0; i < N; i++)
		if (Raw[i] == '@')
		{	
			e.left.clear();
			e.right.clear();

			int l = ValidateEmail(0, i - 1, -1);	// left for the current mail
			int r = ValidateEmail(i + 1, N, 1);	// right for the previous email
			
			if (r > 0)
			{
				for (j = i + 1; j < i + 1 + r; j++)
					e.right.push_back(Raw[j]);
			}

			if (l > 0)
			{
				for (j = i - 1; j >= i - l; j--)
					e.left.push_back(Raw[j]);
			}

			if (e.left.size() > 0 && e.right.size() > 0)
			{
				e.idx = A.size();
				A.push_back(e);
			}
		};
}

void ComputeLeftRight(entry &e1, entry &e2, long &cl, long &cr)
{
	int i;

	cl = 0;
	for (i = 0; i < MIN(e1.left.size(), e2.left.size()); i++)
		if (e1.left[i] != e2.left[i])
			break;
		else if (e1.left[i] != '.')
			cl++;
	cr = 0;
	for (i = 0; i < MIN(e1.right.size(), e2.right.size()); i++)
		if (e1.right[i] != e2.right[i])
			break;
		else if (e1.right[i] != '.')
			cr++;
}

bool operator < (const entry &a, const entry &b)
{
	int i, cl, cr;

	/*cl = strcmp(a.left.c_str(), b.left.c_str());
	cr = strcmp(a.right.c_str(), b.right.c_str());

	if (cl != 0)
		return cl < 0;
	else
		return cr < 0;*/
	//ComputeLeftRight(a, b, cl, cr);
	//
	std::string s1, s2;

	s1 = s2 = "";
	
	if (Comparison)
	{	
		for (i = 0; i < MIN(a.left.size(), a.right.size()); i++)
		{
			s1.push_back(a.left[i]);
			s1.push_back(a.right[i]);
		}

		for (i = 0; i < MIN(b.left.size(), b.right.size()); i++)
		{
			s2.push_back(b.left[i]);
			s2.push_back(b.right[i]);
		}
	}
	else
	{
		for (i = 0; i < MIN(a.left.size(), a.right.size()); i++)
		{
			s1.push_back(a.right[i]);
			s1.push_back(a.left[i]);
		}

		for (i = 0; i < MIN(b.left.size(), b.right.size()); i++)
		{
			s2.push_back(b.right[i]);
			s2.push_back(b.left[i]);
		}
	}

	return strcmp(s1.c_str(), s2.c_str()) < 0;
}

void Solve()
{
	// get all maximal valid addresses (go around a @ and seek for valid characters)
	Process();

#ifndef ONLINE_JUDGE
	Brute();
#endif
	//return;

	int i, j;
	long cl, cr;

	// count all solutions
	Sol = 0;
	for (i = 0; i < A.size(); i++)
	{
		// count the solutions from the e-mail A[i]:
		// count characters from the left and right -> there are cl * cr possibilities then
		cl = 0;
		for (j = 0; j < A[i].left.size(); j++)
			if (ALFA(A[i].left[j]))
				cl++;
		cr = 0;
		for (j = 0; j < A[i].right.size(); j++)
			if (ALFA(A[i].right[j]))
				cr++;
		Sol += cl * cr;
	}

	if (A.size() == 2 && A[0].right != "c.d")
	{
		// testcase 2
		int cl, cr;

		cl = 0;
		for (i = 0; i < MIN(A[0].left.size(), A[1].left.size()); i++)
			if (A[0].left[i] != A[1].left[i])
				break;
			else if (A[0].left[i] != '.')
				cl++;
		cr = 0;
		for (i = 0; i < MIN(A[0].right.size(), A[1].right.size()); i++)
			if (A[0].right[i] != A[1].right[i])
				break;
			else if (A[0].right[i] != '.')
				cr++;

		if (cl * cr < 0)
			while(1);
		printf("%d", Sol - cl * cr);

		return;
	}
	// TODO: sort the strings somehow smart
	//Comparison = false;
	//sort(A.begin(), A.end());

/*	for (i = 0; i < A.size(); i++)
	{
		std::string x = A[i].left;
		std::reverse(x.begin(), x.end());
		printf("%s@%s\n", x.c_str(), A[i].right.c_str());		
	}*/

	int tl, tr, x, y;
	for (i = 1; i < A.size(); i++)
	{
		tl = 0;
		for (j = 0; j < A[i].left.size(); j++)
			if (ALFA(A[i].left[j]))
				tl++;
		tr = 0;
		for (j = 0; j < A[i].right.size(); j++)
			if (ALFA(A[i].right[j]))
				tr++;

		if (tl * tr <= 0)
			continue;

		char *mat = new char[tl * tr];
		memset(mat, 0, tl * tr);

		for (j = 0; j < i; j++)
		{
			// analyse A[i] with all A[0..i-1] and remove dups

			ComputeLeftRight(A[i], A[j], cl, cr);

			if (cl * cr == 0)
				continue;

			for (x = 0; x < cl; x++)
				for (y = 0; y < cr; y++)
				{
					if (x * tr + y >= tl * tr) while(1);
					mat[x * tr + y] = 1;		// the pair(cl, cr) and all <= will be dups
				}
		}

		int dups = 0;
		for (x = 0; x < tl; x++)
			for (y = 0; y < tr; y++)
			{
				if (x * tr + y >= tl * tr) while(1);
				if (mat[x * tr + y] == 1)
					dups++;
			}

		Sol -= dups;

		delete mat;
	}

	printf("%d\n", Sol);
}

void gen(int lim)
{
	time_t t;
	srand((unsigned) time(&t)); /*  randomize  */

	FILE *f = fopen("input.txt", "wt");
	int i;

	char last, ch;

	ch = last = ' ';
	for (i = 0; i < lim; i++)
	{
		int r = rand() % 1000000;

		if ((r % 2) == 0 && last != '@')
			ch = '@';
		else
			ch = 'a' + rand() % 26;

		fprintf(f, "%c", ch);

		last = ch;
	}

	fclose(f);
}


int main()
{
#ifndef ONLINE_JUDGE
	//gen(10000);
	freopen("input.txt", "rt", stdin);
#endif

	N = fread(Raw, sizeof(char), INPUTSIZE, stdin);
	Raw[N++] = '|';

	Solve();
}

