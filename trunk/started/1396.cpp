/*
 *  ACM Timus Online Judge
 *  Maximum. Version 2
 */

#include <stdio.h>
#include <vector>
#include <map>

#define INPUT_FILE		"input.txt"

using namespace std;

__int64 N, Max, SolN;
map <__int64, __int64> M;




__int64 Value(__int64 n)
{
	if (M.find(n) != M.end())
		return M[n];
	else	
	{
		__int64 t1 = 0, t2 = 0;

		t1 = Value(n >> 1);

		if (n & 1)
		{
			t2 = Value((n >> 1) + 1);
		}

		return M[n] = t1 + t2;
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif

	while (scanf("%I64d", &N) == 1)
	{
		if (N == 0) break;

		M.clear();
		M[0] = 0;
		M[1] = 1;

		Max = 0;

		/*int i;
		for (i = 0; N - i >= 0 && i <= 2000; i++)
		{
			__int64 nr = Value(N - i);
			if (nr > Max)
				Max = nr, SolN = N - i;
		}*/
		printf("%I64d\n", Value(N));
		//printf("%I64d\n", Max);
	}

	return 0;
}
