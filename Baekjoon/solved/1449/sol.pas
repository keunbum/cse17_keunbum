{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  n, l, p, i, last, ans: longint;
  chk: array[0..1000] of boolean;
begin
  fillchar(chk, sizeof(chk), false);
  read(n, l);
  for i := 1 to n do
  begin
    read(p);
    chk[p] := true;
  end;
  ans := 0;
  last := -inf;
  for i := 1 to 1000 do
  begin
    if not chk[i] then continue;
    if i - last >= l then
    begin
      last := i;
      inc(ans);
    end;
  end;
  writeln(ans);
end.
