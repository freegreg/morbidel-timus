{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
{#######################################################
(A)0 - Ok!
(P)1 - не создан output.txt
(P)2 - существуют пустые строки в output.txt
(P)3 - существуют ведущие нули в output.txt
(P)4 - существуют нецифровые символы в output.txt
(W)5 - несуществующий номер комнаты в output.txt
(W)6 - переход не в соседнюю комнату
(W)7 - закончили не на m-ом этаже
(W)8 - неоптимальный результат
#######################################################}
var
  i, j, n, m, x, y: LongInt;
  err: Integer;
  st: String;
  BestFloor:  array [1..500] of LongInt;
    {  Лучшая стоимость пути до данной комнаты,
     с учетом пошлины заплаченной в данной комнате.}
  CurrentFloor: array [1..500] of LongInt;
    {  Размер пошлины, взымаемой в данной комнате.}
  tstf,       {тестируемый на правильность файл-ответ}
  inf,        {входной файл жюри}
  resf: Text; {файл-пояснение с результатами проверки}
  BestSum: LongInt;   {Наилучшая конечная сумма}
  CurrentSum: LongInt;{Сумма получающаяся с помощью файла-решения}

BEGIN
  FillChar(BestFloor, SizeOf(BestFloor), 0);
  Assign(inf, 'input.txt');
  Assign(resf, 'result.txt');
  {$I-}
  Append(resf);  Close(resf);
  {$I+}
  if (IOResult <> 0) then
    Rewrite(resf)
  else
    Append(resf);
  Assign(tstf, 'output.txt');
  {$I-}
  Reset(tstf);  Close(tstf);
  {$I+}
  if (IOResult <> 0) then
    begin  {не создан output.txt}
      Writeln(resf, '(P)Error 1 - не создан output.txt');
      Writeln('(P)Error 1 - не создан output.txt');
      Flush(resf);  Close(resf);
      Halt(1);
    end;
  Reset(inf);
  Readln(inf, m, n);

  i := 0;   y := 0;
  Reset(tstf);
  while NOT EOF(tstf) do
    begin
      readln(tstf, st);
      if (length(st)=0) then
        begin  {существуют пустые строки в output.txt}
          Writeln(resf, '(P)Error 2 - существуют пустые строки в output.txt');
          Writeln('(P)Error 2 - существуют пустые строки в output.txt');
          Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
          Halt(2);
        end;
      if (st[1]='0') then
        begin  {существуют ведущие нули в output.txt}
          Writeln(resf, '(P)Error 3 - существуют ведущие нули в output.txt');
          Writeln('(P)Error 3 - существуют ведущие нули в output.txt');
          Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
          Halt(3);
        end;
      for j:=1 to length(st) do
        if NOT(st[j] in ['0'..'9']) then
          begin  {существуют нецифровые символы в output.txt}
            Writeln(resf, '(P)Error 4 - существуют нецифровые символы в output.txt');
            Writeln('(P)Error 4 - существуют нецифровые символы в output.txt');
            Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
            Halt(4);
          end;
      if (length(st)>3) then
        begin  {несуществующий номер комнаты в output.txt}
          Writeln(resf, '(W)Error 5 - несуществующий номер комнаты в output.txt');
          Writeln('(W)Error 5 - несуществующий номер комнаты в output.txt');
          Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
          Halt(5);
        end;
      val(st, x, err);
      if (x<1)OR(x>n) then
        begin  {несуществующий номер комнаты в output.txt}
          Writeln(resf, '(W)Error 5 - несуществующий номер комнаты в output.txt');
          Writeln('(W)Error 5 - несуществующий номер комнаты в output.txt');
          Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
          Halt(5);
        end;
      if (ABS(y-x)>1)AND(y<>0) then
        begin  {переход не в соседнюю комнату}
          Writeln(resf, '(W)Error 6 - переход не в соседнюю комнату');
          Writeln('(W)Error 6 - переход не в соседнюю комнату');
          Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
          Halt(6);
        end;
      if (x=y)OR(y=0) then Inc(i);
      y := x;
    end;
  if (i<>m) then
    begin  {закончили не на m-ом этаже}
      Writeln(resf, '(W)Error 7 - закончили не на m-ом этаже');
      Writeln('(W)Error 7 - закончили не на m-ом этаже');
      Flush(resf);  Close(resf);  Close(tstf);  Close(inf);
      Halt(7);
    end;
  {Динамически заполняем массив оптимальных путей до каждой комнаты}
  {Проверяем маршрут из output.txt на соответствие правилам обхода комнат}
  CurrentSum := 0; {Сумма на входе в здание}
  Reset(tstf);
  Readln(tstf, x);
  y := 0;
  for i:=1 to m do{Для каждого этажа выполняем...}
    begin
      for j:=1 to n do
        begin
          Read(inf, CurrentFloor[j]);{Читаем величину пошлин на текущем этаже}
          Inc(BestFloor[j], CurrentFloor[j]);{"Поднимаемся" с предыдущ. этажа}
        end;
      Readln(inf);

      {Ищем комнаты в которые нам дешевле прийти слева чем снизу.}
      for j:=2 to n do
        if (BestFloor[j-1]+CurrentFloor[j] < BestFloor[j]) then
          {Если нам дешевле войти слева...}
          BestFloor[j] := BestFloor[j-1] + CurrentFloor[j];{пересчет суммы}

      {Ищем комнаты в которые нам дешевле прийти справа чем снизу и слева.}
      for j:=n-1 downto 1 do
        if (BestFloor[j+1]+CurrentFloor[j] < BestFloor[j]) then
          {Если нам дешевле войти справа...}
          BestFloor[j] := BestFloor[j+1] + CurrentFloor[j];{пересчет суммы}

      {суммируем пройденные комнаты}
      Inc(CurrentSum, CurrentFloor[x]);
      while NOT EOF(tstf) do
        begin
          y := x;
          Readln(tstf, x);
          if (x=y) then
            break
          else
            Inc(CurrentSum, CurrentFloor[x]);
        end;
    end;
  Close(inf);

  {Находим стоимость самого дешевого пути приведшего нас на последний этаж}
  BestSum := BestFloor[1];
  for i:=2 to n do
    if (BestFloor[i] < BestSum) then   BestSum := BestFloor[i];
  {Проверяем оптимальность конечной суммы пошлин}
  if (BestSum<CurrentSum) then
    begin  {неоптимальный результат}
      Writeln(resf, '(W)Error 8 - неоптимальный результат ', CurrentSum,
                                 ' вместо ',BestSum);
      Writeln('(W)Error 8 - неоптимальный результат ', CurrentSum,
                                 ' вместо ',BestSum);
      Flush(resf);  Close(resf);  Close(tstf);
      Halt(8);
    end;
  Writeln(resf, '(A)0 - Ok!');
  Writeln('(A)0 - Ok!');
  Close(tstf);
  Flush(resf);
  Close(resf);
END.