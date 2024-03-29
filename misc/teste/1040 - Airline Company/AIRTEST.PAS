program airtst;
{�஢������ �ணࠬ�� ��� �ணࠬ�� airprime}
Const
   nmax = 50;
   mmax = 1500;
Type
   boolrow = array[1..nmax] of boolean;
   boolmatr = array[1..nmax] of boolrow;
   boolrow1 = array[1..mmax] of boolean;
   introw = array[1..mmax] of integer;
Var
   n : integer; {������⢮ ���設 (��ய��⮢)}
   m : integer; {������⢮ ॡ�� (३ᮢ)}
   s : boolmatr; {����� ᬥ�����}
   l : introw; {ᯨ᮪ �।�������� ����஢ ॡ�� (३ᮢ)}
   buff : string; {��ப� �⢥�}
   lbuff : integer; {����� ��ப� �⢥�}
   c : integer; {����� ᨬ���� � ����}
   errcode : integer; {��� �訡�� �� ��ॢ��� ��ப� � �᫮}
   nstr : string; {����� ��।���� ॡ� � ��ப���� �ଥ}
   nuse : boolrow1; {�ਧ��� ⮣�, �� �᫮ 㦥 ����� ��� ����� ३�}
   infile : text; {input.txt}
   outfile : text; {output.txt}
   k : integer; {����� ॡ�}
   i,j : integer; {����� ���設}
   nbi : integer; {������⢮ �ᥤ�� � ���設� � ����஬ i}
   ik1,ik2 : introw; {����� ���設, ��樤����� ॡ�� � ����஬ k}
   gcdi : integer; {��� ॡ��, ��樤����� i-�� ���設�}

function gcd(a : integer; b : integer) : integer;
{��宦����� ���(a,b)}
var
   r : integer; {���⮪}
Begin
   r := a mod b;
   while r <> 0 do
      begin
         a := b;
         b := r;
         r := a mod b
      end;
   gcd := b
End; {gcd}


begin
   Assign(infile,'input.txt');
   Reset(infile);
   Readln(infile,n,m);
   Assign(outfile,'output.txt');
   Reset(outfile);
{�஢�ઠ ��ࢮ� ��ப�}
   Readln(outfile,buff);
   If buff<>'YES' then
      begin
         writeln('����ୠ� ��ࢠ� ��ப� ��室���� 䠩��!');
         halt(1)
      end;
{������ � ���⥩�� �஢�ઠ ��ன ��ப�}
k := 0;
nstr := '';
While not eoln(outfile) do
Begin
   Read(outfile,buff);
   lbuff := length(buff);
   c := 1;
   While c <= lbuff do
      Begin
         {����祭�� ��।���� ����� ३�}
         while (c<=lbuff) and (buff[c]<>' ')do
            begin
               nstr := nstr + buff[c];
               inc(c)
            end;
         if (c<=lbuff) or (eoln(outfile)) then
            Begin
               inc(k);
               val(nstr,l[k],errcode);
               nstr := '';
               {���⥩訥 �஢�ન}
               if errcode <> 0 then
                  Begin
                     Writeln('������ ᨬ��� � ��室��� 䠩��!');
                     Halt(2)
                  End;
               If (l[k]<1) or (l[k]>m) then
                  Begin
                     writeln('����� ३� ��� �����⨬��� ���������!');
                     Halt(3)
                  End;
               {�ய�� �஡����}
               inc(c);
               while (c<=lbuff) and (buff[c]=' ') do
                  inc(c)
            End
      End
End;
{�஢�ઠ �� ������७�� ����஢}
   If k<>m then
      Begin
         writeln('����୮� �᫮ ३ᮢ ',k,' � ��室��� 䠩��!');
         halt(4)
      End;
   For k := 1 to m do
      nuse[k] := false;
   For k := 1 to m do
      if nuse[l[k]] then
         Begin
            Writeln('�������騥�� ����� ३ᮢ!');
            halt(5)
         End
      Else
         nuse[l[k]] := true;
{�஢�ઠ �� �������� ������}
   for i := 1 to n do
      for j := 1 to n do
         s[i,j] := false;
   for k := 1 to m do
      Begin
         Readln(infile,i,j);
         s[i,j] := true;
         s[j,i] := true;
         ik1[k] := i;
         ik2[k] := j
      End;
   for i := 1 to n do
      Begin
         nbi := 0;
         for j := 1 to n do
            Begin
               if s[i,j] then
                  Begin
                     inc(nbi);
                     k := 1;
                     while ((ik1[k]<>i)or(ik2[k]<>j)) and
                           ((ik1[k]<>j)or(ik2[k]<>i)) do
                        inc(k);
                     if nbi=1 then
                        gcdi := l[k]
                     else
                        gcdi := gcd(gcdi,l[k])
                  End
            End;
         if (nbi>1) and (gcdi<>1) then
            begin
               writeln('����襭�� �������� ������ � ���設� ',i);
               halt(6)
            end
      End;
   writeln('ok!');
   halt(0)
end.