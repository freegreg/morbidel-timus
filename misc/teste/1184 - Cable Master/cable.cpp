/*
 *  ACM Timus Online
 *  Cable Master - Problem 1184
 * 
 *  solutie: caut binar lungimea maxima si compar suma [ni/x] cu K
 */


#include <stdio.h>

#define input "cable.in"
#define output "cable.out"
#define MAXN 10010

FILE *f;
long N, K;
long double V[MAXN], Len = 0;


void readdata()
{
	long i; 

	f = fopen(input, "r");

	fscanf(f, "%ld %ld", &N, &K);
	for (i = 0; i < N; i++)
		fscanf(f, "%Lf", &V[i]);

	fclose(f);
}

long rez(long double len)
{
	long i, sum = 0;

	len = (long)(len * 100); 
	len /= 100;

	for (i = 0; i < N; i++)
		sum += (long)(V[i] / len);

	return sum;
}

void solve()
{
	long ss;
	long double l, r, m;

	l = 0.01; r = 100000.01;

	do
	{
		ss = rez(m = (l + r) / 2);
		
		if (ss < K) 
			r = m;
		else 
		if (ss >= K)
			Len = m, l = m + 0.0001; /*  rafinarea solutiei  */
		if ((r - l) < 0.0001) break;
	}
	while (l <= r);

	Len = (long) (Len * 100); 
	Len /= 100;

	f = fopen(output, "w");
	fprintf(f, "%.2Lf\n", Len);
	fclose(f);
}

int main()
{

	readdata();
	solve();

	return 0;
}
