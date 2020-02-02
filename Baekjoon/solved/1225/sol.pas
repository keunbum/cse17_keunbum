{$R-,S-,Q-,I-,O+}
var
  n, m, i, j: longint;
  ans: int64;
  a, b: ansistring;

procedure GetS(var s: ansistring);
var
  ch: char;
begin
  read(ch);
  s := '';
  while ch in ['0'..'9'] do
  begin
    s := s + ch;
    read(ch);
  end;
end;

function T(c: char): longint;
var
  x: longint;
begin
  x := ord('0');
  T := ord(c) - x;
end; 
  
begin
  GetS(a);
  GetS(b);
  n := length(a);
  m := length(b);
  ans := 0;
  for i := 1 to n do
    for j := 1 to m do
      inc(ans, T(a[i]) * T(b[j]));
  writeln(ans);
end.
