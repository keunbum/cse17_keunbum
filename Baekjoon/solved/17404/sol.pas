{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  i, j, t, ans, n: longint;
  a, dp: array[0..1000, 0..2] of longint;

function min(a, b: longint): longint; inline;
begin
  if a < b then min := a else min := b;
end;

begin
  read(n);
  for i := 1 to n do
    for j := 0 to 2 do
      read(a[i][j]);
  ans := inf;
  for t := 0 to 2 do
  begin
    for i := 0 to 2 do dp[1][i] := a[1][i];
    dp[1][t] := inf;
    for i := 2 to n do
    begin
      dp[i][0] := min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
      dp[i][1] := min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
      dp[i][2] := min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    end;
    ans := min(ans, dp[n][t]);
  end;
  writeln(ans);
end.
