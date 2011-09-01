{
asd
E
}
Program Divide_Sum;
{Программа находит подмножество чисел в данном n-элементном множестве,
сумма элементов в котором делится на n}
Const
   nmax = 10000;
Type
   list = array[1..nmax] of integer;
Var
   a : list; {список чисел в исходном множестве}
   r : list; {номера чисел с данным остатком}
   n : integer;
   fin : text;
   i : integer; {номер числа в исходном множестве}
   sum : longint;
   rs : integer;

Procedure outres(b : integer; e : integer);
{Вывод результата (второй проход)}
Var
   i : integer;
   fout : text;
Begin
   Assign(fout,'output.txt');
   Rewrite(fout);
   Writeln(fout,e-b+1);
   for i := b to e do
      Writeln(fout,a[i]);
   Close(fout);
   Halt(0)
End; {outres}

Begin
   Assign(fin,'input.txt');
   Reset(fin);
   Readln(fin,n);
   sum := 0;
   for i := 1 to n do
      r[i] := -1;
   for i := 1 to n do
      Begin
         readln(fin,a[i]);
         sum := sum + a[i];
         rs := sum mod n;
         if rs = 0 then
            Outres(1,i)
         else
            If r[rs] <> -1 then
               Outres(r[rs]+1,i)
            Else
               r[rs] := i
      End
End.