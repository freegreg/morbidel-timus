const
max = 3000;
del = 600;
type
long = record n,t : word; end;
var
free : array [1..max] of word;
used : array [1..max] of long;
pf,pu : array [1..max] of word;
i,lf,lu,time,num : word;
c : char;
procedure inpt;
begin
fillchar(used,sizeof(used),0);
fillchar(pu,sizeof(pu),0); lu := 0;
for i := 1 to max do
begin
free[i] := i;
pf[i] := i;
end;
lf := max;
end;
procedure up_f(x : word);
var
l,c : word;
begin
if (x div 2 > 0) and (free[x div 2] > free[x])
then l := x div 2 else l := x;
if (l <> x) then
begin
c := free[x]; free[x] := free[l]; free[l] := c;
pf[free[x]] := x; pf[free[l]] := l;
up_f(l);
end;
end;
procedure dn_f(x : word);
var
l,c : word;
begin
if (2*x <= lf) and (free[x] > free[2*x]) then l := 2*x else l := x;
if (2*x+1 <= lf) and (free[l] > free[2*x+1]) then l := 2*x+1;
if (l <> x) then
begin
c := free[x]; free[x] := free[l]; free[l] := c;
pf[free[x]] := x; pf[free[l]] := l;
dn_f(l);
end;
end;
procedure up_u(x : word);
var
l : word;
c : long;
begin
if (x div 2 > 0) and (used[x div 2].t > used[x].t)
then l := x div 2 else l := x;
if (l <> x) then
begin
c := used[x]; used[x] := used[l]; used[l] := c;
pu[used[x].n] := x; pu[used[l].n] := l;
up_u(l);
end;
end;
procedure dn_u(x : word);
var
l : word;
c : long;
begin
if (2*x <= lu) and (used[x].t > used[2*x].t) then l := 2*x else l := x;
if (2*x+1 <= lu) and (used[l].t > used[2*x+1].t) then l := 2*x+1;
if (l <> x) then
begin
c := used[x]; used[x] := used[l]; used[l] := c;
pu[used[x].n] := x; pu[used[l].n] := l;
dn_u(l);
end;
end;
procedure delfree;
begin
pf[free[1]] := 0;
free[1] := free[lf]; dec(lf);
pf[free[1]] := 1;
dn_f(1);
end;
procedure insfree(n : word);
begin
inc(lf); free[lf] := n; pf[n] := lf;
up_f(lf);
end;
procedure delused;
begin
pu[used[1].n] := 0;
used[1] := used[lu]; dec(lu);
pu[used[1].n] := 1;
dn_u(1);
end;
procedure insused(n,t : word);
begin
inc(lu); used[lu].n := n; used[lu].t := t;
pu[n] := lu; up_u(lu);
end;
procedure refresh;
begin
while (lu > 0) and (time - used[1].t >= del) do
begin
insfree(used[1].n);
delused;
end;
end;
procedure find;
begin
while not(eof) do
begin
read(time); refresh;
c := ' '; while (c = ' ') do read(c);
case c of
'+' :
begin
writeln(free[1]);
insused(free[1],time);
delfree;
end;
'.' :
begin
read(num);
if (pu[num] = 0) then writeln('-')
else
begin
writeln('+');
used[pu[num]].t := time;
dn_u(pu[num]);
end;
end;
end;
readln;
end;
end;
begin
inpt;
find;
end.