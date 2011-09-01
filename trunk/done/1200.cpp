/*
 *  ACM Timus Online
 *  Horns and Hoofs - Problem 1200
 *
 *  solutie: calculez varful parabolei...
 *   am ecuatia -A * A + A * Pa - B * B + B * Pb cu extremul e-n punctul -b/2a adica Pa / 2 
 */

#include <stdio.h>

double Pa, Pb, Total, Max;
long A, B, K, Opta, Optb;


void brute()
{
	Opta = Optb = Max = 0;

	for (A = 0; A <= K; A++)
		for (B = 0; B <= K - A; B++)
		{
			Total = A * Pa + B * Pb - A * A - B * B;
			if (Total > Max)
				Max = Total, Opta = A, Optb = B;
		}
	printf("%.2lf\n%ld %ld\n", Max, Opta, Optb);
}

int main()
{
	scanf("%lf %lf %I64d", &Pa, &Pb, &K);

	brute();
	return 0;

	Opta = Optb = Max = 0;

	for (B = 0; B <= K; B++)
	{
		A = Pa / 2;
		if (A > K - B) 
			A = K - B;
		if (A < 0)
			A = 0;

		int i, eps = 10;
		for (i = A - eps; i <= A + eps; i++)
		{
			if (B + i > K) break;
			if (i < 0) continue;
			Total = i * Pa + B * Pb - i * i - B * B;
			if (Total > Max)
				Max = Total, Opta = i, Optb = B;
		}
	}

	printf("%.2lf\n%ld %ld\n", Max, Opta, Optb);

	return 0;
}
