{ VERIFICATION PROGRAM for "Heroes Of Might And Magic" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }
{$APPTYPE CONSOLE}
program HEROES_CHECK;
uses
  sysutils, math, testlib in '..\testlib.pas';

var
  N, HPh, MPh, HPm, Nm, V, dH: integer;
  L: array[1..10] of integer;

const
  VICTORIOUS = 'VICTORIOUS';
  DEFEATED = 'DEFEATED';
  LIGHTNING = 'L';
  TELEPORT = 'T';
  HEAL = 'H';

type
  TSolution = class
  public 
    answer: boolean;

    constructor Create(var ins: InStream);
    function ToStr: string;
  end;

constructor TSolution.Create(var ins: InStream);
var
  s: string;
  wa: boolean;
  wm: string;
  sim_hph, sim_mph, sim_h, sim_p: integer;
begin
  s := ins.ReadString;
  if s = VICTORIOUS then
    answer := true
  else if s = DEFEATED then
    answer := false
  else
    ins.Quit(_PE, 'Invalid answer: ' + s);
  wa := false; // wrong-answer flag
  if answer then begin
    // Init simulation
    sim_hph := HPh;
    sim_mph := MPh;
    sim_h := Nm * HPm;
    sim_p := N;
    // Read spells & simulate spell-casting
    while not ins.SeekEof do begin
      { Check if battle continues }
      if not wa and (sim_h <= 0) then begin
        wa := true;
        wm := 'Monsters were already defeated! No further spells shall be cast.';
      end;
      if not wa and (sim_hph <= 0) then begin
        wa := true;
        wm := 'Hero has been defeated in the battle.';
      end;
      { Read & cast spell }
      s := ins.ReadWord(blanks, blanks);
      dec(sim_mph);
      if s = LIGHTNING then begin
        dec(sim_h, L[sim_p]);
      end else if s = TELEPORT then begin
        sim_p := ins.ReadInteger;
        if (sim_p < 1) or (sim_p > N) then
          ins.Quit(_PE, 'Wrong teleport position: ' + IntToStr(sim_p));
      end else if s = HEAL then begin
        sim_hph := Min(HPh, sim_hph + dH);
      end else
        ins.Quit(_PE, 'Unknown spell: ' + s);
      { Monster's turn }
      if not wa then begin
        if sim_h <= 0 then
          continue; // Monsters are defeated -- they don't move
        sim_p := sim_p - Min(V, sim_p - 1);
        if sim_p = 1 then 
          dec(sim_hph, (sim_h + HPm - 1) div HPm);
      end;
    end;
    // Check mana
    if not wa and (sim_mph < 0) then begin
      wa := true;
      wm := 'Not enough mana = ' + IntToStr(sim_mph);
    end;
    // Check monsters
    if not wa and (sim_h > 0) then begin
      wa := true;
      wm := 'Monsters were not actually killed. Remaining hits = ' + IntToStr(sim_h);
    end;
  end;
  if not ins.SeekEof then
    ins.Quit(_PE, 'Extra data in file');
  if wa then
    ins.Quit(_WA, wm);
end;

function TSolution.ToStr: string;
begin
  if answer then
    result := VICTORIOUS
  else
    result := DEFEATED;
end;

var
  souf, sans: TSolution;
  i: integer;

begin
  try
    { Read input }
    N := inf.ReadInteger;
    HPh := inf.ReadInteger;
    MPh := inf.ReadInteger;
    HPm := inf.ReadInteger;
    Nm := inf.ReadInteger;
    V := inf.ReadInteger;
    dH := inf.ReadInteger;
    for i := 1 to N do
      L[i] := inf.ReadInteger;
    if not inf.SeekEof then
      Quit(_FAIL, 'Extra data in input file');
    { Read answer & output }
    sans := TSolution.Create(ans);
    souf := TSolution.Create(ouf);
    { Check is answer is correct }
    if not souf.answer and sans.answer then
      Quit(_WA, 'Wrong answer: ' + souf.ToStr + ' <> ' + sans.ToStr);
    if souf.answer and not sans.answer then
      Quit(_FAIL, 'Solution is better than judges could imagine');
    Quit(_OK, 'Ok');
  except on e: Exception do
    Quit(_FAIL, e.Message);
  end;
end.
