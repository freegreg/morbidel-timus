/*
 *  ACM Timus Online
 *  Country of Fools - Problem 1604
 */

#include <stdio.h>
#include <list>

#define input "input.txt"

using namespace std;



int N;
list<pair<int, int> > lstCount;
list<int> lstRes;


void ReadData()
{
	int i, x;

	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);
		pair<int, int> p;
		p.first = x;
		p.second = i + 1;
		lstCount.push_back(p);
	}
}

void Solve()
{
	list<int>::iterator it;


	lstCount.sort();

	while (lstCount.size() > 0)
	{
		pair<int, int> d1, d2;

		if (lstCount.size() == 1)
		{
			d1 = lstCount.front();
			
			if (lstRes.size() == 0)
			{
				// lista goala
				for (; d1.first; d1.first--)
					lstRes.insert(lstRes.begin(), d1.second);
			}
			else
			{
				int last = -1;
				// baga intre randuri
				for (it = lstRes.begin(); d1.first && it != lstRes.end(); it++)
				{
					if (it == lstRes.begin() && d1.second != *it)
					{
						lstRes.insert(it, d1.second);
						d1.first--;
					}
					else
					if (it != lstRes.begin() && d1.second != *it && d1.second != last)
					{
						lstRes.insert(it, d1.second);
						d1.first--;
					}

					last = *it;
				}

				// am bagat cat sa nu fie conflicte, daca au mai ramas ii pun pleasca la inceput sau la sfarsit

				if (lstRes.front() == d1.second)
				{
					for (; d1.first; d1.first--)
						lstRes.insert(lstRes.end(), d1.second);
				} else
				{
					for (; d1.first; d1.first--)
						lstRes.insert(lstRes.begin(), d1.second);
				}
			}
			
			break;
		}

		d1 = lstCount.front();
		lstCount.pop_front();

		d2 = lstCount.front();
		lstCount.pop_front();

		int i;
		pair<int, int> p;

		// pun perechi 2 cate 2, alternativ, ca sa nu incep cu cea cu care am terminat anterior
		int last = lstRes.size() > 0 ? lstRes.back() : -1;
		for (i = 0; i < d1.first; i++)
		{
			if (d1.second != last)
			{
				lstRes.push_back(d1.second);
				lstRes.push_back(d2.second);
			} else
			{
				lstRes.push_back(d2.second);
				lstRes.push_back(d1.second);
			}
		}

		bool bSort = false;
		if (abs(d1.first - d2.first) > 0)
		{
			if (d1.first > d2.first)
			{
				p.second = d1.second;
			} else
				p.second = d2.second;

			p.first = abs(d1.first - d2.first);

			// insert item at correct position so sorting remains ok
			list<pair<int, int> >::iterator it2;
			for (it2 = lstCount.begin(); it2 != lstCount.end(); it2++)
			{
				pair<int, int> pp = *it2;

				if (pp.first > p.first)
					break;
			}
			lstCount.insert(it2, p);
		}
	}

	for (it = lstRes.begin(); it != lstRes.end(); it++)
		printf("%d ", (*it));
	printf("\n");
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
