{$R-,S-,Q-,I-,O+}
var
  i, x, ans: longint;
  cnt: array[0..41] of longint;
begin
  fillchar(cnt, sizeof(cnt), 0);
  for i := 1 to 10 do
  begin
    read(x);
    inc(cnt[x mod 42]);
  end;
  ans := 0;
  for i := 0 to 41 do
    if cnt[i] > 0 then inc(ans);
  writeln(ans);
end.
