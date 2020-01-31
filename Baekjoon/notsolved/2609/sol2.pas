{$R-,S-,Q-,I-,O+}
var
  x, y, g: longint;

function gcd(a, b: longint): longint;
begin
  if b = 0 then gcd := a
  else gcd := gcd(b, a mod b);
end;

begin
  read(x, y);
  g := gcd(x, y);
  writeln(g);
  writeln(x div g * y);
end.
