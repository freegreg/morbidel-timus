/*
 *  ACM Online
 *  Fibonacci Sequence - Problem 1133
 *
 *  solutie: coborƒm din indicele cel mai mare pƒn† la cel mic si afl†m astfel
 *  doi consecutivi apoi Œi gener†m pe toti. Coeficientii †lora doi cns. sunt
 *  termeni din sirul lui Fibo cu t1 = 1, t2 = 2...
 *  sursa asta nu ia Accepted, dar scris†-n Pascal ia.. (de ce?)
 */

#include <stdio.h>

long double fib[2500], t[2500], fm, fn;
int k, l, m, n;


int main()
{
	int i;
	scanf("%ld %Lf %ld %Lf %ld", &m, &fm, &n, &fn, &k);
	if (m > n)
		fib[0] = m, m = n, n = fib[0], fib[0] = fm, fm = fn, fn = fib[0];
	m += 1000; n += 1000; k += 1000;
	t[0] = t[1] = 1; t[2] = 2;
	for (i = 3; i <= 2000; i++)
	   	t[i] = t[i - 1] + t[i - 2];
    l = n - m - 1;
	fib[m] = fm;
	fib[m + 1] = (fn - t[l - 1] * fm) / t[l];
	for (i = m + 2; i <= 2000; i++)
		 	fib[i] = fib[i - 1] + fib[i - 2];
	for (i = m - 1; i >= 0; i--)
		fib[i] = fib[i + 2] - fib[i + 1];

	printf("%.0Lf\n", fib[k]);
	return 0;
}
