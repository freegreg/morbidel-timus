/*
 *  ACM Timus
 *  A. Awakening
 */

#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
struct object
{
	string name;
	vector<string> ob;		// obiectele
};
vector<object> Obj;
vector<string> Query;


// rez = v1 inters v2
// v1 and v2 are sorted so do something like a merge
void Intersect(vector<string> &v1, vector<string> &v2, vector<string> &rez)
{
	int i, j;

	rez.clear();
	if (v1.size() == 0 || v2.size() == 0)
		return;

	i = j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] == v2[j])
		{
			rez.push_back(v1[i]);

			i++;
			j++;
		} else
		if (v1[i] > v2[j])
		{
			j++;	
		} else
		if (v1[i] < v2[j])
		{
			i++;
		}
	}
}

int Search(string sName)
{
	int l, r;

	l = 0;
	r = N - 1;

	while (l <= r)
	{
		int m = (l + r + 1) / 2;
		if (Obj[m].name == sName)
			return m;
		else
		if (Obj[m].name < sName)
			l = m;
		else
			r = m - 1;
	}

	return -1;
}

void printv(vector<string> &v)
{
	int i;

	for (i = 0; i < v.size(); i++)
		printf("%s ", v[i].c_str());
	printf("\n");
}

void Solve()
{
	// now intersect each of the query's objects
	int i;
	vector<string> inters, inters2;

	if (Query.size() == 0)
	{
		printf("No solution.\n");
		return;
	} else
	if (Query.size() == 1)
	{
		int s = Search(Query[0]);
		printv(Obj[s].ob);
		return;
	} else
	{
		int i1, i2;

		i1 = Search(Query[0]);
		i2 = Search(Query[1]);
		Intersect(Obj[i1].ob, Obj[i2].ob, inters);

		if (inters.size() == 0)
		{
			printf("No solution.\n");
			return;
		}

		for (i = 2; i < Query.size(); i++)
		{
			i2 = Search(Query[i]);
			Intersect(inters, Obj[i2].ob, inters2);
			inters = inters2;
			if (inters.size() == 0)
			{
				printf("No solution.\n");
				return;
			}
		}

		printv(inters);
	}
}

bool operator < (const object &a, const object &b)
{
	return strcmp(a.name.c_str(), b.name.c_str()) < 0;
}

int main()
{
	int i, pos;
	char sz[1024];
	string s, w;

	freopen("input.txt", "rt", stdin);	
	scanf("%d\n", &N);

	Obj.resize(N);
	for (i = 0; i < N; i++)
	{
		gets(sz);
		s = sz;
		pos = s.find_first_of(':', 0);
		Obj[i].name = s.substr(0, pos);
		s.erase(0, pos + 2);

		while ((pos = s.find_first_of(' ', 0)) >= 0)
		{
			w = s.substr(0, pos);
			Obj[i].ob.push_back(w);
			s.erase(0, pos + 1);
		}
		if (s.size() > 0)
		{
			Obj[i].ob.push_back(s);
		}

		sort(Obj[i].ob.begin(), Obj[i].ob.end());
	}

	sort(Obj.begin(), Obj.end());

	scanf("%d\n", &M);
	for (i = 0; i < M; i++)
	{
		gets(sz);
		s = sz;
		Query.clear();

		while ((pos = s.find_first_of(' ', 0)) >= 0)
		{
			w = s.substr(0, pos);
			Query.push_back(w);
			s.erase(0, pos + 1);
		}
		if (s.size() > 0)
		{
			Query.push_back(s);
		}

		Solve();
	}

	return 0;
}
