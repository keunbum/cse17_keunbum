{$R-,S-,Q-,I-,O+}
var
  n,k,i,j,m,x,y,s: longint;
  g: array [0..444,0..444] of longint;
begin
  read(n,k);
  fillchar(g,sizeof(g),0);
  for i:=1 to k do
  begin
    read(x,y);
    g[x][y]:=1;
  end;
  for m:=1 to n do
    for i:=1 to n do
    begin
      if g[i,m] = 0 then continue;
      for j:=1 to n do
        g[i,j]:=g[i,j] or (g[i,m] and g[m,j]);
    end;
  read(s);
  for i:=1 to s do
  begin
    read(x,y);
    writeln(g[y,x] - g[x,y]);
  end;
end.
