{$R-,S-,Q-,I-,O+}
var
  n, k, x, i, j: longint;
  dp: array[0..10000] of longint;
begin
  fillchar(dp, sizeof(dp), 0);
  dp[0] := 1;
  read(n, k);
  for i := 1 to n do
  begin
    read(x);
    for j := x to k do inc(dp[j], dp[j - x]);
  end;
  writeln(dp[k]);
end.
