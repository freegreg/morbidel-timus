/*
 * ACM Timus Online Judge
 * Ural Championship 2012 - Problem C
 * Neo-Venice
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

#define INPUT_FILE		"input.txt"
#define OUTPUT_FILE		"output.txt"
#define ABS(x)        ((x) > 0 ? (x) : -(x))
#define MAX(a, b)     ((a) > (b) ? (a) : (b))

using namespace std;

short N, T, S;


int main()
{
#ifndef ONLINE_JUDGE
	freopen(INPUT_FILE, "rt", stdin);
#endif

  int si;

  cin >> N >> T >> S;

  for (int i = 0; i < N; ++i)
  {
    cin >> si;

    // Anna va fi intre [s, s + t]
    // i-ul va fi intre [si, si + t]. Se intersecteaza cu Anna?
    if (si > S + T || si + T < S)
    {
      // nu tre sa se intample!
      while(1);
      continue;
    }

    double cross = (double)MAX(S, si) + ((double)T - ABS(si - S)) / 2;

    printf("%.6lf\n", cross);
  }

	return 0;
}