/*
 *  ACM Timus Online
 *  Financial Error - Problem 1435
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN	200000L

int N;
long long A[MAXN];
long long Sum, Total, Delta;
long long pow10[64];


int SwitchDigits(long long &num, int p1, int p2)
{
  int n = 0;
  long long on = num;

  // count digits
  while (on > 0)
  {
    on /= 10;
    n++;
  }

  if (p1 >= n || p2 >= n || p1 < 0 || p2 < 0)
    return 1;

  // digit p1 and p2
  int c1 = (num / pow10[p1]) % 10;
  int c2 = (num / pow10[p2]) % 10;

  if (c1 == 0 && p2 == n - 1)
    return 1;

  num += pow10[p1] * (c2 - c1);
  num += pow10[p2] * (c1 - c2);

  return 0;
}

int main()
{
	int i, pos;

  pow10[0] = 1;
  for (i = 1; i < 64; i++)
    pow10[i] = pow10[i - 1] * 10;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	scanf("%d\n", &N);

	Total = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		Total += A[i];
	}
	scanf("%lld", &Sum);

	Delta = Sum - Total;

	if (Delta < 0) 
    Delta *= -1;

	if (Delta == 0)
	{
		printf("Input has no error.\n");
		return 0;
	}

  long long t1 = 9, t2 = 81, j;

  // check at what digit the mistake could have occured
	for (pos = 0; pos < 1000; pos++)
	{
		if (t1 <= Delta && Delta <= t2) 
      break;
		t1 *= 10;
		t2 *= 10;
	}

	for (i = 0; i < N; i++)
	{
		long long elem = A[i];

		Total -= elem;

    // test also pos nearby digits (-1, +1)
    for (j = pos - 1; j <= pos + 1; j++)
    {
      if (j < 0)
        continue;
  		if (!SwitchDigits(elem, j, j + 1))
	  	{
		  	Total += elem;
			  if (Total == Sum)
  			{
	  			printf("Error in record #%d. Correct number is: %lld.\n", i + 1, elem);
		  		return 0;
			  }
  			Total -= elem;

	  		SwitchDigits(elem, j, j + 1);
		  }
      else 
        break;
    }

  		Total += elem;
	}

	printf("Unrecoverable error.\n");

	return 0;
}
