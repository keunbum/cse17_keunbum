{$R-,S-,Q-,I-,O+}
var
  i, n: longint;
  f: array[0..1000000] of longint;
begin
  read(n);
  f[1] := 0;
  for i := 2 to n do
  begin
    f[i] := f[i - 1] + 1;
    if (i mod 3 = 0) and (f[i] > f[i div 3]) then f[i] := f[i div 3] + 1;
    if (i and 1 = 0) and (f[i] > f[i shr 1]) then f[i] := f[i shr 1] + 1;
  end;
  writeln(f[n]);
end.
