{$R-,S-,Q-,I-,O+}
var
  a, b, g: longint;
function gcd(a, b: longint): longint;
var
  t: longint;
begin
  while b > 0 do
  begin
    a := a mod b;
    t := a; a := b; b := t;
  end;
  gcd := a;
end;

begin
  read(a, b);
  g := gcd(a, b);
  writeln(g);
  writeln(a div g * b);
end.
