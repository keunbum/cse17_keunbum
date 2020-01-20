{$R-,S-,Q-,I-,O+}

var
  i, n: longint;
  a, b, v: array[0..10] of longint;
  chk: array[0..10] of boolean;

procedure dfs(depth: longint);
var
  ok: boolean;
  i, j: longint;
begin
  if depth = n + 1 then
  begin
    fillchar(b, sizeof(b), 0);
    for i := 1 to n do
      for j := 1 to i - 1 do
        if v[i] < v[j] then inc(b[v[i]]);
    ok := true;
    for i := 1 to n do
      if b[i] <> a[i] then
      begin
        ok := false;
        break;
      end;
    if ok then
    begin
      for i := 1 to n - 1 do write(v[i], ' ');
      writeln(v[n]);
    end;
    exit;
  end;
  for i := 1 to n do
    if not chk[i] then
    begin
      v[depth] := i;
      chk[i] := true;
      dfs(depth + 1);
      chk[i] := false;
    end;
end;

begin
  fillchar(chk, sizeof(chk), false);
  read(n);
  for i := 1 to n do read(a[i]);
  dfs(1);
end.
