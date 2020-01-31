{$R-,S-,Q-,I-,O+}
var
  x, i, qq, tt: longint;
  f: array[0..100] of int64;
begin
  f[0] := 0;
  f[1] := 1;
  f[2] := 1;
  f[3] := 1;
  f[4] := 2;
  for i := 5 to 100 do
  begin
    f[i] := f[i - 5] + f[i - 1];
  end;
  read(tt);
  for qq := 1 to tt do
  begin
    read(x);
    writeln(f[x]);
  end;
end.
