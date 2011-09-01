/*  
 *  Problem I - Tie  
 *  solutie: Cel mai lung subsir crescator...  
 */

#include <stdio.h>

int n, max = 0, x[200], v1[200], v2[200];


int main()
{
	int i, j, k;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &v1[i], &v2[i]);

	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (v1[i] > v1[j])
				k = v1[i], v1[i] = v1[j], v1[j] = k, 
				k = v2[i], v2[i] = v2[j], v2[j] = k; 

	for (i = 0; i < n; i++)
	{
		x[i] = 1; 
		for (j = 0; j < i; j++)
			if (v2[j] <= v2[i] && x[j] + 1 > x[i]) 
				x[i] = x[j] + 1;
		if (x[i] > max)
			max = x[i];
	}
	printf("%d\n", n - max);

	return 0;
}
