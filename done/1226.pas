{ ACM Online }
{ esreveR redrO - Problem 1226 }

{ o fac in Pascal ca merg mai ushor alea cu string-uri }

const  alfa = ['A'..'Z', 'a'..'z'];

procedure flip(a:string; var b:string);
var i:integer;
begin
	b := a;
	for i := length(a) downto 1 do
		b[length(b) - i + 1] := a[i];
end;

var s, cuv:string;
	i:integer;
	iss:boolean;
begin
	while not eof do
	begin
		readln(s);
		iss := false; cuv := '';
		for i := 1 to length(s) do
			if (s[i] in alfa) then
			begin
				if (not iss) then
					iss := true;
				if (iss) then
					cuv := cuv + s[i];
				if (i = length(s)) then
				begin
					flip(cuv, cuv);
					write(cuv);
				end;
			end else
			begin
				if (iss) then
				begin
					flip(cuv, cuv);
					write(cuv);
					iss := false; cuv := '';
				end;
				write(s[i]);
			end;
		writeln;
	end;
end.