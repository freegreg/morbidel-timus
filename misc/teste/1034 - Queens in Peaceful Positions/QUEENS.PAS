 Program queens;
{Программа решает следующую задачу. В квадратной таблице n на n расставлены
n мирных ферзей. Сколько существует способов переставить ровно три ферзя так,
чтобы образовалась снова мирная позиция? }
Const
   nmax = 50; {максимальная сторона квадрата}
Type
   Position = array[1..nmax] of integer;
Var
   p : position; {Исходная позиция. Р[i] = j <==> в i-м столбце и j-й строке
	               стоит ферзь}
   pnew : position; {Позиция после перестановки ферзей}
   n : integer;          {Сторона квадрата}
   i1, i2, i3 : integer; {номера переставляемых ферзей}
   Count : longint; {Счетчик правильных позиций, получающихся после
	                  перестановки}
   tmp : integer; {Временная переменная для осуществления перестановок}
   well : boolean; {Признак того, что новая позиция мирная}

Procedure Indata;
Var
   filein : text;
   i : integer; {Номер очередного ферзя}
   r, c : integer; {Номер строки и номер колонки позиции очередного ферзя}
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
{Процедура проверяет, является ли мирной позиция, получившаяся после
перестановки трех ферзей}
Var
   i : integer; {Номер тестируемого ферзя}
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
               {Первая циклическая перестановка тройки}
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
               {Вторая циклическая перестановка тройки}
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