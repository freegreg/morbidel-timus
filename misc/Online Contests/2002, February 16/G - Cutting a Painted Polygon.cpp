// ACM Online
// Cutting a painted polygon - Problem 1181

// solutie: tinem aparitiile si taiem caciulile (RGB consecutive) dar sa
// dispara un varf care apare mai des (?)
// nu-i solutie cand doua vf. au aceeasi culoare sau cand lipeste o culoare

#include <stdio.h>

int n, flag[100], num[1000];
char v[1001];

char p(int poz)
{
	if (poz < 0) return v[poz + n];
	return v[poz % n];
}
char next()
{
	char max;
	max = flag['B'] > flag['G'] ? 'B' : 'G';
	max = flag[max] > flag['R'] ? max : 'R';
	return max;
}
int colt(int poz, char mid)
{
	char p1, p2;
	switch(mid)
	{
		case 'R': p1 = 'G'; p2 = 'B'; break;
		case 'G': p1 = 'B'; p2 = 'R'; break;
		case 'B': p1 = 'R'; p2 = 'G'; break;
	}
	if (p(poz - 1) == p1 && p(poz + 1) == p2) return 1;
	if (p(poz - 1) == p2 && p(poz + 1) == p1) return 1;
	return 0;
}
void readdata()
{
	scanf("%d %s", &n, &v);
}
void scoate(int poz)
{
	int i;
	for (i = poz; i < n - 1; i++)
		num[i] = num[i + 1], v[i] = v[i + 1];
	num[i] = v[i] = 0;
}
void solve()
{
	int i;
	char c;
	for (i = 0; i < n; i++) num[i] = i, flag[v[i]]++;
	for (i = 0; i < n; i++)
		if (p(i) == p(i + 1) || !flag['R'] || !flag['G'] || !flag['B'])
		{
			printf("0");
			return;
		}
	printf("%d\n", n - 3);        // n - 3 diagonale
	i = 0;
	do
	{
		c = next();
		if (i == n)             // cand sunt toate egale si nu merge
			c = c == 'G' ? 'R' : 'G';
		num[-1] = num[n - 1];
		for (i = 0; i < n; i++)       // cauta c†ciuli cu c la mijloc
			if (p(i) == c && colt(i, c))
			{
				printf("%d %d\n", num[i - 1] + 1, num[i + 1] + 1);
				flag[c]--;
				scoate(i); n--; i = 0;
				break;
			}
	}
	while (flag[next()] > 1 || n > 3);
}
void main()
{
	readdata();
	solve();
}