#include "iostream.h"
#include "fstream.h"
#include "stdlib.h"

#define SIZE 30000
#define DELAY 600

ofstream out("input.txt");

int main()
{
  long iCount;
  long lTime = 0;
/*
  for (iCount = 1; iCount <= 30000; iCount++)
    if (iCount <= SIZE - DELAY)
      out << "1 +" << endl;
    else
      out << (iCount - SIZE + DELAY) << " +" << endl;
*/
  for (iCount = 1; iCount <= 30000; iCount++)
    if (iCount <=  30000 - DELAY/2)
      out << 1 << " +" << endl;
    else
      out << (iCount + DELAY/2 - 30000 ) << " +" << endl;
  for (iCount = 1; iCount <= 30000; iCount++)
  {
    if (iCount < 10000)
      out << (301) << " . " << (iCount) << endl;
    else if (iCount % 2 == 0)
      out << (302) << " . " << (iCount) << endl;
  }
/*
    if (iCount <= DELAY)
    {
      out << (599 + iCount) << " . " << (iCount) << endl;
//      out << (599 + iCount) << " . " << (30000 - iCount) << endl;
    }
    else
      out << (1198) << " . " << iCount << endl;
  }
*/

  for (iCount = 1; iCount <= 30000; iCount++)
    if (iCount <= 10000)
    {
      if (iCount <= DELAY/2)
        out << (600 + iCount) << " +" << endl;
      else
        out <<  "900 +" << endl;
    }
    else
    {
      if ((iCount-10000) <= DELAY/2)
        out << (900 + (iCount-10000)) << " +" << endl;
      else
        out <<  "1200 +" << endl;
    }
/*
    {
      if (iCount <= DELAY)
        out << (1197 + iCount/2) << " +" << endl;
      else
        out <<  "1797 +" << endl;
    }
*/
/*
  for (iCount = 1; iCount <= 100; iCount++)
  {
    lTime += random(50);
    if (random(2))
    {
      out << lTime << " +" << endl;
    }
    else
    {
      out << lTime << " . " << random(50) << endl;
    }
  }
*/
  return 0;
}