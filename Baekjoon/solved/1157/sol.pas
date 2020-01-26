{$R-,S-,Q-,I-,O+}
var
  sz: longint;
  ch, ans: char;
  cnt: array['A'..'Z'] of longint;
begin
  fillchar(cnt, sizeof(cnt), 0);
  while not eof do
  begin
    read(ch);
    if ch in ['a'..'z'] then ch := char(ord(ch) - ord('a') + ord('A'));
    inc(cnt[ch]);
  end;
  ans := 'A';
  sz := 0;
  for ch := 'A' to 'Z' do
  begin
    if cnt[ch] > cnt[ans] then
    begin
      ans := ch;
      sz := 1;
    end else
    if cnt[ch] = cnt[ans] then inc(sz);
  end;
  if sz > 1 then writeln('?')
  else writeln(ans);
end.
