{$R-,S-,Q-,I-,O+}
var
  n, m, i, j, k, sum, ans: longint;
  a: array[0..100] of longint;
begin
  readln(n, m);
  ans := 0;
  for i := 1 to n do read(a[i]);
  for i := 1 to n do
    for j := i + 1 to n do
      for k := j + 1 to n do
      begin
        sum := a[i] + a[j] + a[k];
        if (sum <= m) and (sum > ans) then ans := sum;
      end;
  writeln(ans);
end.
