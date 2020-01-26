{$R-,S-,Q-,I-,O+}
var
  a, ans: longint;
begin
  read(a);
  ans := 0;
  if ((a and 3 = 0) and (a mod 100 <> 0)) or (a mod 400 = 0) then ans := 1;
  writeln(ans);
end.
