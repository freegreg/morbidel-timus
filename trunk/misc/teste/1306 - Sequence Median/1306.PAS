var n,i, j:longint;
nr:array[0..1000] of double;
f:text;

procedure quick(li,ls:longint);
var i,j:longint;
x,y:double;
begin
i:=li; j:=ls; x:=nr[(li+ls) div 2];
repeat
while nr[i]<x do i := i + 1;
while nr[j]>x do j := j - 1;
if i<=j then
begin
x:=nr[i]; nr[i]:=nr[j]; nr[j]:=x;
i := i + 1; j := j - 1;
end;
until i>j;
if li<j then quick(li, j);
if i<ls then quick(i, ls);
end;

procedure quick2(st, dr:longint);
var i, j:integer;
p, x:double;
begin
	i := st; j := dr;
	x := nr[(st + dr) shr 1];
	repeat
		while nr[i] < x do inc(i);
		while nr[j] > x do dec(j);
		if i <= j then											begin
			p := nr[i]; nr[i] := nr[j]; nr[j] := p;								inc(i); dec(j);
		end;
	until i > j;
	if st < j then quick(st, j);
	if i < dr then quick(i, dr);
end;

begin
assign(f, 'input5.txt'); reset(f);
readln(f, n);
for i:=1 to n do readln(f, nr[i]);
close(f);
quick(1,n);
quick2(1, n);

for i := 1 to n do
	for j := i + 1 to n do
	if (nr[i] > nr[j]) then
	begin
	nr[0] := nr[i];
	nr[i] := nr[j];
	nr[j] := nr[0];
	end;

if n=1 then writeln(nr[1]:0:1)
else if n mod 2<>0 then writeln(nr[n div 2+1]:0:0)
else writeln((nr[n div 2]+nr[1+n div 2]) / 2:0:1);

end.
