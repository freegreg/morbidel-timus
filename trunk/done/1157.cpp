/*
 *  ACM Online
 *  Young Tiler - Problem 1157
 *
 *  baleiem toate L pƒn† la 10000 si verific†m dac† cu L-K au fost M si acum
 *  sunt N. Num†rul †la de dreptunghiuri e nr. de divizori <= ûN. Evident de ce...
 */

#include <stdio.h>

int M, N, K, L, last[10000], sol = 0;


int main()
{
	int i, how;

	scanf("%d %d %d", &M, &N, &K);

	for (L = 1; L <= 10000; L++)
	{
		for (how = 0, i = 1; i * i <= L; i++)
			if (L % i == 0) how++;
		last[L] = how;
		if (last[L] == N && L > K && last[L - K] == M)
			sol = L, L = 10000;
	}
	printf("%d\n", sol);

	return 0;
}
/*
	C†ci face diferenta dintre inferior si superior, dintre imitator si creator,
	dintre afon si cunosc†tor, si dac† cel ce-ascult† crede c† gusturile nu se
	discut† Œnseamn† c†-n hip-hop Œiplace muia Œn cantitate mult†.
*/
