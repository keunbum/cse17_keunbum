{$R-,S-,Q-,I-,O+}

var
  i, j, n, t: longint;
  ans: array[0..10] of longint;
begin
  fillchar(ans, sizeof(ans), 0);
  read(n);
  for i := 1 to n do
  begin
    read(t);
    for j := 1 to n do
    begin
      if ans[j] = 0 then
      begin
        dec(t);
        if t = -1 then
        begin
          ans[j] := i;
          break;
        end;
      end;
    end;
  end;
  for i := 1 to n - 1 do write(ans[i], ' ');
  writeln(ans[n]);
end.
