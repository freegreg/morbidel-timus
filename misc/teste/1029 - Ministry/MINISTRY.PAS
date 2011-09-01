{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
type
  TBestPath = array [1..25000] of Word;
  const input = 'mini13.in';
	   output = 'mini_13.out';

var
  i, j, n, m, x: LongInt;
  BestDirection: array [1..100, 1..500] of ShortInt;

  BestFloor:  array [1..500] of LongInt;

  CurrentFloor: array [1..500] of LongInt;

  PBestPath: ^TBestPath;

  inf, outf: Text;

BEGIN
  FillChar(BestDirection, SizeOf(BestDirection), 0);
  FillChar(BestFloor, SizeOf(BestFloor), 0);
  Assign(inf, input);
  Reset(inf);
  Readln(inf, m, n);


  for i:=1 to m do
	begin
	  for j:=1 to n do
		begin
		  Read(inf, CurrentFloor[j]);{Читаем величину пошлин на текущем этаже}
		  Inc(BestFloor[j], CurrentFloor[j]);{"Поднимаемся" с предыдущ. этажа}
		  if (BestFloor[j]>1000000000) then
			BestFloor[j] := 1000000001;
		end;
	  Readln(inf);


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
  Assign(outf, output);
  Rewrite(outf);
  for i:=x downto 1 do
    Writeln(outf, PBestPath^[i]);
  Flush(outf);
  Close(outf);
  Dispose(PBestPath);
END.