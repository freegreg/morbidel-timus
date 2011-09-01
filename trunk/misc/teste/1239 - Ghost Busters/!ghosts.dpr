{ VERIFICATION PROGRAM for "Ghost Busters" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }
{$APPTYPE CONSOLE}
program GHOSTS_CHECK;
uses
  sysutils, math, testlib in '..\testlib.pas';

const
  EPS = 1e-14;

type
  TVector = array[1..3] of extended;
  TArea = array[1..3] of TVector;
  TMinMax = record
    min: integer;
    max: integer;
  end;

  TAreaList = class
  public
    l: array of TArea;
    size: integer;

    procedure Add(const a: TArea);
    function Get: TArea;
  end;
    

  TSolution = class
  public 
    cnt: integer;
    gl: array of integer;
    gp: array of boolean;

    constructor Create(var ins: InStream);
    function CountMinMax(const area: TArea): TMinMax;
  end;

var
  n: integer;
  p: array of TVector;
  r: array of extended;

function DotProduct(const a, b: TVector): extended;
begin
  result := a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
end;

function VectorProduct(const a, b: TVector): TVector;
begin
  result[1] := a[2]*b[3] - a[3]*b[2];
  result[2] := a[3]*b[1] - a[1]*b[3];
  result[3] := a[1]*b[2] - a[2]*b[1];
end;

function SafeSqrt(x: extended): extended;
begin
  if x < 0 then
    result := 0
  else
    result := Sqrt(x);
end;

function Len(const a: TVector): extended;
begin
  result := SafeSqrt(DotProduct(a, a));
end;

function RayTg(const p: TVector; r: extended): extended; 
begin
  result := r / SafeSqrt(DotProduct(p, p) - r*r);
end;

function VectorsTg(const a, b: TVector): extended;
begin
  result := Len(VectorProduct(a, b)) / DotProduct(a, b);
end;

function SumTg(a, b: extended): extended;
begin
  result := (a + b) / (1 - a * b);
end;

function GtEq(a, b: extended): boolean;
begin
  if abs(b) < EPS then
    result := a >= b - EPS
  else if b > 0 then
    result := a / b >= 1 - EPS
  else
    result := (a > 0) or (a / b <= 1 + EPS);
end;

function Add3(const a, b, c: TVector): TVector;
begin
  result[1] := a[1] + b[1] + c[1];
  result[2] := a[2] + b[2] + c[2];
  result[3] := a[3] + b[3] + c[3];
end;

function NormCenter(const a, b: TVector): TVector;
var
  l: extended;
begin
  result[1] := a[1] + b[1];
  result[2] := a[2] + b[2];
  result[3] := a[3] + b[3];
  l := Len(result);
  result[1] := result[1] / l;
  result[2] := result[2] / l;
  result[3] := result[3] / l;
end;

procedure TAreaList.Add(const a: TArea);
begin
  if size >= length(l) then
    SetLength(l, 2*size + 16);
  l[size] := a;
  inc(size);
end;

function TAreaList.Get: TArea;
begin
  dec(size);
  result := l[size];
end;


constructor TSolution.Create(var ins: InStream);
var
  i: integer;
  a: TArea;
  v12, v13, v23: TVector;
  l: TAreaList;
  killed: boolean;

  function AddArea(const v1, v2, v3: TVector): boolean;
  var
    a: TArea;
    mm: TMinMax;
  begin
    result := false;
    a[1] := v1;
    a[2] := v2;
    a[3] := v3;
    mm := CountMinMax(a);
    if mm.max < cnt then
      exit;
    if mm.min = cnt then begin
      result := true;
      exit;
    end;
    l.Add(a);
  end;

begin
  // Read solution (check PEs)
  cnt := ins.ReadInteger;
  if (cnt < 0) or (cnt > n) then
    ins.Quit(_PE, 'Ghost count is out of range');
  SetLength(gl, cnt);
  for i := 0 to cnt - 1 do
    gl[i] := ins.ReadInteger;
  if not ins.SeekEof then
    ins.Quit(_PE, 'Extra data in file');
  // Check solution (check WAs)
  // 1: Check ghost numbers and if they repeat
  SetLength(gp, n);
  FillChar(gp[0], n*sizeof(boolean), false);
  for i := 0 to cnt - 1 do begin
    if (gl[i] < 1) or (gl[i] > n) then
      Quit(_WA, 'Ghost number is out of range');
    dec(gl[i]);
    if gp[gl[i]] then
      Quit(_WA, 'Ghost number repeats');
    gp[gl[i]] := true;
  end;
  // 2: Find area where these ghosts really intersect
  l := TAreaList.Create;
  FillChar(a, sizeof(a), 0);
  for i := 1 to 3 do
    a[i][i] := 1;
  l.Add(a);
  killed := false;
  while l.size > 0 do begin
    a := l.Get;
    v12 := NormCenter(a[1], a[2]);
    v13 := NormCenter(a[1], a[3]);
    v23 := NormCenter(a[2], a[3]);
    if AddArea(a[1], v12, v13) or 
       AddArea(a[2], v12, v23) or  
       AddArea(a[3], v13, v23) or   
       AddArea(v12, v13, v23) then begin
      killed := true;
      break;
    end;
  end;
  if not killed then
    ins.Quit(_WA, 'These ghosts cannot be killed with a single shot');
end;

function TSolution.CountMinMax(const area: TArea): TMinMax;
var
  i: integer;
  pi, c: TVector;
  ri, a1, a2, b: extended;
begin
  // Analyze area
  c := Add3(area[1], area[2], area[3]);
  a2 := VectorsTg(c, area[1]); // Tg of area angle
  // Compute min max
  result.min := 0;
  result.max := 0;
  for i := 0 to cnt - 1 do begin
    pi := p[gl[i]];
    ri := r[gl[i]];
    a1 := RayTg(pi, ri);    // Tg of ray angle
    b := VectorsTg(pi, c); // Tg of (ray,area) angle
    if GtEq(SumTg(a1, a2), b) then begin
      // Definitely intesect at least once somewhere inside
      inc(result.max, 1);
      if not GtEq(b, SumTg(a2, -a1)) then
        // Definitely intesect always 
        inc(result.min, 1);
    end;
  end;
  // If angle's too small, then consider min = max
  if a2 < EPS then
    result.min := result.max;
end;

var
  souf, sans: TSolution;
  i: integer;

begin
  try
    { Read input }
    n := inf.ReadInteger;
    SetLength(p, n);
    SetLength(r, n);
    for i := 0 to n - 1 do begin
      p[i][1] := inf.ReadInteger;
      p[i][2] := inf.ReadInteger;
      p[i][3] := inf.ReadInteger;
      r[i] := inf.ReadInteger;
    end;
    if not inf.SeekEof then
      Quit(_FAIL, 'Extra data in input file');
    { Read opt & output }
    sans := TSolution.Create(ans);
    souf := TSolution.Create(ouf);
    { Check is opt is correct }
    if souf.cnt < sans.cnt then
      Quit(_WA, 'Wrong answer: ' + IntToStr(souf.cnt) + ' <> ' + IntToStr(sans.cnt));
    if souf.cnt > sans.cnt then
      Quit(_FAIL, 'Solution is better than judges could imagine');
    Quit(_OK, 'Ok');
  except on e: Exception do
    Quit(_FAIL, e.Message);
  end;
end.
