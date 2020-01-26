{$R-,S-,Q-,I-,O+}
uses math;
var
  a, b, c, x, y, z: longint;
begin
  read(a, b, c);
  x := min(a, b);
  y := min(b, c);
  z := min(c, a);
  writeln(max(x, max(y, z)));
end.
