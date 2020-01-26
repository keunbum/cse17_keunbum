{$R-,S-,Q-,I-,O+}
var
  tt, qq, i, ans, n: longint;
  ok: boolean;
  was: array['a'..'z'] of boolean;
  s: ansistring;
begin
  readln(tt);
  ans := 0;
  for qq := 1 to tt do
  begin
    fillchar(was, sizeof(was), false);
    readln(s);
    n := length(s);
    ok := true;
    for i := 1 to n do
    begin
      if (s[i] <> s[i - 1]) and was[s[i]] then ok := false;
      was[s[i]] := true;
    end;
    if ok then inc(ans);
  end;
  writeln(ans);
end.
