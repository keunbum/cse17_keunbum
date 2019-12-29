{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  i,n: int32;
  x,y,z: char;
  tree: array [0..127,0..1] of char;
  
function getc:char;
var
  ch: char;
begin
  read(ch);
  while (ch = ' ') or (ch = #10) do read(ch);
  getc:=ch;
end;

procedure dfs(v:char; order:int32);
var
  i,j: int32;
begin
  if v = '.' then exit;
  j:=0;
  for i:=0 to 2 do
  begin
    if i = order then write(v) else
    begin
      dfs(tree[ord(v)][j],order);
      inc(j);
    end;
  end;
end;

begin
  read(n);
  for i:=1 to n do
  begin
    x:=getc; y:=getc; z:=getc;
    tree[ord(x)][0]:=y;
    tree[ord(x)][1]:=z;
  end;
  for i:=0 to 2 do
  begin
    dfs('A',i);
    writeln;
  end;
end.
