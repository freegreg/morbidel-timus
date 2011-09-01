// ACM Online
// Permutations - Problem 1024
// afisati puterea minima la care apare e (adica 1 2 ... N)

// solutia am aflat-o de la profu' de mate accidental!:
// facem din fiecare element ciclul si facem cmmmc la toate !!!

#include <stdio.h>

int n, p[2001], flag[2001], fp[2000];
long cmmmc = 1;

void readdata()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
scanf("%d", &p[i]);
}

void primi(int num)
{
	int d, c;
	for (d = 2; num > 1; d++)
	{
		c = 0;
		while (num % d == 0)
			num /= d, c++;
		if (c > fp[d]) fp[d] = c;
	}
}

void solve()
{
	int i, k, len;
	for (i = 1; i <= n; i++)       // gaseste ciclurile din i
		if (!flag[i])
		{
			flag[i] = 1; k = i; len = 1;
			do
			{
				k = p[k];
				if (flag[k]) break;
				flag[k] = 1; len++;
			}
			while(1);
			primi(len);
		}
	for (i = 2; i <= n; i++)
		for (k = 0; k < fp[i]; k++)
			cmmmc *= i;
	printf("%ld\n", cmmmc);
}

int main()
{
	readdata();
	solve();
	return 0;
}
