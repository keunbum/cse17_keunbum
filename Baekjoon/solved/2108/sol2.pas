{$R-,S-,Q-,I-,O+}
var
  i, n, sum, mode, mode_cnt, sz, mx, mn, mid_i: longint;
  a: array[0..500000] of longint;
  cnt: array[0..8000] of longint;
begin
  fillchar(cnt, sizeof(cnt), 0);
  read(n);
  sum := 0;
  mx := 0;
  mn := 8000;
  for i := 1 to n do
  begin
    read(a[i]);
    inc(a[i], 4000);
    inc(sum, a[i]);
    inc(cnt[a[i]]);
    if a[i] > mx then mx := a[i];
    if a[i] < mn then mn := a[i];
  end;
  writeln(round(sum / n) - 4000);
  mid_i := (n + 1) div 2;
  for i := 0 to 8000 do
  begin
    dec(mid_i, cnt[i]);
    if mid_i <= 0 then break;
  end;
  writeln(i - 4000);
  mode := 0;
  mode_cnt := 0;
  sz := 0;
  for i := 0 to 8000 do
  begin
    if cnt[i] > mode_cnt then
    begin
      sz := 1;
      mode_cnt := cnt[i];
      mode := i
    end else
    if cnt[i] = mode_cnt then
    begin
      inc(sz);
      if sz = 2 then mode := i;
    end;
  end;
  writeln(mode - 4000);
  writeln(mx - mn);
end.
