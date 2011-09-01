{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V-,X+,Y+}
{$M 16384,0,655360}

const
  digits: set of char = ['0'..'9'];
type
  tarr = array ['A'..'Z', '`'..'z'] of integer;
  parr = ^tarr;

var
  z: string;
  p: longint;

function readnum: longint;
var
  t: longint;
begin
  t := 0;
  while z[p] in digits do
  begin
    t := t * 10 + ord(z[p]) - ord('0');
    inc(p);
  end;
  readnum := t;
end;

procedure readel(var s: string);
begin
  s := z[p];
  inc(p);
  if z[p] in ['a'..'z'] then
  begin
    s := s + z[p];
    inc(p);
  end else begin
    s := s + '`';
  end;
end;

procedure add(a1, a2: parr);
var
  c, d: char;
begin
  for c := 'A' to 'Z' do
    for d := '`' to 'z' do
      a1^[c][d] := a1^[c][d] + a2^[c][d];
end;

procedure mul(a1: parr; n: longint);
var
  c, d: char;
begin
  for c := 'A' to 'Z' do
    for d := '`' to 'z' do
      a1^[c][d] := a1^[c][d] * n;
end;

function eq(a1, a2: parr): boolean;
var
  c, d: char;
begin
  eq := false;
  for c := 'A' to 'Z' do
    for d := '`' to 'z' do
      if (a1^[c][d] <> a2^[c][d]) then
      begin
		{writeln(c, d, ' ', a1^[c][d], ' ', a2^[c][d]);}
		exit;
	  end;
  eq := true;
end;

function readseq: parr;
var
  el: string[3];
  t: longint;
  a1, a2: parr;
begin
  new(a1);
  fillchar(a1^, sizeof(a1^), 0);

  while z[p] in ['A'..'Z', '('] do
  begin
    if (z[p] = '(') then
    begin
      inc(p);
      a2 := readseq;
      inc(p);
      if (z[p] in digits) then
        t := readnum
      else
        t := 1;
      mul(a2, t);
      add(a1, a2);
      dispose(a2);
    end else begin
      readel(el);
      if (z[p] in digits) then
        t := readnum
      else
        t := 1;
      a1^[el[1]][el[2]] := a1^[el[1]][el[2]] + t;
    end;
  end;
  readseq := a1;
end;

function readadd: parr;
var
  t: longint;
  a1: parr;
begin
  if z[p] in digits then
    t := readnum
  else
    t := 1;
  a1 := readseq;
  mul(a1, t);
  readadd := a1;
end;

function readformula: parr;
var
  a1, a2: parr;
begin
  a1 := readadd;
  while z[p] = '+' do
  begin
    inc(p);
    a2 := readadd;
    add(a1, a2);
    dispose(a2);
  end;
  readformula := a1;
end;

var
  a, b: parr;
  s, q: string;
  i, n: longint;

begin
  assign(input, 'chem.in');
  reset(input);
  assign(output, 'chem.out');
  rewrite(output);

  readln(s);
  z := s + '~';
  p := 1;
  a := readformula;
  readln(n);
  for i := 1 to n do
  begin
    readln(q);
    z := q + '~';
    p := 1;
    b := readformula;

    if eq(a, b) then
      writeln(s, '==', q)
    else
      writeln(s, '!=', q);

    dispose(b);
  end;

  close(input);
  close(output);
end.