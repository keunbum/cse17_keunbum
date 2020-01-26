{$R-,S-,Q-,I-,O+}
var
  i, x, n: longint;
begin
  read(x);
  i := 0;
  n := x;
  repeat
    inc(i);
    n := (n mod 10) * 10 + ((n div 10) + (n mod 10)) mod 10;
  until n = x;
  writeln(i);
end.
