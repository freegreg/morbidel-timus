{ VERIFICATION PROGRAM for "Decoding Task" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }
{$APPTYPE CONSOLE}
program DECODE_CHECK;
uses
  sysutils, testlib in '..\testlib.pas';

function GetCode(var ins: InStream): string;
var
  i: integer;
begin
  result := ins.ReadString;
  for i := 1 to length(result) do
    if ((result[i] < '0') or (result[i] > '9')) and
       ((result[i] < 'A') or (result[i] > 'F')) then
      ins.quit(_PE, 'Not a hex sequence in file');
end;

var
  souf, sans: string;

begin
  try
    sans := GetCode(ans);
    souf := GetCode(ouf);
    if not ouf.seekeof then
      Quit(_PE, 'Extra data in file');
    if souf <> sans then
      Quit(_WA, 'Wrong answer');
    Quit(_OK, 'Ok');
  except on e: Exception do
    Quit(_FAIL, e.Message);
  end;
end.
