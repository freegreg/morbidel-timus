// ACM Online
// Problem 1201 - Days

#include <stdio.h>

int day, month, year, leap, jan1;
int months[7][6];        // 0..6 = Mon..Sun, s†pt†mƒnile
int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char zile[7][4] = { "mon", "tue", "wed", "thu", "fri", "sat", "sun" };


void readdata()
{
	scanf("%d %d %d", &day, &month, &year);
}

int firstday()               // cƒnd e prima zi a lunii cerute
{
	int i, next = jan1;
	for (i = 0; i < month - 1; i++)
	{
		switch (days[i])
		{
			case 28: break;
			case 29: next = (next + 1) % 7; break;
			case 30: next = (next + 2) % 7; break;
			case 31: next = (next + 3) % 7; break;
		}
	}
	if (!next) next = 7;
	return next;
}

void solve()
{
	int y = year - 1, day1, i, j, last, bad;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0); // bisect ?
	jan1 = (1 + y + (y / 4) - (y / 100) + (y / 400)) % 7; // 1 ianuarie (!)
	if (!jan1) jan1 = 7;               // Duminica o punem 7...
	days[1] += leap;                   // ad†ug†m 1 la Feb. dac† e an bisect
	day1 = firstday();                 // prima zi a lunii cerute
	for (i = day1 - 1; i <= 7; i++)    // complet†m prima s†pt†mƒn†
		months[i][0] = i - day1 + 2;
	last = months[6][0];
	for (i = 1; i < 6; i++)
		for (j = 0; j < 7; j++)
			months[j][i] = ++last;

	for (bad = i = 0; i < 7; i++)
	{
		printf("%c%c%c ", zile[i][0], zile[i][1], zile[i][2]);
		if (!(months[i][0] == day && day / 10 == 0)) printf(" ");
		if (months[i][0] == day)
		{
			if (day / 10 == 0)
				printf("[ %d]", months[i][0]);
			else printf("[%d]", months[i][0]);
		}
		else
		{
			printf(" ");
			if (!months[i][0]) printf(" "); else printf("%d", months[i][0]);
		}
		for (j = 1; j < 6; j++)
		{
			if (months[i][j] > days[month - 1])
			{
				if (months[0][j] <= days[month - 1])
					printf("     ");
				continue;
			}
			if (months[i][j] == day)
			{
				if (months[i][j] / 10 == 0) printf("  [ ");
				else printf("  [");
				printf("%d]", months[i][j]);
				continue;
			}
			if (months[i][j] / 10 == 0) printf(" ");
			if (months[i][j] - 7 == day) printf("  "); else printf("   ");
			printf("%d", months[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	readdata();
	solve();
	return 0;
}
