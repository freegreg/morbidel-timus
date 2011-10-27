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
bool CompareReversed;
std::vector<int> Pos;


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
	for (it = Hash.begin(); it != Hash.end(); it++)
		printf("%s\n", it->first.c_str());
	printf("-----\n");
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

bool operator < (const entry &a, const entry &b)
{
	int i;

	// compare only the first MIN characters
	if (!CompareReversed)
	{
		// left then right
		for (i = 0; i < MIN(a.left.size(), b.left.size()); i++)
			if (a.left[i] != b.left[i])
				return a.left[i] < b.left[i];
	
		for (i = 0; i < MIN(a.right.size(), b.right.size()); i++)
			if (a.right[i] != b.right[i])
				return a.right[i] < b.right[i];
	}
	else
	{
		// right then left
		for (i = 0; i < MIN(a.right.size(), b.right.size()); i++)
			if (a.right[i] != b.right[i])
				return a.right[i] < b.right[i];
		for (i = 0; i < MIN(a.left.size(), b.left.size()); i++)
			if (a.left[i] != b.left[i])
				return a.left[i] < b.left[i];
	}

	return true;
}

void Solve()
{
	// get all maximal valid addresses (go around a @ and seek for valid characters)
	Process();

	Brute();
	//return;

	int i, j;
	int cl, cr;

	// count all solutions
	Sol = 0;
	for (i = 0; i < A.size(); i++)
	{
		std::string x = A[i].left;
		std::reverse(x.begin(), x.end());
		printf("%s@%s\n", x.c_str(), A[i].right.c_str());

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

	// sort the strings (l, r)
	CompareReversed = false;
	sort(A.begin(), A.end());

	Pos.resize(A.size(), -1);
	for (i = 0; i < A.size(); i++)
	{
		// save the position of each idx so to know when sorting the second time, where was idx in the first sorting
		Pos[A[i].idx] = i;
	}

	for (i = 1; i < A.size(); i++)
	{
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
		Sol -= cl * cr;
	}
	
	// sort the strings (r, l)
	CompareReversed = true;
	sort(A.begin(), A.end());

	// TODO: check if two strings which were compared before will be compared for duplicates again
	for (i = 1; i < A.size(); i++)
	{
		// compare A[i].idx with A[i - 1].idx only if this pair was not compared before (consecutive positions in ID1)
		if (ABS(Pos[A[i].idx] - Pos[A[i - 1].idx]) == 1)
		{
			continue;
		}
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
		Sol -= cl * cr;
	}

	printf("%d\n", Sol);
}

void gen(int lim)
{
	time_t t;
	srand((unsigned) time(&t)); /*  randomize  */

	FILE *f = fopen("input.txt", "wt");
	int i;

	for (i = 0; i < lim; i++)
	{
		int r = rand() % 1000000;

		//if ((r % 199) == 0) fprintf(f, "\n");
//		else 
			if ((r % 5) == 0)
			fprintf(f, "@");
		else if ((r % 2) == 0)
			fprintf(f, "%c", 'a' + rand() % 26);
		else if ((r % 9) == 0)
			fprintf(f, ".");
	}

	fclose(f);
}


int main()
{
	//gen(500);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	N = fread(Raw, sizeof(char), INPUTSIZE, stdin);
	Raw[N++] = '|';

	Solve();

	return 0;
}
