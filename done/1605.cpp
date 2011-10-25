/*
 * ACM Timus Online
 * 1605 - Devil's Sequence
 *
 * Soluție: X[n] = 2/3 + 1/3 * (-1/2)^(n-1)
 */

#include <cstdio>

int N;

int CountDigits(int n)
{
  int c = 0;

  while (n > 0)
  {
    n /= 10;
    c++;
  }

  return c;
}

int main()
{
  scanf("%d", &N);

  // 1/2^(n-1) = 0.0...05^(n-1), nzero zerouri
  // calculăm numărul de cifre al lui 5^(n-1)
  int ncifre = (double)(N - 1) * 0.69897000433601880479 + 1;

  // numărul de zero-uri al lui 1/2^(n1-) e N-1 - ncifre
  int nzero = N - 1 - ncifre;

  // împărțim totul la 3, avem nevoie de primele câteva zecimale semnificative din 1/2^(n-1) deci de
  // fapt din 5^(n-1)
  int i, digits5 = 1;

  for (i = 1; i < N; i++)
  {
    // țin doar primele 8 cifre semnificative
    digits5 = digits5 * 5;
    if (digits5 >= 100000000)
    {
      digits5 /= 10;
    }
  }

  // verificăm dacă prin împărțirea de mai jos mai apare un zero extra. Pt asta prima cifră trebuie
  // să fie mai mică ca 3.
  int first = digits5;

  while (first >= 10)
  {
    first /= 10;
  }

  if (first <= 2)
  {
    nzero++;
  }
  digits5 /= 3;

  // acum adăugăm aceste digits5 la un șir infinit de 6 (2/3 adică) și vedem dacă nu dispare cumva un zero.
  // TODO: cazul cu +/- dacă se schimbă vreun 6 adăugând/scăzând 1/3*2^(n-1)
  int dig2, dig = CountDigits(digits5), digits6 = 0;

  for (i = 0; i < dig; i++)
  {
    digits6 = digits6 * 10 + 1;
  }
  digits6 *= 6;
  // digits6 are același număr de cifre ca și digits5, numai că toate 6
  
  if (N & 1)
  {
    // adun, N-1 e par
    digits6 += digits5;
    dig2 = CountDigits(digits6);

    if (dig2 > dig)
    {
      // am depășit deci mai dispare un zero
      nzero--;
    }
  }
  else
  {
    // scad, N-1 e impar
    digits6 -= digits5;
    if (digits6 < 0)
    {
      // am depășit în minus, iar dispare un zero
      nzero--;
    }
  }

  // fiecărui 0 din 1/3*2^(n-1) îi corespunde un 6 în rezultatul final, deci asta căutam
  printf("%d", nzero);

  return 0;
}

