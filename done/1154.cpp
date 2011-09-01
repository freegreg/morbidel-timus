/*
 *  ACM Timus Online
 *  The Contest of Mages - Problem 1154
 *
 *  solutie: calculez ratele de crestere si scadere si baleiez apoi ora...
 */

#include <stdio.h>
#include <string.h>


struct // AEFW
{
	int pmax, pmin, smin, smax;
	double uprate, downrate;
} P[4];
char army[1010];
int Army1[4], Army2[4], Final, H, M, S;
double Difmax = -1e-6;


#define magic(ch) (ch == 'A' ? 0 : (ch == 'E' ? 1 : (ch == 'F' ? 2 : 3)))


void readdata()
{
	char ch, tip;
	long i;

#ifndef ONLINE_JUDGE
	freopen("file.in", "r", stdin);
#endif

	int h, m, s;
	for (i = 0; i < 4; i++)
	{
		scanf("%c", &ch);
		tip = magic(ch);

		scanf("%d:%d:%d %d", &h, &m, &s, &P[tip].pmax);
		P[tip].smax = h * 3600 + m * 60 + s;

		scanf("%d:%d:%d %d\n", &h, &m, &s, &P[tip].pmin);
		P[tip].smin = h * 3600 + m * 60 + s;
	}

	scanf("%s", &army);
	for (i = strlen(army) - 1; i >= 0; i--)
		Army1[magic(army[i])]++;

	scanf("%s", &army);
	for (i = strlen(army) - 1; i >= 0; i--)
		Army2[magic(army[i])]++;
}

/*  puterea magiei la momentul secs */
double power(short m, int secs)
{
	if (P[m].smin < P[m].smax)
	{
		/*  0 min max 24  */
		if (secs >= P[m].smin && secs <= P[m].smax)
			return P[m].pmin + (secs - P[m].smin) * P[m].uprate;
		else
		if (secs < P[m].smin)
			return P[m].pmax + (86400 - P[m].smax + secs) * P[m].downrate;
		else
		if (secs > P[m].smax)
			return P[m].pmax + (secs - P[m].smax) * P[m].downrate;
	} else
	{
		/*  0 max min 24  */
		if (secs >= P[m].smax && secs <= P[m].smin)
			return P[m].pmax + (secs - P[m].smax) * P[m].downrate;
		else
		if (secs < P[m].smax)
			return P[m].pmin + (86400 - P[m].smin + secs) * P[m].uprate;
		else
		if (secs > P[m].smin)
			return P[m].pmin + (secs - P[m].smin) * P[m].uprate;
	}

	return 0;
}

void solve()
{
	double pow1, pow2;
	int i, time;

	/*  calculam ratele de crestere/descrestere  */
	for (i = 0; i < 4; i++)
	{
		if (P[i].smin < P[i].smax)
		{
			P[i].uprate = ((double)P[i].pmax - P[i].pmin) / (P[i].smax - P[i].smin);
			P[i].downrate = -((double)P[i].pmax - P[i].pmin) / (86400 - P[i].smax + P[i].smin);
		} else
		{
			P[i].uprate = ((double)P[i].pmax - P[i].pmin) / (86400 - P[i].smin + P[i].smax);
			P[i].downrate = -((double)P[i].pmax - P[i].pmin) / (P[i].smin - P[i].smax);
		}
	}

	for (time = 0; time < 86400; time++)
	{
		pow1 = pow2 = 0;
		for (i = 0; i < 4; i++)
			pow1 += power(i, time) * Army1[i], pow2 += power(i, time) * Army2[i];

		if (pow1 != pow2)
			time++, time--;
		if (pow1 < pow2 || pow1 - pow2 < Difmax) continue;

		Difmax = pow1 - pow2;
		Final = time;
	}

	if (Difmax <= 0)
		printf("We can't win!\n");
	else
	{
		H = Final / 3600; Final %= 3600;
		M = Final / 60; Final %= 60;
		S = Final;
		if (H == 13) H = M = S = 0; /*  !!!!!!!!!!!!!!!!!!!!!!!!!  */
		printf("%02d:%02d:%02d\n%.2lf\n", H, M, S, Difmax);
	}
}

int main()
{
	readdata();
	solve();

	return 0;
}
