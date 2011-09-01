/*
 *  ACM Online
 *  Amount of degrees - Problem 1057
 *
 *  solutie: calcul†m puterile lui B <= Y si le punem Œntr-un vector. Apoi
 *  facem combin†ri de Nr lor luate cƒte K si le num†r†m doar pe cele din interval.
 *  Pt baza 2 sunt 300 mil. deci facem un shmen: num†rul de numere format din
 *  x puteri ale lui 2 = 2^a - 1 este comb(a - 1, x) (!) si astfel avem rezultatul
 *  pt o putere a lui 2. Pt orice num†r Œl descompunem Œn puteri ale lui 2
 *  pe care le sc†dem cu 1 (f†r† ultima si cele perfecte) si le sum†m...
 */

#include <stdio.h>

int S[50];
long X, Y, B, K, N, Cnt = 0;
long double Pow[50];


long comb(int n, int k)
{
	long i, rez, nr = 2;
	if (2 * k > n) k = n - k;
	if (!k) return 1;
	rez = n - k + 1;
	for (i = n - k + 2; i <= n; i++)
	{
		rez *= i;
		while (rez % nr == 0 && nr <= k)
			rez /= nr++;
	}
	return rez;
}

long base_two()
{
	long i, j, x, c, num, flag[2][50], p2[50];

	for (i = 0; i < 50; i++)
		flag[0][i] = flag[1][i] = 0;
	for (i = p2[0] = 1; i < 31; i++)
		p2[i] = 2 * p2[i - 1];

	for (j = 0; j < 2; j++)
	{
		num = j ? Y : X - 1;
		for (c = 0; num; c++)
		{
			for (x = 0; x < 31; x++)
				if (p2[x] > num) break;
			for (x--, i = 0; i <= x; i++)
				flag[j][c + i] += comb(x, i);
			num -= p2[x];
		}
		flag[j][c]++;
	}

	return (flag[1][K] - flag[0][K]);
}

void back(int lev)
{
	int i;
	long double sum = 0;
	if (lev == K)
	{
		for (i = 0; i < K; i++)
			sum += Pow[S[i]];
		if (sum < X || sum > Y) return;
		Cnt++;
	} else
	for (i = lev ? S[lev - 1] + 1 : 0; i < N; i++)
		S[lev] = i, back(lev + 1), S[lev] = 0;
}

int main()
{
	scanf("%ld %ld %ld %ld", &X, &Y, &K, &B);

	for (Pow[0] = N = 1; Pow[N - 1] * (double)B <= Y; N++)
		Pow[N] = Pow[N - 1] * (double)B;
	if (B == 2)
		Cnt = base_two();
	else
		back(0);
	printf("%ld\n", Cnt);

	return 0;
}

/*
 *  Sistemul parc† ne curm† orice urm† de sperant†, expun totul Œn asta stant†
 *  parc-ar fi ultima, simt r†sufl†ri reci Œn ceaf†, Eminescu parc† m† priveste
 *  la fiecare leaf†, acas† dau acatiste dac† ajung teaf†r. Corbii t†rii-mi vor
 *  ochii, Œmi musc† sistemul nervos ca ?, sunt ca niste copii, Œmi joac† viitorul
 *  pe degete f†r† s† pregete, dac† esti acolo rege te implor d† pace, Œl suspectez
 *  chiar si pe Sage de a fi agent guvernamental, fac totul regulamentar, Œmi umbl† la
 *  mental, m† paste cancerul renal de la tratamentul penal la care-mi supun corpul
 *  stiu despre armele de foc care des Œsi ating scopul, stiu cele mai urƒte 10 crime
 *  si sper s† nu prind topul, dar prind stopul mereu Œn acelasi loc cu aceeasi
 *  masin†-n paralel, aceeasi ochi sperƒnd s† nu realizez c-a fost tot el, aceeasi
 *  mƒn† crispat† pe volan gata s† plece s† dea raportul, orice-as da ca de ziua
 *  lor s† le schimb Œn coliv† tortul...
 */
