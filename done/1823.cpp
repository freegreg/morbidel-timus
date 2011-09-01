/*
 * ACM Timus Online
 * Ideal Gas - Problem 1823
 *
 * solution: formula is pV = nRT (R = 8.314 J/(mol*K) )
 */


#include <cstdio>

#define R	8.314

double p, V, n, T;

int main()
{
	char ch;
	double value;


#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	p = V = n = T = -1;

	while (scanf("%c = %lf\n", &ch, &value) == 2)
	{
		if (ch == 'p' || ch == 'P')
			p = value;
		else if (ch == 'n' || ch == 'N')
			n = value;
		else if (ch == 'v' || ch == 'V')
			V = value;
		else if (ch == 't' || ch == 'T')
			T = value;
	}

	if (p == -1)
	{
		/* we need to compute p = n * R * T / V */
		p = n * R * T / V;
		printf("p = %.6lf", p);
	}
	else if (n == -1)
	{
		/* we need to compute n = p * V / (R * T) */
		n = p * V / (R * T);
		printf("n = %.6lf", n);
	}
	else if (p == 0 && n == 0)
	{
		goto undefined;
	}
	else if ((p == 0 && n != 0) || (p != 0 && n == 0)) 
	{
		goto error;
	}
	else if (V == -1)
	{
		/* we need to compute V = n * R * T / p */
		if (p == 0)
		{
			goto error;
		} 
		else if (n == 0)
		{
			goto undefined;
		}
		else
		{
			V = n * R * T / p;
			if (V <= 0)
				goto error;
			printf("V = %.6lf", V);
		}
	}
	else if (T == -1)
	{
		/* we need to compute T = p * V / (n * R) */
		if (n == 0)
		{
			goto error;
		} 
		else if (p == 0)
		{
			goto undefined;
		}
		else
		{
			T = p * V / (n * R);
			if (T <= 0)
				goto error;
			printf("T = %.6lf", T);
		}
	}


	return 0;
undefined:
	printf("undefined");
	return 0;
error:
	printf("error");
	return 0;
}

