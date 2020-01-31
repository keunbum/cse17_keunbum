{$R-,S-,Q-,I-,O+}
const md = 15746;
var
  n, a, b, i: longint;
begin
  read(n);
  a := 1;
  b := 2;
  for i := 3 to n do
  begin
    inc(a, b);
    if a >= md then dec(a, md);
    a := a xor b;
    b := a xor b;
    a := a xor b;
  end;
  writeln(b);
end.
