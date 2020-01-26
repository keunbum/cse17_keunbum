{$R-,S-,Q-,I-,O+}
var
  i, x, sum: longint;
  chk: array[0..9999] of boolean;
begin
  fillchar(chk, sizeof(chk), false);
  for i := 1 to 9999 do
  begin
    if not chk[i] then writeln(i);
    x := i;
    sum := 0;
    while x > 0 do
    begin
      inc(sum, x mod 10);
      x := x div 10;
    end;
    if sum + i < 10000 then chk[sum + i] := true;
  end;
end.
