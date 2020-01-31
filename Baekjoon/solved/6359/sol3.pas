{$R-,S-,Q-,I-,O+}
uses math;
var
  i, t, n: longint;
begin
  read(t);
  for i := 1 to t do
  begin
    read(n);
    writeln(trunc(sqrt(n)));
  end;
end.
