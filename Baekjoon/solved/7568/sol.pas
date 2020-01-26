{$R-,S-,Q-,I-,O+}
var
  i, j, n: longint;
  ans, x, y: array[0..50] of longint;
begin
  read(n);
  for i := 1 to n do read(x[i], y[i]);
  for i := 1 to n do
  begin
    ans[i] := 1;
    for j := 1 to n do
    begin
      if i = j then continue;
      if (x[j] > x[i]) and (y[j] > y[i]) then inc(ans[i]);
    end;
  end;
  for i := 1 to n - 1 do write(ans[i], ' ');
  writeln(ans[n]);
end.
