/*
 *  ACM Online
 *  Legendary teams contest - Problem 1208
 */

#include <stdio.h>
#include <string.h>

#define MAXN 32

int NG, N, Good, S[MAXN], Best = 0;
struct team
{
	int p1, p2, p3;
} t[MAXN];
char olds[64][32];
int A[MAXN][MAXN], Flag[MAXN];


int getindex(char *cuv)
{
	for (int i = 1; i <= N; i++)
		if (!strcmp(cuv, olds[i])) return i;

	memcpy(olds[++N], cuv, 40);
	return N;
}

void readdata()
{
	int i;
	char s1[40], s2[40], s3[40];

	//freopen("file.in", "r", stdin);
	scanf("%d", &NG);
	for (i = 1; i <= NG; i++)
	{
		scanf("%s %s %s", &s1, &s2, &s3);
		t[i].p1 = getindex(s1);
		t[i].p2 = getindex(s2);
		t[i].p3 = getindex(s3);
	}
}

/*  generam toate C(NG, x) si le verificam  */
void back(int lev, int x)
{
	int i, j;

	if (lev == x)
	{
		/*  verificam daca e subgraf  */
		for (i = 0; i < x; i++)
			for (j = i + 1; j < x; j++)
				if (!A[S[i]][S[j]])
					return;
		Good = 1;
		return;
	} else
	for (i = S[lev ? lev - 1 : 0] + 1; !Good && i <= NG; i++)
		if (!Flag[i])
		{
			S[lev] = Flag[i] = i;
			back(lev + 1, x);
			S[lev] = Flag[i] = 0;
		}
}

void solve()
{
	int i, j, dim;

	/*  build graph  */
	for (i = 1; i <= NG; i++)
		for (j = i + 1; j <= NG; j++)
		{
			if (t[i].p1 == t[j].p1 || t[i].p1 == t[j].p2 || t[i].p1 == t[j].p3) 
				A[i][j] = A[j][i] = 0;
			else
			if (t[i].p2 == t[j].p1 || t[i].p2 == t[j].p2 || t[i].p2 == t[j].p3) 
				A[i][j] = A[j][i] = 0;
			else
			if (t[i].p3 == t[j].p1 || t[i].p3 == t[j].p2 || t[i].p3 == t[j].p3) 
				A[i][j] = A[j][i] = 0;
			else
				A[i][j] = A[j][i] = 1;
		}

	/*  caut binar un subgraf complet de ordin dim  */
	
	for (i = 1, j = NG; i <= j; i = (Good ? dim + 1 : i), j = (Good ? j : dim - 1))
	{
		dim = (i + j) / 2;
		back(Good = 0, dim);
		if (Good && dim > Best)
			Best = dim;
	}

	printf("%d\n", Best);
}

int main()
{
	readdata();
	solve();

	return 0;
}
