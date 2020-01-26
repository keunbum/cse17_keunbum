{$R-,S-,Q-,I-,O+}
var
  i, n: longint;
begin
  read(n);
  for i := 1 to 9 do
    writeln(n, ' * ', i, ' = ', n * i);
end.
