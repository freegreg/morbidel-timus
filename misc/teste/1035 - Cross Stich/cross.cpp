/*
  Pavel Zaletskiy pevelz@dpt.ustu.ru
*/

#include <fstream.h>
#include <stdlib.h>

ifstream in("input.txt");
ofstream out("output.txt");

typedef unsigned char uchar;
typedef unsigned int uint;
const uint MAXS=201;

uchar huge field[MAXS*MAXS]={0};
uint huge que[MAXS*MAXS];
char huge lab[MAXS*MAXS]={0};

int main()
{
  long n,m;
  in>>n>>m; in.ignore(1000, '\n');
  for(int k=0;k<2;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
        uchar ch; in>>ch;
        switch(ch)
        {
          case 'X':
          case '/':
	    field[(i+1)*(m+1)+j] |= 1<<(4*k);
	    field[i*(m+1)+j+1] |= 1<<(4*k+2);
	    if(ch=='/') break;
	  case '\\':
	    field[i*(m+1)+j] |= 1<<(4*k+1);
	    field[(i+1)*(m+1)+j+1] |= 1<<(4*k+3);
	}
      }
  long dx[]={-m,m+2,m,-m-2};
  long count=0;
  for(long x=0;x<(n+1)*(m+1);x++)
      if(lab[x]==0)
      {
	long c=0;
	long qb=0, qe=0; que[qe++]=(uint)x; lab[x]=1;
	while(qb!=qe)
	{
	  long cx=que[qb++];
	  long cc=0;
	  for(int k=0;k<8;k++)
            if((field[cx] & (1<<k)) != 0)
            {
	      cc+= k<4 ? 1 : -1;
	      long nx=cx+dx[k%4];
	      if(lab[nx]==0)
	      {
		que[qe++]=(uint)nx;
		lab[nx]=1;
	      }
	    }
	  c+=labs(cc);
	}
	if(qb>1) count += c==0 ? 1 : c/2;
      }
  out<<count;
  return 0;
}
