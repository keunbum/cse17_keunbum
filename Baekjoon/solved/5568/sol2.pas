{$R-,S-,Q-,I-,O+}
const MAXN = 10 * 9 * 8 * 7;
var
  i, n, k, ans, cnt: longint;
  a: array[0..10] of longint;
  v: array[0..MAXN] of longint;
  chk: array[0..10] of boolean;

procedure Dfs(depth, value: longint);
var
  i, n_value: longint;
begin
  if depth = k + 1 then
  begin
    inc(cnt);
    v[cnt] := value;
    exit;
  end;
  for i := 1 to n do
  begin
    if chk[i] then continue;
    chk[i] := true;
    if a[i] > 9 then n_value := value * 100 + a[i]
    else n_value := value * 10 + a[i];
    Dfs(depth + 1, n_value);
    chk[i] := false;
  end;
end;

procedure Sort(l, r: longint);
var
  i, j, p, t: longint;
begin
  i := l;
  j := r;
  p := v[l + random(r - l + 1)];
  repeat
    while v[i] < p do inc(i);
    while p < v[j] do dec(j);
    if i <= j then
    begin
      t := v[i]; v[i] := v[j]; v[j] := t;
      inc(i);
      dec(j);
    end;
  until i > j;
  if l < j then sort(l, j);
  if i < r then sort(i, r);
end;

begin
  fillchar(chk, sizeof(chk), false);
  read(n, k);
  for i := 1 to n do read(a[i]);
  cnt := 0;
  Dfs(1, 0);
  Sort(1, cnt);
  ans := 0;
  for i := 1 to cnt do
    if v[i] > v[i - 1] then inc(ans);
  writeln(ans);
end.
