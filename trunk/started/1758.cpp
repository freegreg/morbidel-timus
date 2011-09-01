/*
 *  ACM Timus Online
 *  Bald Spot Revisited 2 - Problem 1758
 */

//#include <stdio.h>
//#include <string.h>
//#include <vector>
//
//#define MAXN	64
//
//using namespace std;
//
//int N, MaxLen, NPieces;
//int Best[MAXN], S[MAXN];
//int Pieces[MAXN][3];
//int Flag[MAXN];
//
//
//void ComputePieces()
//{
//	int i, j, d, d1, d2;
//
//	NPieces = 0;
//	// compute the pieces
//	for (i = 2; i <= N; i++)
//	{
//		d = 0;
//
//		// search for numbers with just two divisors and/or multiples
//		for (j = 2; j <= N; j++)
//			if (i != j && (i % j == 0 || j % i == 0))
//			{
//				d++;
//				if (d == 1)
//					d1 = j;
//				else if (d == 2)
//					d2 = j;
//				else break;
//			};
//
//		if (d == 2)
//		{
//			Pieces[NPieces][0] = d1;
//			Pieces[NPieces][1] = i;
//			Pieces[NPieces][2] = d2;
//			printf("%d %d %d\n", d1, i, d2);
//
//			NPieces++;
//		}
//	}
//}
//
//int main()
//{
//	MaxLen = 0;
//
//	scanf("%d", &N);
//
//	ComputePieces();
//
//	return 0;
//}
