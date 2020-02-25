{$R-,S-,Q-,I-,O+}
var
  ok: boolean;
  ch: char;
  top: longint;
  st: array[0..123] of char;
begin
  while true do
  begin
    read(ch);
    if ch = '.' then break;
    ok := true;
    top := 0;
    while ch <> '.' do
    begin
      if (ch = '(') or (ch = '[') then
      begin
        inc(top);
        st[top] := ch;
      end else
      if ch = ')' then
      begin
        if (top = 0) or (st[top] <> '(') then ok := false
        else dec(top);
      end else
      if ch = ']' then
      begin
        if (top = 0) or (st[top] <> '[') then ok := false
        else dec(top);
      end;
      read(ch);
    end;
    if (ok) and (top = 0) then writeln('yes')
    else writeln('no');  
    readln;
  end;
end.
