{$R-,S-,Q-,I-,O+}
const md = round(1e9);
var
  n, k, i, j, r: longint;
  f: array[0..200, 0..200] of int64;

begin
  read(n, k);
  for i := 1 to 200 do
  begin
    f[0, i] := 1;
    f[i, 1] := 1;
  end;
  for i := 1 to n do
    for j := 2 to k do
    begin
      for r := 0 to i do
        inc(f[i, j], f[r, j - 1]);
      f[i, j] := f[i, j] mod md;
    end;
  writeln(f[n, k]);
end.
