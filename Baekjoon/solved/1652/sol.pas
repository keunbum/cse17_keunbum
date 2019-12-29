{$O+}
var
  ch: char;
  n,r,ans,cnt,i,j: int32;
  s: array [0..123,0..123] of char;
begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(ch);
      while not (ch in ['.','X']) do read(ch);
      s[i,j]:=ch;
    end;
  for r:=0 to 1 do
  begin
    ans:=0;
    for i:=1 to n do
    begin
      cnt:=0;
      for j:=1 to n do
      begin
        if r = 0 then ch:=s[i,j] else ch:=s[j,i];
        if ch = '.' then inc(cnt) else cnt:=0;
        if cnt = 2 then inc(ans);
      end;
    end;
    writeln(ans);
  end;
end.
