{$R-,S-,Q-,I-,O+}
var
  n, m, p, i, last, d, ans: longint;
  dp: array[0..40, 0..1] of longint;
begin
  readln(n);
  dp[0][0] := 0;
  dp[0][1] := 1;
  for i := 0 to n - 1 do
  begin
    dp[i + 1][0] := dp[i][0] + dp[i][1];
    dp[i + 1][1] := dp[i][0];
//    writeln(i + 1, ': ', dp[i + 1][0], ' ', dp[i + 1][1]);
  end;
  readln(m);
  last := 1;
  ans := 1;
  for i := 1 to m do
  begin
    readln(p);
    d := p - last;
    ans := ans * (dp[d][0] + dp[d][1]);
    last := p + 1;
  end;
  d := n + 1 - last;
  ans := ans * (dp[d][0] + dp[d][1]);
  writeln(ans);
end.
