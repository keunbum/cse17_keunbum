{$R-,S-,Q-,I-,O+}
var
  n, i, sum, mx, mn, mode, mode_cnt, sz: longint;
  a: array[0..500000] of longint;
  cnt: array[-4000..4000] of longint;

procedure Sort(l, r: longint);
var
  i, j, p, t: longint;
begin
  i := l;
  j := r;
  p := a[l + random(r - l + 1)];
  repeat
    while a[i] < p do inc(i);
    while p < a[j] do dec(j);
    if i <= j then
    begin
      t := a[i]; a[i] := a[j]; a[j] := t;
      inc(i);
      dec(j);
    end;
  until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
end;

begin
  fillchar(cnt, sizeof(cnt), 0);
  read(n);
  sum := 0;
  mx := -4000;
  mn := 4000;
  for i := 1 to n do
  begin
    read(a[i]);
    inc(sum, a[i]);
    inc(cnt[a[i]]);
    if a[i] > mx then mx := a[i];
    if a[i] < mn then mn := a[i];
  end;
  writeln(round(sum / n));
  Sort(1, n);
  writeln(a[(n + 1) div 2]);
  mode_cnt := 0;
  mode := 0;
  sz := 0;
  for i := -4000 to 4000 do
  begin
    if cnt[i] > mode_cnt then
    begin
      sz := 1;
      mode := i;
      mode_cnt := cnt[i];
    end else
    if cnt[i] = mode_cnt then
    begin
      inc(sz);
      if sz = 2 then mode := i;
    end;
  end;
  writeln(mode);
  writeln(mx - mn);
end.
