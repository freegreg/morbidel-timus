/*
 *  ACM Timus Online
 *  The knight - Problem 1298
 */

#include <stdio.h>

long N;
char sol5[25][3] = {"a1","b3","a5","c4","e5","d3","e1","c2","a3","b1","d2","e4","c5","a4","b2","d1","e3","d5","b4","a2","c1","e2","c3","b5","d4"};
char sol6[36][3] = {"a1","b3","a5","c6","e5","f3","e1","c2","a3","b1","d2","f1","e3","f5","d4","b5","d6","c4","b6","a4","b2","d1","f2","e4","f6","d5","c3","a2","b4","a6","c5","e6","f4","d3","c1","e2"};
char sol7[49][3] = {"a1","b3","a5","b7","d6","f7","g5","e6","g7","f5","e7","g6","f4","g2","e1","c2","a3","b1","d2","f1","g3","e2","g1","f3","d4","b5","a7","c6","b4","a2","c1","d3","b2","a4","b6","c4","e5","d7","c5","a6","c7","d5","c3","d1","e3","g4","f2","e4","f6"};
char sol8[64][3] = {"a1","b3","a5","b7","d8","f7","h8","g6","f8","h7","g5","h3","g1","e2","c1","a2","b4","a6","b8","c6","a7","c8","e7","g8","h6","g4","h2","f1","d2","b1","a3","c2","e1","f3","h4","g2","e3","d1","b2","a4","c3","b5","d4","f5","d6","c4","e5","d3","f2","h1","g3","e4","c5","d7","b6","a8","c7","d5","f4","e6","g7","e8","f6","h5"};


int main()
{	
	int i;

	scanf("%d", &N);

	if (N == 1)
		printf("a1\n");
	else
	if (N < 5)
		printf("IMPOSSIBLE\n");
	else
	for (i = 0; i < N * N; i++)
	{
		if (N == 5)
			printf("%s\n", sol5[i]);
		if (N == 6)
			printf("%s\n", sol6[i]);
		if (N == 7)
			printf("%s\n", sol7[i]);
		if (N == 8)
			printf("%s\n", sol8[i]);
	}

	
	return 0;
}
