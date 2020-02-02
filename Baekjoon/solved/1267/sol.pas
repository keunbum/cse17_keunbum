{$R-,S-,Q-,I-,O+}
var
  suma, sumb, n, i, t, mn: longint;
begin
  suma := 0;
  sumb := 0;
  read(n);
  for i := 1 to n do
  begin
    read(t);
    inc(suma, (t div 30 + 1) * 10);
    inc(sumb, (t div 60 + 1) * 15); 
  end;
  if suma < sumb then mn := suma
  else mn := sumb;
  if suma = mn then write('Y ');
  if sumb = mn then write('M ');
  writeln(mn);
end.
