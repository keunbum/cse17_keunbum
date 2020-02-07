{$R-,S-,Q-,I-,O+}
var
  a, b, c, d, e, f, foo: longint;
begin
  read(a, b, c, d, e, f);
  foo := (a - c) * (f - d) - (b - d) * (e - c);
  if foo > 0 then writeln('-1') else
  if foo < 0 then writeln('1')
  else writeln('0');
end.
