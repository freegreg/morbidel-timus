var a:array[0..11,0..11]of byte;
		v:array[0..100]of 
		record
			x,y:byte;
		end;
		s:array[1..100]of string;
		nr,n,i,j,k,x,y:byte;
function maimic(i,j:byte):boolean;
	begin
		if v[i].x<v[j].x then
			begin
				maimic:=true;
				exit;
			end
				else
					if v[i].x=v[j].x then
						if v[i].y<v[j].y then
							begin
								maimic:=true;
								exit;
							end;
		maimic:=false;
	end;
procedure altproc;
	begin
		k:=1;
		v[k].x:=x;
		v[k].y:=y;
		nr:=1;
		for k:=1 to n do
			begin
				for j:=1 to length(s[k])-1 do
					begin
						if s[k][j]='R' then
							begin
								inc(nr);
								v[nr].x:=v[k].x+1;
								v[nr].y:=v[k].y;
							end;
						if s[k][j]='L' then
							begin
								inc(nr);
								v[nr].x:=v[k].x-1;
								v[nr].y:=v[k].y;
							end;
						if s[k][j]='T' then
							begin
								inc(nr);
								v[nr].x:=v[k].x;
								v[nr].y:=v[k].y+1;
							end;
						if s[k][j]='B' then
							begin
								inc(nr);
								v[nr].x:=v[k].x;
								v[nr].y:=v[k].y-1;
							end;
					end;
			end;
	end;
procedure proc(x,y:integer);
	begin
		inc(k);
		v[k].x:=x;
		v[k].y:=y;
		nr:=1;
		a[x,y]:=0;
		for k:=1 to n do
			begin
				if a[v[k].x,v[k].y+1]=1 then
					begin
						s[k]:=s[k]+'R';
						a[v[k].x,v[k].y+1]:=0;
						inc(nr);
						v[nr].x:=v[k].x;
						v[nr].y:=v[k].y+1;
					end;
				if a[v[k].x+1,v[k].y]=1 then
					begin
						s[k]:=s[k]+'T';
						a[v[k].x+1,v[k].y]:=0;
						inc(nr);
						v[nr].x:=v[k].x+1;
						v[nr].y:=v[k].y;
					end;
				if a[v[k].x,v[k].y-1]=1 then
					begin
						s[k]:=s[k]+'L';
						a[v[k].x,v[k].y-1]:=0;
						inc(nr);
						v[nr].x:=v[k].x;
						v[nr].y:=v[k].y-1;
					end;
				if a[v[k].x-1,v[k].y]=1 then
					begin
						s[k]:=s[k]+'B';
						a[v[k].x-1,v[k].y]:=0;
						inc(nr);
						v[nr].x:=v[k].x-1;
						v[nr].y:=v[k].y;
					end;
				s[k]:=s[k]+','
			end;
	end;
begin
	read(n);
	if eoln then
		begin
			readln;
			fillchar(a,sizeof(a),0);
			for i:=1 to n do
				begin
					readln(x,y);
					a[y,x]:=1;
				end;
			k:=0;
			for j:=1 to 10 do
				for i:=1 to 10 do
					if a[i,j]=1 then
						begin
							proc(i,j);
							x:=j;
							y:=i;
						end;
			s[n]:=copy(s[n],1,length(s[n])-1);
			s[n]:=s[n]+'.';
			writeln(x,' ',y);
			for i:=1 to n do
				begin
					writeln(s[i]);
				end;
			halt(0);
		end
			else
				begin
					x:=n;
					readln(y);
					n:=0;
					repeat
						inc(n);
						readln(s[n]);
					until s[n][length(s[n])]='.';
					altproc;
					for i:=1 to n-1 do
						for j:=i+1 to n do
							if not maimic(i,j) then
								begin
									v[0]:=v[i];
									v[i]:=v[j];
									v[j]:=v[0];
								end;
					writeln(n);
					for i:=1 to n do
						writeln(v[i].x,' ',v[i].y);

				end;
end.

