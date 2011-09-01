program divsumts;
{Программа проверяет правильность ответа на задачу divsum}
Const
   nmax = 10000;
Type
   list = array[1..nmax] of integer;
Var
   a : list;
   b : integer; {число из файла с результатами теста}
   n : integer; {количество чисел в исходном файле}
   k : integer; {количество чисел в файле с результатами теста}
   i : integer; {номер числа в исходном списке}
   j : integer; {номер числа в списке результата теста}
   infile : text; {файл с входными данными}
   tstfile : text; {файл с результатами тестирования}
   sum : longint;
   numexist : boolean; {признак существования числа в исходном списке}
Begin
   Writeln('Начало работы тестирующей программы');
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
         Writeln('Неверное количество чисел в результате теста');
         Halt(4)
      End;
   j := 1;
   numexist := true;
   While (j <= k) and numexist do
      Begin
         if eof(tstfile) then
            Begin
               Writeln('Неожиданный конец файла');
               Halt(3)
            End;
         Readln(tstfile,b);
         if b <= 0 then
            Begin
               Writeln('Число ',b,' отсутствует во входных данных.');
               Halt(1)
            End;
         i := 1;
         While (i <= n) and (a[i] <> b) do
            inc(i);
         if i > n then
            Begin
               Writeln('Число ',b,' отсутствует во входных данных.');
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
         Writeln('Ошибочная сумма');
         Halt(2)
      End
   Else
      Begin
         Writeln('Тест пройден успешно');
         halt(0)
      End
End.