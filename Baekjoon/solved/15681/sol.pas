{$R-,S-,Q-,I-,O+}
var
  n, m, root, tt, qq, q, i: longint;
  dp, p, last: array[0..100000] of longint;
  a, b: array[0..200000] of longint;
  was: array[0..100000] of boolean;

procedure Dfs(v: longint);
var
  id: longint;
begin
  was[v] := true;
  dp[v] := 1;
  id := last[v];
  while id <> 0 do
  begin
    if not was[b[id]] then
    begin
      Dfs(b[id]);
      inc(dp[v], dp[b[id]]);
    end;
    id := p[id];
  end;
end;

begin
  read(n, root, tt);
  m := n - 1;
  fillchar(last, sizeof(last), 0);
  for i := 1 to m do
  begin
    read(a[i], b[i]);
    a[i + m] := b[i];
    b[i + m] := a[i];
    p[i] := last[a[i]];
    last[a[i]] := i;
    p[i + m] := last[b[i]];
    last[b[i]] := i + m;
  end;
  fillchar(was, sizeof(was), false);
  Dfs(root);
  for qq := 1 to tt do
  begin
    read(q);
    writeln(dp[q]);
  end;
end.
