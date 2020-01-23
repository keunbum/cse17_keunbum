{$R-,S-,Q-,I-,O+}
const md = 2000007;
const len = 4;
var
  i, n, k, cnt: longint;
  a, v: array[0..10] of longint;
  chk: array[0..10] of boolean;
  ans: array[0..md] of boolean;

function hash(q: longint): longint;
var
  h: int64;
  res: longint;
begin
  h := 0;
  for i := 1 to len do h := h * 239017 + q;
  res := h mod md;
  if res < 0 then inc(res, md);
  hash := res;
end;

procedure dfs(d: longint);
var
  i, key, hh: longint;
begin
  if d = k + 1 then
  begin
    key := 0;
    for i := 1 to k do
    begin
      if (v[i] div 10) > 0 then key := key * 100 + v[i]
      else key := key * 10 + v[i];
    end;
    hh := hash(key);
//    writeln('key = ', key);
//    writeln('hh = ', hh);
    if not ans[hh] then
    begin
      inc(cnt);
      ans[hh] := true;
    end;
    exit;
  end;
  for i := 1 to n do
  begin
    if chk[i] then continue;
    chk[i] := true;
    v[d] := a[i];
    dfs(d + 1);
    chk[i] := false;
  end;
end;

begin
  fillchar(chk, sizeof(chk), false);
  fillchar(ans, sizeof(ans), false);
  read(n, k);
  for i := 1 to n do read(a[i]);
  cnt := 0;
  dfs(1);
  writeln(cnt);
end.
