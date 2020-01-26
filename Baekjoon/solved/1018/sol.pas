{$R-,S-,Q-,I-,O+}
var
  n, m, i, j, x, y, cost, ans: longint;
  a: array[0..50, 0..50] of longint;
  ch: char;
begin
  readln(n, m);
  for i := 1 to n do
  begin
    for j := 1 to m do
    begin
      read(ch);
      if ch = 'W' then a[i, j] := 1
      else a[i, j] := 0;
    end;
    readln;
  end;
  ans := 64;
  for i := 1 to n - 7 do
    for j := 1 to m - 7 do
    begin
      cost := 0;
      for x := 0 to 7 do
        for y := 0 to 7 do
        begin
          if ((x + y + a[i + x, j + y]) and 1) = 1 then inc(cost);
        end;
      if cost > 32 then cost := 64 - cost;
      if ans > cost then ans := cost;
    end;
  writeln(ans);
end.
