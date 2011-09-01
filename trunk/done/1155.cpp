/*
 *  ACM Online
 *  Troubleduons - Problem 1155
 *
 *  solutie: elimin†m toate cele adiacente si restu' vor fi doar pe diagonale
 *  si crestem laturile comune cu valorile respective... m† rog, Œntelegi tu.
 *  Œn final va r†mƒne un singur num†r. Dac† e 0 se poate, altfel nu.
 *  (o burbelie...)
 */

#include <stdio.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int s[10], mv = 0;
char alfa[10] = {'', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
struct edge
{
	int n1, n2;
} ed[12] = {{1, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}, {3, 4},
			{3, 7}, {4, 8}, {5, 6}, {5, 8}, {6, 7}, {7, 8}};
struct move
{
	int n1, n2, what;
} sol[1500];


void readdata()
{
	int i;
	for (i = 1; i <= 8; scanf("%d", s + i++));
}

void go(int n1, int n2, int how)
{
	sol[mv].n1 = n1; sol[mv].n2 = n2; sol[mv++].what = how;
	if (how) s[n1]++, s[n2]++;
	else s[n1]--, s[n2]--;
}

void eliminate()
{
	int i, j, nc, mi;
	do
	{
		for (nc = i = 0; i < 12; i++)
			if (s[ed[i].n1] && s[ed[i].n2])
			{
				mi = min(s[ed[i].n1], s[ed[i].n2]);
				for (nc = 1, j = 0; j < mi; j++)
					go(ed[i].n1, ed[i].n2, 0);
			}
	}
	while (nc);
}

int good()
{
	int i, nc = 0;
	for (i = 1; i <= 8; i++)
		if (s[i]) nc++;
	return (nc < 2);
}

void big_diag(int n1, int n2, int c1, int c2)
{
	int i, mi = min(s[n1], s[n2]);;
	if (s[n1] && s[n2])
		for (i = 0; i < mi; i++)
			go(c1, c2, 1), go(n1, c2, 0), go(n2, c1, 0);
}

void short_diag(int n1, int n2)
{
	int i, mi = s[n1];
	if (s[n1] && s[n2])
		for (i = 0; i < mi; i++)
			go(n1 + 4, n2, 1), go(n1 + 4, n1, 0);
}

void same_diag(int n1, int n2)
{
	int i, mi = min(s[n1], s[n2]);
	if (s[n1] && s[n2])
		for (i = 0; i < mi; i++)
			go(n1, n2 - 1, 1), go(n2 - 1, n2, 0);
}

void solve()
{
	int i, nos = 0;

	eliminate();
	do
	{
		big_diag(1, 7, 3, 2); big_diag(2, 8, 4, 1);
		big_diag(3, 5, 1, 4); big_diag(4, 6, 2, 3);
		short_diag(1, 6); short_diag(1, 8);
		short_diag(2, 5); short_diag(2, 7);
		short_diag(3, 6); short_diag(3, 8);
		short_diag(4, 5); short_diag(4, 7);
		same_diag(1, 3); same_diag(2, 4);
		same_diag(5, 7); same_diag(6, 8);
	}
	while (!good());

	for (i = 1; i <= 8; i++)
		if (s[i]) nos = 1, i = 8;

	if (nos) printf("IMPOSSIBLE\n"); else
	for (i = 0; i < mv; i++)
		printf("%c%c%s\n", alfa[sol[i].n1], alfa[sol[i].n2], sol[i].what ? "+" : "-");
}

int main()
{
	readdata();
	solve();
	return 0;
}

/*
	Ea este Doamna cu coasa, trece prin ploi si prin rug...
*/
