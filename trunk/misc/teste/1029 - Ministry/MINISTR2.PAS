{---
asd
B
---}
{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
type
  TBestPath = array [1..25000] of Word;

var
  i, j, n, m, x: LongInt;
  BestDirection: array [1..100, 1..500] of ShortInt;
    {  Направления лучших путей в данную комнату:
     = 0 - если дешевле прийти из комнаты снизу;
     = -1 - если дешевле прийти из комнаты слева;
     = 1 - если дешевле прийти из комнаты справа.
       Если стоимость пути до данной комнаты с каких либо направлений
     одинакова, то нам не важно откуда войти в данную комнату,
     а значение BestDirection[i,j] зависит от порядка рассмотрения маршрутов.}
  BestFloor:  array [1..500] of LongInt;
    {  Лучшая стоимость пути до данной комнаты,
     с учетом пошлины заплаченной в данной комнате.}
  CurrentFloor: array [1..500] of LongInt;
    {  Размер пошлины, взымаемой в данной комнате.}
  PBestPath: ^TBestPath;
    {  Массив для реализации стека в котором будет
     восстанавливаться оптимальный маршрут обхода кабинетов.}
  inf, outf: Text;

BEGIN
  FillChar(BestDirection, SizeOf(BestDirection), 0);
  FillChar(BestFloor, SizeOf(BestFloor), 0);
  Assign(inf, 'input.txt');
  Reset(inf);
  Readln(inf, m, n);

  {Динамически заполняем массив оптимальных путей до каждой комнаты}
  for i:=1 to m do{Для каждого этажа выполняем...}
    begin
      for j:=1 to n do
        begin
          Read(inf, CurrentFloor[j]);{Читаем величину пошлин на текущем этаже}
          Inc(BestFloor[j], CurrentFloor[j]);{"Поднимаемся" с предыдущ. этажа}
          if (BestFloor[j]>1000000000) then
            BestFloor[j] := 1000000001; {Если результат заведомо не больше,
                                         то избегаем переполнения}
        end;
      Readln(inf);

      {Ищем комнаты в которые нам дешевле прийти слева чем снизу.}
      for j:=2 to n do
        if (BestFloor[j-1]+CurrentFloor[j] < BestFloor[j]) then
          begin {Если нам дешевле войти слева...}
            BestFloor[j] := BestFloor[j-1] + CurrentFloor[j];{пересчет суммы}
            BestDirection[i,j] := -1;{отметка маршрута}
          end;

      {Ищем комнаты в которые нам дешевле прийти справа чем снизу и слева.}
      for j:=n-1 downto 1 do
        if (BestFloor[j+1]+CurrentFloor[j] < BestFloor[j]) then
          begin {Если нам дешевле войти справа...}
            BestFloor[j] := BestFloor[j+1] + CurrentFloor[j];{пересчет суммы}
            BestDirection[i,j] := 1;{отметка маршрута}
          end;
    end;
  Close(inf);

  {Находим самый дешевый путь(любой из них) приведший нас на последний этаж}
  {Находим кабинет в котором окончился самый дешевый маршрут}
  j := 1;{кабинет}
  for i:=2 to n do
    if (BestFloor[i] < BestFloor[j]) then  j := i;
  {Восстанавливаем маршрут сверху-вниз с помощью BestDirection}
  i := m;{этаж}
  x := 0;{кол-во кабинетов в стеке}
  New(PBestPath);{организуем стек}
  while (i>=1) do {пока "не вышли из здания"}
    begin
      Inc(x);
      PBestPath^[x] := j;{номер текущего кабинета в стек}
      if (BestDirection[i, j] = 0) then
        Dec(i) {спускаемся на этаж}
      else
        if (BestDirection[i, j] = -1) then
          Dec(j) {идем влево}
        else
          Inc(j); {идем вправо}
    end;

  {Выводим номера комнат из стека}
  Assign(outf, 'output.txt');
  Rewrite(outf);
  for i:=x downto 1 do
    Writeln(outf, PBestPath^[i]);
  Flush(outf);
  Close(outf);
  Dispose(PBestPath);
END.
