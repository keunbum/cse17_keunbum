{$R-,S-,Q-,I-,O+}
var
  n, m: longint;
  v: array[0..8] of longint;
  chk: array[0..8] of boolean;
procedure Dfs(d: longint);
var
  i: longint;
begin
  if d = m + 1 then
  begin
    for i := 1 to m - 1 do write(v[i], ' ');
    writeln(v[m]);
    exit;
  end;
  for i := 1 to n do
  begin
    if chk[i] then continue;
    chk[i] := true;
    v[d] := i;
    Dfs(d + 1);
    chk[i] := false;
  end;
end;

begin
  fillchar(chk, sizeof(chk), false);
  read(n, m);
  Dfs(1);
end.
