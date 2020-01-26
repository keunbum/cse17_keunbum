{$R-,S-,Q-,I-,O+}
var
  n: longint;

procedure Dfs(k, x, y: longint);
var
  z: longint;
begin
  if k = 1 then
  begin
    writeln(x, ' ', y);
    exit;
  end;
  z := 6 - x - y;
  Dfs(k - 1, x, z);
  writeln(x, ' ', y);
  Dfs(k - 1, z, y);
end;
begin
  readln(n);
  writeln((1 shl n) - 1);
  Dfs(n, 1, 3);
end.
