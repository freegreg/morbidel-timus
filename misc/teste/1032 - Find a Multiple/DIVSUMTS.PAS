program divsumts;
{�ணࠬ�� �஢���� �ࠢ��쭮��� �⢥� �� ������ divsum}
Const
   nmax = 10000;
Type
   list = array[1..nmax] of integer;
Var
   a : list;
   b : integer; {�᫮ �� 䠩�� � १���⠬� ���}
   n : integer; {������⢮ �ᥫ � ��室��� 䠩��}
   k : integer; {������⢮ �ᥫ � 䠩�� � १���⠬� ���}
   i : integer; {����� �᫠ � ��室��� ᯨ᪥}
   j : integer; {����� �᫠ � ᯨ᪥ १���� ���}
   infile : text; {䠩� � �室�묨 ����묨}
   tstfile : text; {䠩� � १���⠬� ���஢����}
   sum : longint;
   numexist : boolean; {�ਧ��� ����⢮����� �᫠ � ��室��� ᯨ᪥}
Begin
   Writeln('��砫� ࠡ��� ������饩 �ணࠬ��');
   Assign(infile,'input.txt');
   Reset(infile);
   Assign(tstfile,'output.txt');
   reset(tstfile);
   sum := 0;
   Readln(infile,n);
   for i := 1 to n do
      readln(infile,a[i]);
   Readln(tstfile,k);
   If k <= 0 then
      Begin
         Writeln('����୮� ������⢮ �ᥫ � १���� ���');
         Halt(4)
      End;
   j := 1;
   numexist := true;
   While (j <= k) and numexist do
      Begin
         if eof(tstfile) then
            Begin
               Writeln('���������� ����� 䠩��');
               Halt(3)
            End;
         Readln(tstfile,b);
         if b <= 0 then
            Begin
               Writeln('��᫮ ',b,' ��������� �� �室��� ������.');
               Halt(1)
            End;
         i := 1;
         While (i <= n) and (a[i] <> b) do
            inc(i);
         if i > n then
            Begin
               Writeln('��᫮ ',b,' ��������� �� �室��� ������.');
               Halt(1)
            End
         Else
            Begin
               Sum := Sum + b;
               a[i] := -1
            End;
         inc(j)
      End;
   if (sum mod n) <> 0 then
      Begin
         Writeln('�訡�筠� �㬬�');
         Halt(2)
      End
   Else
      Begin
         Writeln('���� �ன��� �ᯥ譮');
         halt(0)
      End
End.