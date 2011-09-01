/*
 *  ACM Timus Online
 *  Astronomical database - Problem 1414
 *
 *  arbore de litere, prefixe
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <list>

#define INPUT	"input.txt"

using namespace std;

struct node
{
	bool			bFinalLetter;													// pentru cuvinte incluse in altele
	ustring			sCuv;
	list<node*>		lstFii;
} *Root;

int nSol = 20;



void add(node *nod, string cuv)
{
	list<node*>::iterator it;

	if (!nod || cuv.size() == 0)
		return;

	bool bGasit = false;
	node *fiu = NULL;

	for (it = nod->lstFii.begin(); it != nod->lstFii.end(); it++)
	{
		fiu = *it;

		if (!fiu) continue;

		if (fiu->szChar == cuv[0])
		{
			bGasit = true;
			break;
		}
	}

	if (!bGasit)
	{
		// il adaug in lista tatalui cat sa o pastrez sortata lexicografic

		node *pNew = new node;

		pNew->lstFii.clear();
		pNew->szChar = cuv[0];
		pNew->bFinalLetter = cuv.size() == 1;

		fiu = pNew;

		bool bagat = false;

		for (it = nod->lstFii.begin(); it != nod->lstFii.end(); it++)
		{
			if ((*it)->szChar > cuv[0])
			{
				bagat = true;
				nod->lstFii.insert(it, pNew);
				break;
			}
		}

		if (!bagat)
		{
			nod->lstFii.push_back(pNew);
		}
	} else
	if (bGasit && cuv.size() == 1)										// cuvant inclus in unul deja existent, bifam ca am terminator aici
	{
		fiu->bFinalLetter = true;
	}

	// sterg prima litera
	cuv = cuv.erase(0, 1);

	// si cobor
	add(fiu, cuv);
}

void inordine(node *nod, string sPrefix, string sSufix)
{
	if (nSol == 0)
		return;

	if (nod->lstFii.size() == 0 || nod->bFinalLetter == true)				// frunza
	{
		nSol--;
		string sol = sPrefix + sSufix;
		printf("  %s\n", sol.c_str());
	}

	if (nod->lstFii.size() > 0)
	{
		list<node*>::iterator it;

		for (it = nod->lstFii.begin(); it != nod->lstFii.end(); it++)
		{
			node *fiu = *it;

			sSufix += fiu->szChar;
			inordine(fiu, sPrefix, sSufix);
			sSufix.erase(sSufix.size() - 1, 1);
		}
	}
}

void Query(string cuv)
{
	int i;
	bool bGasit = false;
	node *nod = Root, *fiu = NULL;


	printf("%s\n", cuv.c_str());

	// caut nodul cu prefixul cuv
	for (i = 0; i < cuv.size(); i++)
	{
		list<node*>::iterator it;

		bGasit = false;
		for (it = nod->lstFii.begin(); it != nod->lstFii.end(); it++)
		{
			fiu = *it;

			if (!fiu) continue;

			if (fiu->szChar == cuv[i])
			{
				bGasit = true;
				break;
			}
		}

		if (!bGasit)
		{
			fiu = NULL;
			break;
		}
		nod = fiu;
	}

	// am in fiu nodul tata al tuturor cuvintelor cu prefixul cuv din dictionar; parcurg in adancime din el si-n frunze afisez solutia

	if (!fiu)
		return;

	nSol = 20;
	string sol = "";
	inordine(fiu, cuv, sol);
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen(INPUT, "r", stdin);
	#endif


	char line[32];
	char word[32];

	Root = new node;
	Root->szChar = '*';
	Root->bFinalLetter = false;
	Root->lstFii.clear();

	add(Root, "sun");


	while (scanf("%s", &line) == 1)
	{
		strcpy(word, line + 1);

		string sWord = word;

		if (line[0] == '+')
		{
			// add
			add(Root, sWord);
		}
		else
		if (line[0] == '?')
		{
			// query
			Query(sWord);
		}
	}

	return 0;
}
