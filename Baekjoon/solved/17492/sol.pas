{$R-,S-,Q-,I-,O+}
const DX: array[0..7] of longint = (1, 1, 0, -1, -1, -1, 0, 1);
const DY: array[0..7] of longint = (0, 1, 1, 1, 0, -1, -1, -1);
var
  n, i, j, cnt: longint;
  a: array[0..10, 0..10] of longint;

procedure Dfs(cnt: longint);
var
  x, y, nx, ny, nnx, nny, dir: longint;
begin
  if cnt = 1 then
  begin
    writeln('Possible');
    halt;
  end;
  for x := 1 to n do
    for y := 1 to n do
    begin
      if a[x,y] <> 2 then continue;
      for dir := 0 to 7 do
      begin
        nx := x + DX[dir];
        ny := y + DY[dir];
        nnx := nx + DX[dir];
        nny := ny + DY[dir];
        if (a[nx,ny] <> 2) or (a[nnx,nny] <> 0) then continue;
        a[x,y] := 0;
        a[nx,ny] := 0;
        a[nnx,nny] := 2;
        Dfs(cnt - 1);
        a[nnx,nny] := 0;
        a[nx,ny] := 2;
        a[x,y] := 2; 
      end; 
    end;
end;

begin
  read(n);
  cnt := 0;
  for i := 1 to n do
    for j := 1 to n do
    begin
      read(a[i,j]);
      if a[i,j] = 2 then inc(cnt);
    end;
  Dfs(cnt);
  writeln('Impossible');
end.
