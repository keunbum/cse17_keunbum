{$R-,S-,Q-,I-,O+}
const DX: array[0..3] of longint = (1, 0, -1, 0);
const DY: array[0..3] of longint = (0, 1, 0, -1);
type Pair = record x, y: longint; end;
var
  i, j, k, m, n, px, py, dir: longint;
  a, dp: array[0..500, 0..500] of longint;
  q: array[0..250000] of Pair;

procedure Sort(l, r: longint);
var
  i, j, p, pp: longint;
  t: Pair;
begin
  i := l;
  j := r;
  pp := l + random(r - l + 1);
  p := a[q[pp].x, q[pp].y];
  repeat
    while a[q[i].x, q[i].y] > p do inc(i);
    while p > a[q[j].x, q[j].y] do dec(j);
    if i <= j then
    begin
      t := q[i]; q[i] := q[j]; q[j] := t;
      inc(i);
      dec(j);
    end;
  until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
end;

begin
  fillchar(a, sizeof(a), 0);
  read(m, n);
  for i := 1 to m do
    for j := 1 to n do
    begin
      read(a[i, j]);
      k := (i - 1) * n + j; 
      q[k].x := i;
      q[k].y := j;
    end;
  Sort(1, m * n);
  fillchar(dp, sizeof(dp), 0);
  dp[1, 1] := 1;
  for i := 1 to m * n do
  begin
    for dir := 0 to 3 do
    begin
      px := q[i].x + DX[dir];
      py := q[i].y + DY[dir];
      if (a[px, py] <= a[q[i].x, q[i].y]) then continue;
      inc(dp[q[i].x, q[i].y], dp[px, py]);
    end;
  end;
  writeln(dp[m][n]);
end.
