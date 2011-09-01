#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>

ifstream in("input.txt");
ifstream inout("output.txt");

int n;
int sons[101][101];
int ns[101];
int np[101];
int ans[101];
int used[101];

void input()
{
  in >> n;
	int i,j;

	for (i=1; i<=n; i++)
	 for (j=1; j<=n; j++)
	  sons[i][j]=0;

	for (i=1; i<=n; i++)
	{
	  ns[i]=0;
	  np[i]=0;
	  ans[i]=0;
	  used[i]=0;
	}

  for (i=1; i<=n; i++)
  {
	 in >> j;
	  while (j)
	  {
		sons[i][j]=1;
		ns[i]++;
		np[j]++;
		in >> j;
	  }
  }
}

void test()
{
 int i,j;
	for (i=1; i<=n; i++)
	{
	  if (inout.eof())
	  {
		cout << "Insufficient number of entry values\n";
		exit(EXIT_FAILURE);
	  }
	 inout >> ans[i];
	}

	char nl[5];
	inout.getline(nl,4);

	 if (!inout.eof())
	  {
		cout << "Too many entry values\n";
		exit(EXIT_FAILURE);
	  }

 int curr;

 for (i=1; i<=n; i++)
 {
  int curr = ans[i];
	if (used[curr])
	{
		cout << "Repetitions found in entry sequence!\n";
		exit(EXIT_FAILURE);
	}
	used[curr]=1;
	 if (np[curr])
	 {
		cout << "Wrong order\n";
		exit(EXIT_FAILURE);
	 }
	for (j=1; j<=n; j++)
	 if (sons[curr][j])
	  np[j]--;
 }

 cout << "Output corresponds to the input correctly\n";
}

int main()
{
  input();
  test();
 return 0;
}