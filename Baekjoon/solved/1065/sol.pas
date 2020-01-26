{$R-,S-,Q-,I-,O+}
var
  i, j, n, ans, p, x: longint;
  a: array[0..4] of longint;
  ok: boolean;
begin
  read(n);
  ans := 0;
  for i := 1 to n do
  begin
    x := i;
    p := 0;
    repeat
      inc(p);
      a[p] := x mod 10;
      x := x div 10;
    until x = 0;
    ok := true;
    for j := 2 to p - 1 do
    begin
      if a[j] shl 1 <> a[j - 1] + a[j + 1] then
      begin
        ok := false;
        break;
      end;
    end;
    if ok then inc(ans);
  end;
  writeln(ans);
end.
