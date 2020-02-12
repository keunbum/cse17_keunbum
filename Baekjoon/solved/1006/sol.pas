{ dp(i, j) : 1 부터 i 번째까지 j 상태로 커버하기 위해 필요한 최소 특수 부대의 수 }
{
  [state]
  0 1 2 3
  x o x o
  x x o o
} 
{$R-,S-,Q-,I-,O+}
const INF = round(1e9);
var
  flag_a, flag_b: boolean;
  qq, tt, i, j, n, w, ans, t: longint;
  a: array[0..1, 1..10000] of longint;
  dp: array[1..10000, 0..3] of longint;
  init_a: array[0..3, 0..3] of longint = (
    (0, 1, 1, 0),
    (INF, 0, INF, 1),
    (INF, INF, 0, 1),
    (INF, INF, INF, 0)
  );

function min(a, b: longint): longint; inline;
begin
  if a < b then min := a else min := b;
end;

function Solve(t: longint): longint;
var
  i: longint;
begin
  for i := 0 to 3 do dp[1][i] := init_a[t][i];
  for i := 1 to n - 1 do
  begin
    // 0
    dp[i + 1][0] := dp[i][3];
    // 1
    dp[i + 1][1] := dp[i][3] + 1;
    if a[0][i] + a[0][i + 1] <= w then dp[i + 1][1] := min(dp[i + 1][1], dp[i][2] + 1);
    // 2
    dp[i + 1][2] := dp[i][3] + 1;
    if a[1][i] + a[1][i + 1] <= w then dp[i + 1][2] := min(dp[i + 1][2], dp[i][1] + 1);
    // 3
    dp[i + 1][3] := min(dp[i + 1][1], dp[i + 1][2]) + 1;
    if a[0][i + 1] + a[1][i + 1] <= w then dp[i + 1][3] := min(dp[i + 1][3], dp[i][3] + 1);
    if (a[0][i] + a[0][i + 1] <= w) and (a[1][i] + a[1][i + 1] <= w) then dp[i + 1][3] := min(dp[i + 1][3], dp[i][0] + 2);
  end;
  // 각각의 type에 맞는 최솟값 리턴
  Solve := dp[n][3 - t];
end;

begin
  read(tt);
  for qq := 1 to tt do
  begin
    read(n, w);
    for i := 0 to 1 do for j := 1 to n do read(a[i][j]);
    if n = 1 then
    begin
      if a[0][1] + a[1][1] <= w then writeln(1) else writeln(2);
      continue;
    end;
    if a[0][1] + a[1][1] <= w then t := 1 else t := 2;
    init_a[0][3] := t;
    ans := Solve(0);
    flag_a := a[0][1] + a[0][n] <= w;
    flag_b := a[1][1] + a[1][n] <= w;
    if flag_a then ans := min(ans, Solve(1) + 1);
    if flag_b then ans := min(ans, Solve(2) + 1);
    if flag_a and flag_b then ans := min(ans, Solve(3) + 2);
    writeln(ans);
  end;
end.
