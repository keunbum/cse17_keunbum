{$R-,S-,Q-,I-,O+}
const offset = 10000;
var
  n, i, x, mid, top: longint;
  cnt: array[0..20000] of longint;
begin
  fillchar(cnt, sizeof(cnt), 0);
  read(n);
  read(mid);
  inc(cnt[mid + offset]);
  writeln(mid);
  top := 0;
  for i := 2 to n do
  begin
    read(x);
    inc(cnt[x + offset]);
    if (i and 1) = 0 then dec(top);
    if x >= mid then inc(top);
    if top >= cnt[mid + offset] then
    begin
      repeat inc(mid) until cnt[mid + offset] > 0;
      top := 0;
    end else
    if top < 0 then
    begin
      repeat dec(mid) until cnt[mid + offset] > 0;
      top := cnt[mid + offset] - 1;
    end;
    writeln(mid);
  end;
end.
