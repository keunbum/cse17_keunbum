{$R-,S-,Q-,I-,O+}
var
  a, sum, i, e, foo: longint;
  s: ansistring;
begin
  readln(a);
  read(s);
  sum := 0;
  e := 1;
  for i := 3 downto 1 do
  begin
    foo := a * (ord(s[i]) - ord('0'));
    writeln(foo);
    inc(sum, foo * e);
    e := e * 10;
  end;
  writeln(sum);
end.
