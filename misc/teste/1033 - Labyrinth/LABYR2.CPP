/*
asd
F
*/
/* Solution for "Labyrinth" problem,
   Ural Programming Contest 1999 */

#include <fstream.h>
#include <io.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

char Q[35][35];

class Point
{
public:
        int x;
        int y;
        Point (int ix=0, int iy=0): x(ix), y(iy) {}
        Point (Point &p) { x=p.x, y=p.y; }
};

class StackElem
{
public:
        Point Value;
        StackElem *Next;
        StackElem (Point iValue=Point(), StackElem *iNext=NULL)
        {
                Value=iValue;
                Next=iNext;
        }
};

class Stack
{
protected:
        StackElem *Head;

public:
        Stack ()      { Head=NULL; }
        void  Push    (Point p);
        int   Pop     (Point &p);
    int   Empty   ();
        void  Destroy ();
        ~Stack ();
        Stack& operator << (Point p)  { Push(p);  return (*this); }
        int    operator >> (Point &p) { return Pop(p);  }
};

// class Stack implementation

void Stack::Push (Point p)
{
        StackElem *q=new StackElem(p,Head);
        if ( q==NULL )
        {
                cerr << "Out of memory" << endl;
                exit(1);
        }
        Head=q;
}

int Stack::Pop (Point &p)
{
        if ( Empty() )
                return 0;
        p=Head->Value;
        StackElem *old=Head;
        Head=Head->Next;
        delete old;
        return 1;
}

int Stack::Empty ()
{
        if ( Head == NULL )
                return 1;
        return 0;
}

void Stack::Destroy ()
{
        Point p;
        while (Pop(p));
}

Stack::~Stack ()
{
        Destroy();
}

int main ()
{
        ifstream in("input.txt");
        int N;
        in >> N;
        int i;
        for (i=0; i<N; i++)
                in >> Q[i];
        in.close();

        Stack st;

        Q[0][0]=Q[N-1][N-1]='+';
        st << Point(0,0) << Point(N-1,N-1);
        
        Point p;
        while (st >> p)
        {
                if ( p.x>0 )
                        if ( Q[p.x-1][p.y]=='.' )
                        {
                                Q[p.x-1][p.y]='+';
                                st << Point(p.x-1,p.y);
                        }
                if ( p.y>0 )
                        if ( Q[p.x][p.y-1]=='.' )
                        {
                                Q[p.x][p.y-1]='+';
                                st << Point(p.x,p.y-1);
                        }
                if ( p.x<N-1 )
                        if ( Q[p.x+1][p.y]=='.' )
                        {
                                Q[p.x+1][p.y]='+';
                                st << Point(p.x+1,p.y);
                        }
                if ( p.y<N-1 )
                        if ( Q[p.x][p.y+1]=='.' )
                        {
                                Q[p.x][p.y+1]='+';
                                st << Point(p.x,p.y+1);
                        }
        }

        double res=-4.;

        int j;
        for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                {
                        if ( Q[i][j] != '+' )
                                continue;

                        if ( i==0 || j==0 || i==N-1 || j==N-1 )
                        {
                                res+=
                                        ((i==0 || i==N-1)?1:0) +
                                        ((j==0 || j==N-1)?1:0);
                        }

                        if ( i>0 )
                                if ( Q[i-1][j]=='#' )
                                        res+=1.;

                        if ( j>0 )
                                if ( Q[i][j-1]=='#' )
                                        res+=1.;

                        if ( i<N-1 )
                                if ( Q[i+1][j]=='#' )
                                        res+=1.;

                        if ( j<N-1 )
                                if ( Q[i][j+1]=='#' )
                                        res+=1.;
                        //cout << (i+1) << " " << (j+1) << " cur res : " << res << endl;
                }

        ofstream out("output.txt");
        char str[20];
        sprintf(str,"%1.0lf",res*9.);
        out << str;
        out.close();

        return 0;
}
