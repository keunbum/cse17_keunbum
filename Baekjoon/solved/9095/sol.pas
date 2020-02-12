{$R-,S-,Q-,I-,O+}
var
  tt, qq, q, i: longint;
  f: array[0..11] of longint;
begin
  f[0] := 1;
  f[1] := 1;
  f[2] := 2;
  for i := 3 to 11 do
    f[i] := f[i - 3] + f[i - 2] + f[i - 1];
  read(tt);
  for qq := 1 to tt do
  begin
    read(q);
    writeln(f[q]);
  end;
end.
