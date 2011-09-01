/*
 *  ACM Timus Online
 *  Elevator - Problem 1602
 */

#include <stdio.h>
#include <math.h>

#define input "input.txt"
#define max(a, b) ((a) > (b) ? (a) : (b))

double N, K, U, V;
double time, time_min;
int etaj_magic = -1;


int main()
{
	#ifndef ONLINE_JUDGE
	freopen(input, "r", stdin);
	#endif

	scanf("%lf %lf %lf %lf", &N, &K, &U, &V);

	double i;

	time_min = (N - 1) * U;
	etaj_magic = 1;

	// cobor i etaje pe jos
	for (i = N - 2; i >= 0; i--)
	{
		double lift_jos = (K - 1) * V + 15;
		double gigel_jos = i * U;

		time = max(lift_jos, gigel_jos);

		// a coborat i etaje pe scari, liftul urca de jos N - i - 1 etaje
		time += 2 * V * (N - i - 1);

		// imbarcare/debarcare
		time += 5;

		if (time < time_min || fabs(time - time_min) < 10e-6)
		{
			etaj_magic = N - i;
			time_min = time;
		}
	}

	printf("%d\n", etaj_magic);


	return 0;
}
