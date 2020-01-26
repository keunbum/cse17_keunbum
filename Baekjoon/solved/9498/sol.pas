{$R-,S-,Q-,I-,O+}
var
  a: longint;
  ans: char;
begin
  read(a);
  ans := 'F';
  a := a div 10;
  if a > 8 then ans := 'A' else
  if a > 7 then ans := 'B' else
  if a > 6 then ans := 'C' else
  if a > 5 then ans := 'D';
  writeln(ans);
end.
