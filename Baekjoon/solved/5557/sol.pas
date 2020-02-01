{$R-,S-,Q-,I-,O+}
var
  i, j, n: longint;
  a: array[0..100] of longint;
  dp: array[0..100, 0..20] of int64;

function ok(x: longint): boolean; inline;
begin
  ok := (x >= 0) and (x <= 20);
end;

begin
  fillchar(dp, sizeof(dp), 0);
  read(n);
  for i := 1 to n do read(a[i]);
  dp[1, a[1]] := 1;
  for i := 2 to n - 1 do
    for j := 0 to 20 do
    begin
        if ok(j - a[i]) then inc(dp[i, j], dp[i - 1, j - a[i]]);
        if ok(j + a[i]) then inc(dp[i, j], dp[i - 1, j + a[i]]);
    end;
  writeln(dp[n - 1, a[n]]);
end.
