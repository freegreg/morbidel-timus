{ VERIFICATION PROGRAM for "Inlay Cutters" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }
{$APPTYPE CONSOLE}
program INLAY_CHECK;
uses
  sysutils, testlib in '..\testlib.pas';

var
  iouf, ians: integer;

begin
  try
    ians := ans.ReadInteger;
    iouf := ouf.ReadInteger;
    if not ouf.seekeof then
      Quit(_PE, 'Extra data in file');
    if iouf <> ians then
      Quit(_WA, 'Wrong answer: ' + IntToStr(iouf) + ' <> ' + IntToStr(ians));
    Quit(_OK, 'Ok');
  except on e: Exception do
    Quit(_FAIL, e.Message);
  end;
end.
