{$R-,S-,Q-,I-,O+}
var
  a, b, c, ans: longint;
  x, y, z: boolean;
begin
  read(a, b, c);
  x := a > b;
  y := b > c;
  z := c > a;
  if x then
  begin
    if z then ans := a else if y then ans := b else ans := c;
  end else
  if y then
  begin
    if x then ans := b else if z then ans := c else ans := a;
  end else
  begin
    if y then ans := c else if x then ans := a else ans := b;
  end;
  writeln(ans); 
end.
