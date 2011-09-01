// ACM Online
// Gentleman - Problem 1244

// solutie: încerc prin rucsac să creez diferența dintre sumă c[i] și w. Dacă sunt m m soluții -> 0

#include <stdio.h>

int n, t;
long w;
char s[100001L];
int c[100], flag[101];
int sols[100001];

void readdata()
{
	int i;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
#endif
	scanf("%ld %d", &w, &n);

	for (i = 0; i < n; i++)
  {
		scanf("%d", &c[i]);
    w -= c[i];
  }

  w *= -1;
}

void solve()
{
	int i, j;
	long max = 0;

	for (i = 0; i <= w; i++)
  {
    s[i] = -1;
    sols[i] = 0;
  }

	for (i = 0; i < n; i++)
	{
		for (j = max; j; j--)
		{
			if (s[j] == -1 || j + c[i] > w) 
        continue;

			if (j + c[i] == w && s[w] >= 0)
			{
        // 2 solutions 
        printf("-1\n");
        return;
      }

			if (s[j + c[i]] == -1)
			{
        // valoare nouă dar provenită din altă combinație. 
        sols[j + c[i]] = sols[j];
				s[j + c[i]] = i;
				if (j + c[i] > max) 
          max = j + c[i];
			}
      else
      {
        // încă o soluție
        sols[j + c[i]]++;
      }
		}

		if (s[c[i]] == -1)
		{
      // valoare nouă provenită din nimic -> 1 sol
      sols[c[i]] = 1;

			s[c[i]] = i;
			if (c[i] > max) 
        max = c[i];
		}
    else
      sols[c[i]]++;
	}

  if (sols[w] > 1)
    printf("-1\n");
  else if (s[w] == -1)
    printf("0\n"); 
  else
	{
		i = w;
		do
		{
			flag[s[i]] = 1;
			i -= c[s[i]];
		}
		while (i > 0);
    
		for (i = 0; i < n; i++)
			if (flag[i]) 
        printf("%d ", i + 1);
	}
}

int main()
{
	readdata();
	solve();

  return 0;
}

