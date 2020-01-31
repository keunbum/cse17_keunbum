{$R-,S-,Q-,I-,O+}
var
  i, tt, qq, n: longint;
begin
  read(tt);
  for qq := 1 to tt do
  begin
    read(n);
    i := 1;
    while i * i <= n do inc(i);
    writeln(i - 1);
  end;
end.
