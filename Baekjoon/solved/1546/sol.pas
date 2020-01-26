{$R-,S-,Q-,I-,O+}
uses math;
var
  n, sum, mx, i, x: longint;
  ans: double;
begin
  read(n);
  sum := 0;
  mx := 0;
  for i := 1 to n do
  begin
    read(x);
    inc(sum, x);
    mx := max(mx, x);
  end;
  ans := sum * 100 / (n * mx);
  writeln(ans : 0 : 17);
end.
