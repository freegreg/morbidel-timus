/*
asd
D
*/
/*
  Railway Tickets
  Pavel Zaletskiy pavelz@dpt.ustu.ru
*/

#include <fstream.h>

template <class T> void swap(T &a, T &b) { static T t; t=a; a=b; b=t; }

const maxn=10000;
ifstream in("input.txt");
ofstream out("output.txt");
long zone[3], price[3];
long dist[maxn]={0};
long far cost[maxn]={0};
int posc, n, start, finish;

int main()
{
  in>>zone[0]>>zone[1]>>zone[2]
       >>price[0]>>price[1]>>price[2]
       >>n>>start>>finish;
  start--; finish--;
  if(start>finish) swap(start,finish);
  for(posc=1;posc<=finish;posc++)
  {
    in>>dist[posc];
    if(posc>start)
    {
      cost[posc]=1000000001L;
      for(int j=0;j<3;j++)
      {
	int l=0, r=posc;
	while(l!=r)
	{
	  int o=(l+r)/2;
	  if(dist[posc]-dist[o]>zone[j]) l=o+1; else r=o;
	}
	long c=price[j]+cost[l];
	if(c<cost[posc]) cost[posc]=c;
      }
    }
  }
  out<<cost[finish];
  return 0;
}
