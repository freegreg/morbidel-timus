program airtst;
{проверяющая программа для программы airprime}
Const
   nmax = 50;
   mmax = 1500;
Type
   boolrow = array[1..nmax] of boolean;
   boolmatr = array[1..nmax] of boolrow;
   boolrow1 = array[1..mmax] of boolean;
   introw = array[1..mmax] of integer;
Var
   n : integer; {количество вершин (аэропортов)}
   m : integer; {количество ребер (рейсов)}
   s : boolmatr; {матрица смежности}
   l : introw; {список предложенных номеров ребер (рейсов)}
   buff : string; {строка ответа}
   lbuff : integer; {длина строки ответа}
   c : integer; {номер символа в буфере}
   errcode : integer; {код ошибки при переводе строки в число}
   nstr : string; {номер очередного ребра в строковой форме}
   nuse : boolrow1; {признак того, что число уже занято под номер рейса}
   infile : text; {input.txt}
   outfile : text; {output.txt}
   k : integer; {номер ребра}
   i,j : integer; {номера вершин}
   nbi : integer; {количество соседей у вершины с номером i}
   ik1,ik2 : introw; {номера вершин, инцидентных ребру с номером k}
   gcdi : integer; {НОД ребер, инцидентных i-ой вершине}

function gcd(a : integer; b : integer) : integer;
{Нахождение НОД(a,b)}
var
   r : integer; {остаток}
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
{проверка первой строки}
   Readln(outfile,buff);
   If buff<>'YES' then
      begin
         writeln('неверная первая строка выходного файла!');
         halt(1)
      end;
{Разбор и простейшая проверка второй строки}
k := 0;
nstr := '';
While not eoln(outfile) do
Begin
   Read(outfile,buff);
   lbuff := length(buff);
   c := 1;
   While c <= lbuff do
      Begin
         {получение очередного номера рейса}
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
               {простейшие проверки}
               if errcode <> 0 then
                  Begin
                     Writeln('Неверный символ в выходном файле!');
                     Halt(2)
                  End;
               If (l[k]<1) or (l[k]>m) then
                  Begin
                     writeln('номер рейса вне допустимого диапазона!');
                     Halt(3)
                  End;
               {пропуск пробелов}
               inc(c);
               while (c<=lbuff) and (buff[c]=' ') do
                  inc(c)
            End
      End
End;
{Проверка на неповторение номеров}
   If k<>m then
      Begin
         writeln('Неверное число рейсов ',k,' в выходном файле!');
         halt(4)
      End;
   For k := 1 to m do
      nuse[k] := false;
   For k := 1 to m do
      if nuse[l[k]] then
         Begin
            Writeln('Повторяющиеся номера рейсов!');
            halt(5)
         End
      Else
         nuse[l[k]] := true;
{Проверка на взаимную простоту}
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
               writeln('нарушение взаимной простоты у вершины ',i);
               halt(6)
            end
      End;
   writeln('ok!');
   halt(0)
end.