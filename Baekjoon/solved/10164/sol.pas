{$R-,S-,Q-,I-,O+}
var
  n, m, k, x, y, i, j: longint;
  f: array[0..15, 0..15] of longint;
begin
  read(n, m, k);
  fillchar(f, sizeof(f), 0);
  f[1, 1] := 1;
  for i := 1 to n do
  begin
    for j := 1 to m do
    begin
      inc(f[i, j], f[i, j - 1] + f[i - 1, j]);
    end;
  end;
  if k = 0 then begin writeln(f[n, m]); exit; end;
  dec(k);
  x := k div m + 1;
  y := k mod m + 1;
  writeln(f[x, y] * f[n - x + 1, m - y + 1]);
end.
