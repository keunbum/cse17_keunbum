{$R-,S-,Q-,I-,O+}
var
  n, k, i, j, w, v: longint;
  dp: array[0..100000] of longint;
begin
  fillchar(dp, sizeof(dp), 0);
  read(n, k);
  for i := 1 to n do
  begin
    read(w, v);
    for j := k downto w do
      if dp[j] < dp[j - w] + v then dp[j] := dp[j - w] + v;
  end;
  writeln(dp[k]);
end.
