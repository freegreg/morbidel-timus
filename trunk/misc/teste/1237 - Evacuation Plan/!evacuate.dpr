{ VERIFICATION PROGRAM for "Evacuation Plan" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }
{$APPTYPE CONSOLE}
program EVACUATE_CHECK;
uses
  sysutils, math, testlib in '..\testlib.pas';

const
  MAX_CAP = 1000;

type
  TArr = array of integer;
  TArr2 = array of TArr;

var
  n, m: integer;
  x, y, b, p, q, c: TArr;
  e: TArr2;
  tt: integer;

function distance(i, j: integer): integer;
begin
  distance := abs(x[i] - p[j]) + abs(y[i] - q[j]) + 1;
end;

function totaltime(e: TArr2): integer;
var
  i, j: integer;
begin
  result := 0;
  for i := 0 to n - 1 do
    for j := 0 to m - 1 do 
      inc(result, e[i][j] * distance(i, j));
end;

const
  OPTIMAL = 'OPTIMAL';
  SUBOPTIMAL = 'SUBOPTIMAL';

type
  TSolution = class
  public 
    opt: boolean;

    constructor Create(var ins: InStream);
    function ToStr: string;
  end;

constructor TSolution.Create(var ins: InStream);
var
  s: string;
  e: TArr2;
  bu, cu: TArr;
  i, j: integer;
  ttt: integer;
begin
  s := ins.ReadString;
  if s = OPTIMAL then
    opt := true
  else if s = SUBOPTIMAL then
    opt := false
  else
    ins.Quit(_PE, 'Uncecognized answer: ' + s);
  if not opt then begin
    SetLength(e, n);
    for i := 0 to n - 1 do begin
      SetLength(e[i], m);
      for j := 0 to m - 1 do 
        e[i][j] := ins.ReadInteger;
    end;
  end;
  if not ins.SeekEof then
    ins.Quit(_PE, 'Extra data in file');
  if opt then
    exit;
  // Check if capacities are in range
  for i := 0 to n - 1 do
    for j := 0 to m - 1 do
      if (e[i][j] < 0) or (e[i][j] > MAX_CAP) then
        ins.Quit(_WA, 'Plan has out of range values');
  // Compute totals and check if valid
  SetLength(bu, n);
  SetLength(cu, m);
  FillChar(bu[0], sizeof(integer)*n, 0);
  FillChar(cu[0], sizeof(integer)*m, 0);
  for i := 0 to n - 1 do
    for j := 0 to m - 1 do begin
      inc(bu[i], e[i][j]);
      inc(cu[j], e[i][j]);
    end;
  for i := 0 to n - 1 do 
    if b[i] <> bu[i] then
      ins.Quit(_WA, 'Plan is invalid - building ' + IntToStr(i + 1) + ' is not evacuated properly');
  for j := 0 to m - 1 do 
    if c[j] < cu[j] then
      ins.Quit(_WA, 'Plan is invalid - shelter ' + IntToStr(j + 1) + ' is overcrowded');
  ttt := totaltime(e);
  if ttt >= tt then
    ins.Quit(_WA, 'Proposed plan is not better: ' + IntToStr(ttt) + ' vs ' + IntToStr(tt));
end;

function TSolution.ToStr: string;
begin
  if opt then
    result := OPTIMAL
  else
    result := SUBOPTIMAL;
end;

var
  souf, sans: TSolution;
  i, j: integer;

begin
  try
    { Read input }
    n := inf.ReadInteger;
    m := inf.ReadInteger;
    SetLength(x, n);
    SetLength(y, n);
    SetLength(b, n);
    SetLength(p, m);
    SetLength(q, m);
    SetLength(c, m);
    for i := 0 to n - 1 do begin
      x[i] := inf.ReadInteger;
      y[i] := inf.ReadInteger;
      b[i] := inf.ReadInteger;
    end;
    for i := 0 to m - 1 do begin
      p[i] := inf.ReadInteger;
      q[i] := inf.ReadInteger;
      c[i] := inf.ReadInteger;
    end;
    SetLength(e, n);
    for i := 0 to n - 1 do begin
      SetLength(e[i], m);
      for j := 0 to m - 1 do
        e[i][j] := inf.ReadInteger;
    end;
    if not inf.SeekEof then
      Quit(_FAIL, 'Extra data in input file');
    tt := totaltime(e);
    { Read opt & output }
    sans := TSolution.Create(ans);
    souf := TSolution.Create(ouf);
    { Check is opt is correct }
    if souf.opt and not sans.opt then
      Quit(_WA, 'Wrong answer: ' + souf.ToStr + ' <> ' + sans.ToStr);
    if not souf.opt and sans.opt then
      Quit(_FAIL, 'Solution is better than judges could imagine');
    Quit(_OK, 'Ok');
  except on e: Exception do
    Quit(_FAIL, e.Message);
  end;
end.
