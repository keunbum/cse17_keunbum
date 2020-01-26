{$R-,S-,Q-,I-,O+}
var
  a, b: longint;
begin
  read(a, b);
  writeln(a * (b mod 10));
  writeln(a * ((b div 10) mod 10));
  writeln(a * (b div 100));
  writeln(a * b);
end.
