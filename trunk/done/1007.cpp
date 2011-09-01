// ACM Online
// Code Words - Problem 1007

// solutie: vedem ce operatie trebuie facuta si o facem pt. fiecare element...

#include <stdio.h>
#include <string.h>

char s[2010];
long p[4010], n, len, nr1, c[4050], newc[4050], num[4020];


long suma(int a, int b) // suma poz lui 1 intre [a, b]
{
	return (a > b) ? 0 : p[b + 1] - p[a];
}

int num1(int a, int b) // numarul de 1 din [a, b]
{
	return (a > b) ? 0 : num[b + 1] - num[a];
}

void solve()
{
	long i, poz, what, ss, sr, sl, r1, l1;

	nr1 = 0; poz = 0;
	memset(p, 0, sizeof(p));
	memset(num, 0, sizeof(num));
	for (i = 1; i <= len + 1; i++)
	{
		if (c[i]) nr1++;
		p[i] = c[i - 1] ? i - 1 + p[i - 1] : p[i - 1];
		num[i] = c[i - 1] ? num[i - 1] + 1 : num[i - 1];
	}
	if (len == n - 1)        // e mai mic deci adaugam un 0 sau 1
	{
		for (i = 1; i <= n; i++)
		{
			sl = suma(1, i - 1); sr = suma(i, len);
			r1 = num1(i, len); sr += r1;
			if ((sl + sr) % (n + 1) == 0)
			{
				poz = i; what = 0;
				break;
			}
			sr += i;
			if ((sl + sr) % (n + 1) == 0)
			{
				poz = i; what = 1;
				break;
			}
		}
		for (i = 1; i < poz; i++) 
			newc[i] = c[i];
		newc[poz] = what;
		for (i = poz; i <= len; i++) 
			newc[i + 1] = c[i];
	} else
	if (len == n)     // e egal deci inlocuim un 1 cu un 0
	{
		memcpy(newc, c, sizeof(c));
		ss = suma(1, n);
		if (ss % (n + 1))
		{
			for (i = 1; i <= len; i++)
				if (newc[i])
				{
					newc[i] = 0; ss -= i;
					if (ss % (n + 1) == 0)
					{ poz = 1; break;}
					ss += i; newc[i] = 1;
				}
		} else poz = 1;
	} else
	if (len == n + 1)        // e mai mare deci stergem un 0 sau 1
	{
		for (i = 1; i <= len; i++)
		{
			sl = suma(1, i - 1); sr = suma(i + 1, len);
			r1 = num1(i + 1, len);
			sr -= r1;
			if ((sl + sr) % (n + 1) == 0)
			{
				poz = i;
				break;
			}
		}
		for (i = 1; i < poz; i++) newc[i] = c[i];
		for (i = poz + 1; i <= len; i++) newc[i - 1] = c[i];
	}
	if (!poz)
	{
		printf("No solution!\n");
		return;
	}
	for (i = 1; i <= n; i++)
		printf("%ld", newc[i]);
	printf("\n");
}

int main()
{
	int i, j;

	scanf("%ld\n", &n);
	while (scanf("%s", &s) == 1)
	{
		memset(c, 0, sizeof(c));
		len = 0;
		while (1)
		{
			c[++len] = s[len - 1] - 48;
			if (len == strlen(s)) break;
		}
		solve();
	}
	return 0;
}
