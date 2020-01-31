{$R-,S-,Q-,I-,O+}
const md = 15746;
var
  n, i: longint;
  f: array[0..1000000] of longint;
begin
  read(n);
  f[1] := 1;
  f[2] := 2;
  for i := 3 to n do
  begin
    f[i] := f[i - 1] + f[i - 2];
    if f[i] >= md then dec(f[i], md);
  end;
  writeln(f[n]);
end.
