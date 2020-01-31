{$R-,S-,Q-,I-,O+}
var
  i, j, tt, qq, n: longint;
  f, dp: array[0..100] of longint;
begin
  fillchar(f, sizeof(f), 0);
  dp[0] := 0;
  for i := 1 to 100 do
  begin
    j := i;
    repeat
      f[j] := f[j] xor 1;
      inc(j, i);
    until j > 100;
    dp[i] := dp[i - 1] + f[i];
  end;
  read(tt);
  for qq := 1 to tt do
  begin
    read(n);
    writeln(dp[n]);
  end;
end.
