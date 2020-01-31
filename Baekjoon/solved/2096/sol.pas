{$R-,S-,Q-,I-,O+}
{$M 4000000}
const inf = round(1e9);
var
  n, i, j: longint;
  pmx, pmn, mx, mn: array[0..3] of longint;

function max(a, b: longint): longint; inline; begin if a > b then max := a else max := b; end;
function min(a, b: longint): longint; inline; begin if a < b then min := a else min := b; end;

procedure Update(p: longint);
var
  x, i, u, v: longint;
begin
  read(x);
  u := 0;
  v := inf;
  for i := p - 1 to p + 1 do
  begin
    if (i < 1) or (i > 3) then continue;
    u := max(u, pmx[i]);
    v := min(v, pmn[i]);
  end;
  mx[p] := x + u;
  mn[p] := x + v;
end;

begin
  for i := 1 to 3 do
  begin
    pmx[i] := 0;
    pmn[i] := 0;
  end;
  read(n);
  for i := 1 to n do
  begin
    for j := 1 to 3 do
      Update(j);
    for j := 1 to 3 do
    begin
      pmx[j] := mx[j];
      pmn[j] := mn[j];
    end;
  end;
  writeln(max(mx[1], max(mx[2], mx[3])), ' ', min(mn[1], min(mn[2], mn[3])));
end.
