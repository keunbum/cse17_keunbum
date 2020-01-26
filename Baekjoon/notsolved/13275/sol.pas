{$R-,S-,Q-,I-,O+}
var
  c: char;
  t: ansistring;
  p: array[0..200010] of longint;
begin
  fillchar(p, sizeof(p), 0);
  t := '#';
  read(c);
  while c in ['a'..'z'] do
  begin
    t := t + c + '#';
    read(c);
  end;
end.
