{$R-,S-,Q-,I-,O+}
var
  i, n, x, foo: longint;
begin
  read(n);
  for i := 1 to n do
  begin
    x := i;
    foo := x;
    repeat
      inc(foo, x mod 10);
      x := x div 10;
    until x = 0;
    if foo = n then break;
  end;
  if i = n then writeln('0') else
  writeln(i);
end.
