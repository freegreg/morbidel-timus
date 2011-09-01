{the jury solution for trial tour problem (Questions)
 by S. Vasilyev (Stanislav.Vasilyev@usu.ru)
}
const secret_number=1999;
var
fin,fout:text;
count,last,prev,len:longint;
c:char;

begin
assign(fin,'input.txt');
reset(fin);
len:=0;
while not(eof(fin)) do {count number of characters}
begin
 while eoln(fin) and not eof(fin) do readln(fin);
 if  not(eof(fin)) then
  begin
   read(fin,c);
   inc(len);
  end;
end;

prev:=0;
for count:=1 to len do {find the number of the last deleted symbol
			using a reccurent formula}
begin
  last:= ( (secret_number + prev - 1) mod count) + 1 ;
			{last is the number of the last deleted character
			 if the length of the input string equals to count}
  prev:=last;
end;

reset(fin);
for count:=1 to last do {read the last deleted symbol}
begin
 while eoln(fin) do readln(fin);
 read(fin,c);
end;
close(fin);

assign(fout,'output.txt'); {write the answer}
rewrite(fout);
case c of
 '?':write(fout,'Yes');
 ' ':write(fout,'No');
 else write(fout,'No comments');
end;
close(fout);
end.