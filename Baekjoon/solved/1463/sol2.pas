{$R-,S-,Q-,I-,O+}
const MAX = round(1e6);
var
  n, b, e: longint;
  q, f: array[0..MAX] of longint;
begin
  fillchar(f, sizeof(f), 0);
  read(n);
  b := 1;
  e := 2;
  q[1] := 1;
  while b < e do
  begin
    if q[b] = n then break;
    if (q[b] + 1 <= MAX) and (f[q[b] + 1] = 0) then
    begin
      f[q[b] + 1] := f[q[b]] + 1;
      q[e] := q[b] + 1;
      inc(e);
    end;
    if (q[b] * 3 <= MAX) and (f[q[b] * 3] = 0) then
    begin
      f[q[b] * 3] := f[q[b]] + 1;
      q[e] := q[b] * 3;
      inc(e);
    end;
    if (q[b] shl 1 <= MAX) and (f[q[b] shl 1] = 0) then
    begin
      f[q[b] shl 1] := f[q[b]] + 1;
      q[e] := q[b] shl 1;
      inc(e);
    end;
    inc(b);
  end;
  writeln(f[n]);
end.
