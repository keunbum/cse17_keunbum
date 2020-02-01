{$R-,S-,Q-,I-,O+}
var
  i, j, n, m, x, y, top: longint;
  a, b: ansistring;
  dp: array[0..1000, 0..1000] of longint;
  stk: array[0..1000] of char;

function max(a, b: longint): longint; inline; begin if a > b then max := a else max := b; end;

begin
  readln(a);
  readln(b);
  n := length(a);
  m := length(b);
  fillchar(dp, sizeof(dp), 0);
  for i := 1 to n do
    for j := 1 to m do
    begin
      if a[i] = b[j] then dp[i][j] := dp[i - 1][j - 1] + 1
      else dp[i][j] := max(dp[i][j - 1], dp[i - 1][j]);
    end;
  writeln(dp[n][m]);
  top := 0;
  x := n;
  y := m;
  repeat
    if a[x] = b[y] then
    begin
      inc(top);
      stk[top] := a[x];
      dec(x); dec(y);
    end else
    if dp[x][y - 1] > dp[x - 1][y] then dec(y)
    else dec(x);
  until (x < 1) or (y < 1);
  while top > 0 do
  begin
    write(stk[top]);
    dec(top);
  end;
end.
