// ACM Online
// Parity - Problem 1003

#include <stdio.h>
#include <stdlib.h>

struct set
{
	long l, r, s;
	set *next;
} *p;
long n, nq;
struct interval
{
	long a, b, par;
} ii[5000];

int main()
{
	long i, a, b, oa, solu;
	char par[20], s;
	set *c, *m;

	do
	{
		scanf("%ld %ld", &n, &nq);
		if (n == -1) break;

		for (solu = i = 0; i < nq; i++)
		{	
			scanf("%ld %ld %s", &a, &b, &par); // 0 even, 1 odd
			ii[i].par = (par[0] == 'e') ? 0 : 1;
			ii[i].a = a; ii[i].b = b;
		}
		c = (set*) malloc(sizeof(*c));
		c -> l = 0; c -> r = 2000000000L; c -> s = -1; c -> next = 0;
		p = c;

		for (i = 0; i < nq; i++)
		{
			if (solu) break;
			a = ii[i].a; b = ii[i].b; s = ii[i].par;
			for (c = p; c; c = c -> next)
			{
				if (c -> next && b > c -> next -> r || !c -> next) // il bagam aici
				{
					m = (set*) malloc(sizeof(*m));
					m -> l = a; m -> r = b; m -> s = s; m -> next = c -> next;
					c -> next = m; c = c -> next;
					break;
				} else
				if (c -> next -> r == b)
				{
					if (c -> next -> l == a && c -> next -> s != s)
					{ 
						solu = i; 
						break; 
					} else
					{
						s = (c -> next -> s + s) % 2; oa = a;
						if (c -> next -> l > a) 
							b = c -> next -> l - 1;
						if (c -> next -> l < a) 
							a = c -> next -> l, b = oa - 1;
					}
				}
			}
		}
		if (!solu) solu = nq;
		printf("%ld\n", solu);

		free(c); free(p); free(m);
		for (i = solu; i < nq; i++)
			scanf("\n");
		c = p = m = NULL;
	} while (1);

	return 0;
}
