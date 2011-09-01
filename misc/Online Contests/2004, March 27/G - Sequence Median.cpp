/*
 *  ACM Timus Online Contest 27 March 2004
 *  G - Sequence Median
 *
 *  solutie: NlogN cu N/2 memorie: tin un max-heap cu N/2 + 1 elemente. Bag in el doar elementele mai mici, si scot varful.
 */

#include <stdio.h>

#define MAXN 125100
#define INF 4294967295

long N, TN;
unsigned long H[MAXN], X, Foo;
double Sol;


/*  urca in Heap din frunze  */
void baga_mare(long pos)
{
	long tata;

	do
	{
		if (pos == 1) return;
		tata = pos / 2;
		if (H[tata] < H[pos])
			Foo = H[tata], H[tata] = H[pos], H[pos] = Foo, pos = tata;
		else break;
	}
	while (1);
}

/*  coboara din Heap din radacina */
void scoate_mare(long pos)
{
	long minpos = pos, son;

	do
	{
		son = 2 * pos;
		if (son <= N && H[son] > H[minpos])
			minpos = son;
		son = 2 * pos + 1;
		if (son <= N && H[son] > H[minpos])
			minpos = son;

		if (minpos == pos) break;
		Foo = H[pos]; H[pos] = H[minpos]; H[minpos] = Foo;
		pos = minpos;
	}
	while (1);
}

int main()
{
	long i;

 	scanf("%ld", &TN);
	N = TN / 2 + 1;

	for (i = 1; i <= TN; i++)
	{
		scanf("%ul", &X);
		if (i <= N)
			H[i] = X, baga_mare(i);
		else
		if (X < H[1])
			H[1] = X, scoate_mare(1);
	}
	Sol = H[1];
	if (TN % 2 == 0)
	{
		for (H[1] = 0, i = 2; i <= N; i++)
			if (H[i] > H[1])
				H[1] = H[i];
		Sol = (Sol + H[1]) / 2;
	}

	printf("%.1lf\n", Sol);

	return 0;
}
