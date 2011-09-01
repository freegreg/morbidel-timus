// ACM Online
// Democracy in Danger - Problem 1005

// solutie: se injumatatesc toate numerele apoi se sorteaza crescator si
// se aleg primele k / 2 + 1

#include <stdio.h>

int n, s[100], sum = 0;

void main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &j);
		s[i] = j / 2 + 1;
	}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (s[i] > s[j])
				s[i] += s[j], s[j] = s[i] - s[j], s[i] -= s[j];
	for (i = 0; i < n / 2 + 1; i++)
		sum += s[i];
	printf("%d", sum);
}