{$R-,S-,Q-,I-,O+}
var
  c: char;
  top: longint;
  s: ansistring;
  st: array[0..1000010] of char;
begin
  read(s);
  top:=0;
  for c in s do
  begin
    inc(top);
    st[top]:=c;
    if (top >= 4) and (st[top-3] = 'P') and (st[top-2] = 'P') and (st[top-1] = 'A') and (st[top] = 'P') then dec(top,3);
  end;
  if (top = 1) and (st[1] = 'P') then writeln('PPAP')
  else writeln('NP');
end.
