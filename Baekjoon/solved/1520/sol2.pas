{$R-,S-,Q-,I-,O+}
const DX: array[0..3] of longint = (1, 0, -1, 0);
const DY: array[0..3] of longint = (0, 1, 0, -1);
var
  r, c, i, j: longint;
  a, dp: array[0..500, 0..500] of longint;

function rec(x, y: longint): longint;
var
  dir, px, py: longint;
begin
  if dp[x, y] >= 0 then begin rec := dp[x, y]; exit; end;
  dp[x, y] := 0;
  for dir := 0 to 3 do
  begin
    px := x + DX[dir];
    py := y + DY[dir];
    if (px < 1) or (py < 1) or (px > r) or (py > c) or (a[px, py] <= a[x, y]) then continue;
    inc(dp[x, y], rec(px, py));
  end;
  rec := dp[x, y];
end;

begin
  read(r, c);
  for i := 1 to r do
    for j := 1 to c do
      read(a[i, j]);
  fillchar(dp, sizeof(dp), -1);
  dp[1, 1] := 1;
  writeln(rec(r, c));
end.
