#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#include <list>

#define INPUT_FILE	"input.txt"
#define	ROOT		std::string("Isenbaev")
#define EMPTY		std::string("")
#define MAXN		128
#define INF		666666

int N;
std::map<std::string, int> Sol;	// solution number for each team contestant
struct Team
{
	std::string names[3];
	bool isRoot;
} Teams[MAXN];


std::string TieTeams(int t1, int t2)
{
	int i, j;

	if (t1 == t2)
		return EMPTY;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (Teams[t1].names[i] == Teams[t2].names[j])
			{
				return Teams[t1].names[i];
			}
	return EMPTY;
}

void BF(int start_team)
{
	int i, node;
	std::string sTieMember, sName;
	std::list<int> queue;
	std::list<std::string> qMember;
	bool bContinue;

	node = start_team;
	queue.clear();
	queue.push_back(node);
	qMember.push_back(ROOT);
	Sol[ROOT] = 0;

	do
	{
		node = queue.front();
		sTieMember = qMember.front();

		queue.pop_front();
		qMember.pop_front();

		bContinue = false;
		/* we have a team. Fill rest of members of it with +1 of the sTieMember if this makes it better */
		for (i = 0; i < 3; i++)
		{
			sName = Teams[node].names[i];
			if (sName != sTieMember && Sol[sName] > Sol[sTieMember] + 1)
			{
				Sol[sName] = Sol[sTieMember] + 1;
				/* we improved it, add neighboring teams in the queue */
				bContinue = true;
			}
		}

		/* find a team which ties with current one. If we improved this team, add those to queue */
		if (bContinue)
			for (i = 0; i < N; i++)
			{
				sName = TieTeams(node, i);

				if (sName != EMPTY)
				{
					queue.push_back(i);
					qMember.push_back(sName);
				}
			}
	}
	while (queue.size() > 0);
}


int main()
{
	int i, j;
	char sz[32];


#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif
	scanf("%d\n", &N);

	Sol.clear();

	for (i = 0; i < N; i++)
	{
		Teams[i].isRoot = false;

		for (j = 0; j < 3; j++)
		{
			scanf("%s", &sz);
			Teams[i].names[j] = sz;
			Sol[sz] = INF;
			
			if (ROOT == sz)
				Teams[i].isRoot = true;
		}
	}

	/* make a BF from each root team */
	for (i = 0; i < N; i++)
		if (Teams[i].isRoot)
		{
			BF(i);
		}

	/* output results */
	std::map<std::string, int>::iterator iter;

	for (iter = Sol.begin(); iter != Sol.end(); iter ++)
	{
		printf("%s ", iter->first.c_str());
		if (iter->second == INF)
			printf("undefined\n");
		else
			printf("%d\n", iter->second);
		
	}

	return 0;
}
