/*
  Reilway Tickets
  Pavel Zaletskiy pavelz@dpt.ustu.ru
*/

#include <fstream.h>

template <class T> void swap(T &a, T &b) { static T t; t=a; a=b; b=t; }

const maxn=20;
ifstream in[4]={"input.txt", "input.txt", "input.txt", "input.txt"};
ifstream &inc=in[3];
ofstream out("output.txt");
long dist[4]={0}, &distc=dist[3];
int pos[4]={0}, &posc=pos[3];
long zone[3], price[3];
long cost[maxn]={0};
int n, start, finish;

int main()
{
  for(int i=0;i<4;i++)
  {
    in[i]>>zone[0]>>zone[1]>>zone[2]
	 >>price[0]>>price[1]>>price[2]
	 >>n>>start>>finish;
    start--; finish--;
    if(start>finish) swap(start,finish);
  }
  for(posc=1;posc<=finish;posc++)
  {
    if(posc<=start)
      for(int j=0;j<4;j++) { in[j]>>dist[j]; pos[j]=posc; }
    else
    {
      inc>>distc;
      cost[posc]=1000000001L;
      for(int j=0;j<3;j++)
      {
	while(distc-dist[j]>zone[j]) { in[j]>>dist[j]; pos[j]++; }
	long c=price[j]+cost[pos[j]];
	if(c<cost[posc]) cost[posc]=c;
      }
    }
  }
  out<<cost[finish];
  return 0;
}
