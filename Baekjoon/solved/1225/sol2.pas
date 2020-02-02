{$R-,S-,Q-,I-,O+}
var
  a, b: int64;

procedure Get(var x: int64);
var
  ch: char;
begin
  x := 0;
  read(ch);
  while ch in ['0'..'9'] do
  begin
    inc(x, ord(ch) - ord('0'));
    read(ch);
  end;
end;

begin
  Get(a);
  Get(b);
  writeln(a * b);
end.
