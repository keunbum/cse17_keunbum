{$R-,S-,Q-,I-,O+}
var
  i, j: longint;
  ch: char;
  cnt: array[0..127] of longint;
  ans: ansistring;

function IsPal(var t: ansistring): boolean;
var
  s, e: longint;
  ok: boolean;
begin
  s := 1;
  e := length(t);
  ok := true;
  while s < e do
  begin
    if t[s] <> t[e] then
    begin
      ok := false;
      break;
    end;
    inc(s);
    dec(e);
  end;
  IsPal := ok;
end;

begin
  fillchar(cnt, sizeof(cnt), 0);
  read(ch);
  while ch in ['A'..'Z'] do
  begin
    inc(cnt[ord(ch)]);
    read(ch);
  end;
  ans := '';
  for i := ord('A') to ord('Z') do
    for j := 1 to (cnt[i] shr 1) do
      ans := ans + chr(i);
  for i := ord('A') to ord('Z') do
    if (cnt[i] and 1) = 1 then ans := ans + chr(i);
  for i := ord('Z') downto ord('A') do
    for j := 1 to (cnt[i] shr 1) do
      ans := ans + chr(i);
  if IsPal(ans) then writeln(ans)
  else writeln('I''m Sorry Hansoo');
end.
