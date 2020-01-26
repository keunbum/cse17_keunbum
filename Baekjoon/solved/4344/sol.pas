{$R-,S-,Q-,I-,O+}
var
  qq, tt, n, sum, i, cnt: longint;
  avr: double;
  a: array[0..1000] of longint;
begin
  read(tt);
  for qq := 1 to tt do
  begin
    read(n);
    sum := 0;
    for i := 1 to n do
    begin
      read(a[i]);
      inc(sum, a[i]);
    end;
    avr := sum / n;
    cnt := 0;
    for i := 1 to n do
      if a[i] > avr then inc(cnt);
    writeln(cnt / n * 100 : 0 : 3, '%');
  end;
end.
