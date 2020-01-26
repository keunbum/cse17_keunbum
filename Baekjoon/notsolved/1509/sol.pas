{$R-,S-,Q-,I-,O+}
var
  c: char;
  s: ansistring;
begin
  s := '#';
  read(c);
  while c in ['A'..'Z'] do
  begin
    s := s + c + '#';
    read(c);
  end;
  write(s);
end.
