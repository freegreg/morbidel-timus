/*
 * ACM Timus Online
 * Anindilyakwa - Problem 1777
 *
 * solution: simulation
 */

#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>

std::list<long long> L;


int main()
{
	std::vector<long long> v;
	long long x1, x2, x3;

	scanf("%lld %lld %lld", &x1, &x2, &x3);

	v.push_back(x1);
	v.push_back(x2);
	v.push_back(x3);

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		L.push_back(v[i]);

	/* now we have the elements in ascending order. The minimal difference should be between two consecutive values */
	while (true)
	{
		long long min = -1;
		std::list<long long>::iterator now, next;

		for (now = L.begin(); now != L.end(); now++)
		{
			next = now;
			next++;
			if (next != L.end())
			{
				if (min == -1 || (*next - *now < min))
					min = *next - *now;
			}
		}

		if (min == 0)
			break;

		/* insert min in the list so it remains sorted */
		for (now = L.begin(); now != L.end(); now++)
			if (*now > min)
			{
				L.insert(now, min);
				break;
			}
/*		for (now = L.begin(); now != L.end(); now++)
			printf("%lld ", *now);
		printf("\n");*/
	}

	printf("%d\n", L.size() - 2);

	return 0;
}

