{ VERIFICATION PROGRAM for "Cricket Field" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }
{$APPTYPE CONSOLE}
program CRICKET_CHECK;
uses
  sysutils, testlib in '..\testlib.pas';

var
  n, w, h: integer;
  x, y: array of integer;

type 
  TSolution = class
  public
    p, q, l: integer;

    constructor Create(var ins: InStream);
  end;

constructor TSolution.Create(var ins: InStream);
var
  i: integer;
begin
  p := ins.ReadInteger;
  q := ins.ReadInteger;
  l := ins.ReadInteger;
  if not ins.SeekEof then
    ins.Quit(_PE, 'Extra data in file');
  if (l < 1) or (l > w) or (l > h) then 
    ins.Quit(_WA, 'L is out of range: ' + IntToStr(l));
  if (p < 0) or (p + l > w) then
    ins.Quit(_WA, 'P is out of range: ' + IntToStr(p));
  if (q < 0) or (q + l > h) then
    ins.Quit(_WA, 'Q is out of range: ' + IntToStr(q));
  for i := 0 to n - 1 do 
    if (x[i] > p) and (x[i] < p + l) and (y[i] > q) and (y[i] < q + l) then
      ins.Quit(_WA, 'Tree is inside field: ' + IntToStr(i+1));
end;

var
  souf, sans: TSolution;
  i: integer;

begin
  try
    { Read input }
    n := inf.ReadInteger;
    w := inf.ReadInteger;
    h := inf.ReadInteger;
    SetLength(x, n);
    SetLength(y, n);
    for i := 0 to n - 1 do begin
      x[i] := inf.ReadInteger;
      y[i] := inf.ReadInteger;
    end;
    if not inf.SeekEof then
      Quit(_FAIL, 'Extra data in input file');
    { Read ans & ouf }
    sans := TSolution.Create(ans);
    souf := TSolution.Create(ouf);
    { Check answer }
    if souf.l < sans.l then
      Quit(_WA, 'Wrong answer: ' + IntToStr(souf.l) + ' <> ' + IntToStr(sans.l));
    if souf.l > sans.l then
      Quit(_FAIL, 'Solution is better than judges could imagine');
    Quit(_OK, 'Ok');
  except on e: Exception do
    Quit(_FAIL, e.Message);
  end;
end.
