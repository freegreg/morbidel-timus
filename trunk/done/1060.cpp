/*
 *  ACM Online
 *  Flip Game - Problem 1060
 *
 *  solutie: branch shmenar: fiecare configuratie e un nr. Œn baza 2 si-l
 *  transform†m Œn baza 10. Acum expand†m din nodul initial bifƒnd noile config.
 *  si retinem doar solutiile care n-au mai fost sau au fost dar oglindite sau rotite...
 *  In final dac† e bifat 0 sau 65535 e solutie
 */

#include <stdio.h>
#include <string.h>

int flag[66666L];
typedef int table[5][5];
table t;
long moves, q[10000], p2[20];


void readdata()
{
	char ch;
	int i, j;
	for (i = 1; i < 5; i++, scanf("\n"))
		for (j = 1; j < 5; j++)
			scanf("%c", &ch), t[i][j] = (ch == 'b' ? 1 : 0);
}

/*  table -> id  */
long get_id(table s)
{
	long i, j, pos = 0, id = 0;
	for (i = 1; i < 5; i++)
		for (j = 1; j < 5; j++, pos++)
			if (s[i][j])
				id += p2[15 - pos];
	return id;
}

/*  id -> table  */
void id_table(long id, table s)
{
	int i, b[20];
	for (id <<= 1, i = 15; i >= 0; i--)
		if ((id >>= 1) & 1) b[i] = 1; else b[i] = 0;
	for (i = 0; i < 16; i++)
		s[i / 4 + 1][i % 4 + 1] = b[i];
}

/*  move  */
void touch(table s, int l, int c)
{
	s[l][c] = 1 - s[l][c];
	if (l > 1) s[l - 1][c] = 1 - s[l - 1][c];
	if (l < 4) s[l + 1][c] = 1 - s[l + 1][c];
	if (c > 1) s[l][c - 1] = 1 - s[l][c - 1];
	if (c < 4) s[l][c + 1] = 1 - s[l][c + 1];
}

void rot90(table s)
{
	int i, j;
	table a;
	memcpy(a, s, sizeof(table));
	for (i = 1; i < 5; i++)
		for (j = 1; j < 5; j++)
			s[i][j] = a[j][5 - i];
}

void mirror(table s)
{
	int i, j, kk;
	for (i = 1; i < 5; i++)
		for (j = 1; j < 3; j++)
			kk = s[i][j], s[i][j] = s[i][5 - j], s[i][5 - j] = kk;
}

/*  verific† dac† mai e s Œn coad† si rotirile ei... */
int good(table s)
{
	long i, id;
	for (i = 0; i < 8; i++)
	{
		id = get_id(s);
		if (flag[id] >= 0) return 0;
		rot90(s);
		if (i == 3) mirror(s);
	}
	return 1;
}

void solve()
{
	table a;
	long i, j, l, ml, ids, idnow;
	for (i = 0; i <= 20; i++)
		p2[i] = (long)1 << i;
	ids = get_id(t);
	memset(flag, -1, sizeof(flag));

	// brenciu'
	q[0] = ids; flag[ids] = 0;
	for (l = 0, ml = 1; l < ml; l++)
	{
		if (flag[0] >= 0 || flag[65535L] >= 0) break;
		idnow = q[l];
		id_table(idnow, t);
		memcpy(a, t, sizeof(table));
		for (i = 1; i < 5; i++)
			for (j = 1; j < 5; j++)
			{
				memcpy(t, a, sizeof(table));
				touch(t, i, j);
				ids = get_id(t);
				if (good(t))
					flag[ids] = flag[idnow] + 1, q[ml++] = ids;
			}
	}
	moves = flag[0];
	if (flag[0] == -1 || (flag[65535L] != -1 && flag[65535L] < moves))
		moves = flag[65535L];
	if (moves >= 0)
		printf("%d\n", moves);
	else printf("Impossible\n");
}

int main()
{
	readdata();
	solve();
	return 0;
}
/*
	Dac† hip-hopu-i de c†cat eu am scaune zilnice
	si cei cu simtul olfactiv dezvoltat Œmi acorda aplauze ritmice,
	MC-ii Œmi adreseaz† laude cinice dar transpir† c†ci pentru ei
	sesiunile-s asemenea unor saune lirice...
*/

