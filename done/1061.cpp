/*
 *  ACM Online
 *  Buffer Manager - Problem 1061
 *
 *  solutie: se cere secv. de K elemente cu suma maximå; tinem un vector cu ce citim si facem suma
 *  curentå, o reactualizåm...
 */

#include <stdio.h>

long n, k, sum, poz, smax = 1e9L;
int a[100100L];


int main()
{
	char ch;
	long i;

	scanf("%ld %ld\n", &n, &k);
	poz = sum = 0; i = 0;
	while (i < n)
	{
		scanf("%c", &ch);
		if ((ch != '*' && ch <'0') || ch > '9') continue;
		i++;
		if (ch == '*') a[0] = sum = 0;
		else
		{
			a[++a[0]] = ch - '0';
			sum += a[a[0]];
			if (a[0] > k)
				sum = sum - a[a[0] - k];
			if (a[0] >= k && sum < smax)
				smax = sum, poz = i - k + 1;
		}
	}
	printf("%ld\n", poz);

	return 0;
}

/*
	Ceata de flåcåi cu plete si cu cobza-n mânå, a pornit si pe-ndelete de då sara bunå...
 */
