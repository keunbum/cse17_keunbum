{$R-,S-,Q-,I-,O+}
const DX: array[0..3] of longint = (1, 0, -1, 0);
const DY: array[0..3] of longint = (0, 1, 0, -1);
var
  i, j, n, cnt, ans: longint;
  a, grid, dist: array[0..100, 0..100] of longint;
  qx, qy: array[0..10000] of longint;

function min(a, b: longint): longint; inline; begin if a < b then min := a else min := b; end;

function IsIn(x, y: longint): boolean; inline;
begin
  IsIn := (x >= 0) and (y >= 0) and (x < n) and (y < n);
end;

procedure Dfs(x, y: longint);
var
  nx, ny, dir: longint;
begin
  for dir := 0 to 3 do
  begin
    nx := x + DX[dir];
    ny := y + DY[dir];
    if (not IsIn(nx, ny)) or (a[nx][ny] = 0) or (grid[nx][ny] > 0) then continue;
    grid[nx][ny] := grid[x][y];
    Dfs(nx, ny);
  end;
end;

function Find(sx, sy: longint): longint;
var
  i, j, b, e, nx, ny, mn, dir: longint;
begin
  for i := 0 to n - 1 do
    for j := 0 to n - 1 do
      dist[i][j] := -1;
  b := 0;
  e := 1;
  qx[0] := sx;
  qy[0] := sy;
  dist[sx][sy] := 0;
  mn := n * n;
  while b < e do
  begin
    for dir := 0 to 3 do
    begin
      nx := qx[b] + DX[dir];
      ny := qy[b] + DY[dir];
      if (not IsIn(nx, ny)) or (dist[nx][ny] <> -1) then continue;
      if a[nx][ny] = 1 then
      begin
        if grid[nx][ny] = grid[sx][sy] then continue;
        mn := dist[qx[b]][qy[b]] + 1;
        b := e;
        break;
      end;
      dist[nx][ny] := dist[qx[b]][qy[b]] + 1;
      qx[e] := nx;
      qy[e] := ny;
      inc(e);
    end;
    inc(b);
  end;
  Find := mn;
end;

begin
  fillchar(grid, sizeof(grid), 0);
  read(n);
  for i := 0 to n - 1 do
    for j := 0 to n - 1 do
    begin
      read(a[i][j]);
    end;
  cnt := 0;
  for i := 0 to n - 1 do
    for j := 0 to n - 1 do
    begin
      if (a[i][j] = 0) or (grid[i][j] > 0) then continue;
      inc(cnt);
      grid[i][j] := cnt;
      Dfs(i, j);
    end;
  ans := n * n;
  for i := 0 to n - 1 do
    for j := 0 to n - 1 do
      if a[i][j] = 1 then ans := min(ans, Find(i, j));
  writeln(ans - 1);
end.
