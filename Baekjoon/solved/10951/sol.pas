{$R-,S-,Q-,I-,O+}
var
  a, b: longint;
begin
  while not eof(input) do
  begin
    readln(a, b);
    writeln(a + b);
  end;
end.
