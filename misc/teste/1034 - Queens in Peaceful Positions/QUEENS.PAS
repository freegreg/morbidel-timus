 Program queens;
{�ணࠬ�� �蠥� ᫥������ ������. � �����⭮� ⠡��� n �� n ���⠢����
n ����� �৥�. ����쪮 ������� ᯮᮡ�� ����⠢��� ஢�� �� ��� ⠪,
�⮡� ��ࠧ������� ᭮�� ��ୠ� ������? }
Const
   nmax = 50; {���ᨬ��쭠� ��஭� ������}
Type
   Position = array[1..nmax] of integer;
Var
   p : position; {��室��� ������. �[i] = j <==> � i-� �⮫�� � j-� ��ப�
	               �⮨� ���}
   pnew : position; {������ ��᫥ ����⠭���� �৥�}
   n : integer;          {��஭� ������}
   i1, i2, i3 : integer; {����� ����⠢�塞�� �৥�}
   Count : longint; {���稪 �ࠢ����� ����権, ���������� ��᫥
	                  ����⠭����}
   tmp : integer; {�६����� ��६����� ��� �����⢫���� ����⠭����}
   well : boolean; {�ਧ��� ⮣�, �� ����� ������ ��ୠ�}

Procedure Indata;
Var
   filein : text;
   i : integer; {����� ��।���� ���}
   r, c : integer; {����� ��ப� � ����� ������� ����樨 ��।���� ���}
Begin
   Assign(filein,'input.txt');
   Reset(filein);
   Readln(filein,n);
   for i := 1 to n do
      Begin
         Readln(filein,r,c);
         p[c] := r
      End
End; {Indata}

Procedure Testperm(var w : boolean);
{��楤�� �஢����, ���� �� ��୮� ������, ����稢���� ��᫥
����⠭���� ��� �৥�}
Var
   i : integer; {����� ����㥬��� ���}
Begin
   i := 1;
   While (i<=n) and (((i=i1) or (abs(i-i1) <> abs(pnew[i]-pnew[i1]))) and
                     ((i=i2) or (abs(i-i2) <> abs(pnew[i]-pnew[i2]))) and
                     ((i=i3) or (abs(i-i3) <> abs(pnew[i]-pnew[i3])))) do
      inc(i);
   w := i > n
End; {Testperm}

Procedure Outresult;
Var
   fileout : text;
Begin
   Assign(fileout,'output.txt');
   Rewrite(fileout);
   Writeln(fileout,count);
Writeln(count);
   Close(fileout)
End; {Outresult}



Begin
   Indata;
   Count := 0;
   For i1 := 1 to n-2 do
      For i2 := i1+1 to n-1 do
         For i3 := i2+1 to n do
            Begin
               pnew := p;
               {��ࢠ� 横���᪠� ����⠭���� �ன��}
               tmp := pnew[i1];
               pnew[i1] := pnew[i2];
               pnew[i2] := pnew[i3];
               pnew[i3] := tmp;
               testperm(well);
               if well then
Begin
                  inc(count);
Writeln('1 ',i1,' ',i2,' ',i3)
End;
               {���� 横���᪠� ����⠭���� �ன��}
               tmp := pnew[i1];
               pnew[i1] := pnew[i2];
               pnew[i2] := pnew[i3];
               pnew[i3] := tmp;
               testperm(well);
               if well then
Begin
                  inc(count)
;Writeln('2 ',i1,' ',i2,' ',i3)
End;
            End;
   Outresult
End.