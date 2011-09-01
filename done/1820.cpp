#include <stdio.h>

int N, K, Sol;

int main()
{
	scanf("%d %d", &N, &K);
	if (K > N)
		K = N;
	Sol = 2 * N;
	Sol /= K;

	if ((2 * N) % K)
		Sol ++;
	printf("%d\n", Sol);

	return 0;
}
