/*
 * ACM Timus
 * 1467 - Sum of degrees
 */

#include <stdio.h>

long K;

class CFraction
{
public:
	CFraction() { nUp = 0; nDown = 1; }

	__int64 nUp;
	__int64 nDown;

	CFraction& operator = (CFraction x)
	{
		nUp = x.nUp;
		nDown = x.nDown;

		return *this;
	}

	CFraction operator + (CFraction x)
	{
		CFraction aux(nUp * x.nDown + nDown * x.nUp, nDown * x.nDown);
		Reduce(aux);

		return aux;
	}

	CFraction operator - (CFraction x)
	{
		CFraction aux(nUp * x.nDown - nDown * x.nUp, nDown * x.nDown);
		Reduce(aux);

		return aux;
	}

	CFraction operator * (CFraction x)
	{
		CFraction aux(nUp * x.nUp, nDown * x.nDown);
		Reduce(aux);

		return aux;
	}

	CFraction operator / (CFraction x)
	{
		CFraction aux(nUp * x.nDown, nDown * x.nUp);
		Reduce(aux);

		return aux;
	}

	void Reduce(CFraction &x)
	{
		__int64 d = gcd(x.nUp, x.nDown);
		x.nUp	/= d;
		x.nDown /= d;
	}


protected:
	__int64 gcd(__int64 a, __int64 b)
	{
		return (b == 0) ? a : gcd(b, a % b);
	}
};


CFraction A[32];

__int64 Combination(int n, int k)
{
	__int64 res = 1;
	int i, c;

	if (2 * k > n)
		k = n - k;

	i = 2;
	c = n - k + 1;
	while (true)
	{
		if (i <= k && res % i == 0)
			res /= i, i++;
		if (c <= n)
			res *= c++;

		if (i > k && c > n)
			break;
	}

	return res;
}

int main()
{
 	int i, j;

	scanf("%d", &K);

	A[K + 1] = CFraction(1, K + 1);
	for (j = K; j > 0; j--)
	{
		CFraction sum;

		for (i = j + 1; i <= K + 1; i++)
		{
			__int64 num = Combination(i, j - 1) * (((i - j + 1) & 1) ? -1 : 1);

			sum = sum + A[i] * CFraction(num, 1);
		}

		A[j] = sum * CFraction(1, j);
	}

	for (i = K + 1; i >= 0; i--)
	{
		if (A[i].nDown < 0)
			A[i].nDown *= -1, A[i].nUp *= -1;
		printf("%I64d/%I64d ", A[i].nUp, A[i].nDown);
	}

	return 0;
}
