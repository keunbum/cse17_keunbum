{$R-,S-,Q-,I-,O+}
var
  i, n, ans: longint;

function IsHan(x: longint): boolean; inline;
var
  a, b, c: longint;
begin
  if x < 100 then begin Result := true; exit; end;
  if x = 1000 then begin IsHan := false; exit; end;
  a := x div 100;
  b := (x div 10) mod 10;
  c := x mod 10;
  IsHan := b + b = a + c;
end;
begin
  read(n);
  ans := 0;
  for i := 1 to n do
    if IsHan(i) then inc(ans);
  writeln(ans);
end.
