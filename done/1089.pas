(*
 *  ACM Timus Online
 *  A verification with a vocabulary -> problem 1089
 *
 *  am luat-o de pe forum...
 *)

var slovar:array[0..100] of string[8];
	k, Errors:integer;
	slovo, stroka:string;


procedure Correct;
var i, j, p:integer;
	b:char;
	WasError:boolean;
begin
	for i := 1 to k do
		for j := 1 to length(slovar[i]) do
		begin
			slovo := slovar[i];
			for b := 'a' to 'z' do
			begin
				slovo[j] := b;
				repeat
					WasError := false;
					p := pos(slovo, stroka);
					if (p > 0) and ((not(stroka[p - 1] in ['a'..'z'])) or (p = 1))
					and ((not(stroka[p + length(slovo)] in ['a'..'z']) or (p + length(slovo) = length(stroka))))
					and (slovo <> slovar[i]) then
					begin
						delete(stroka, p, length(slovo));
						insert(slovar[i], stroka, p);
						inc(errors);
						WasError := true;
					end;
				until (Not WasError);
			end;
		end;
end;


begin
	k := 0;
	repeat
		readln(slovo);
		if slovo <> '#' then
		begin
			inc(k);
			slovar[k] := slovo;
		end;
	until slovo = '#';

	Errors := 0;
	while not eof do
	begin
		readln(stroka);
		if (stroka = '') and (eof) then break;
		Correct;
		writeln(stroka);
	end;

	write(Errors);
end.
