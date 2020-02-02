{$R-,S-,Q-,I-,O+}
const MAX = 202;
var
  i: longint;
  c: array[0..2] of longint;
  chk: array[0..MAX * MAX] of boolean;
  ans: array[0..MAX] of boolean;

function min(a, b: longint): longint; inline; begin if a < b then min := a else min := b; end;

procedure Rec(acc: longint);
var
  i, j, k, nacc, m: longint;
  a, b: array[0..2] of longint;
begin
  if chk[acc] then exit;
  chk[acc] := true;
  a[0] := acc mod MAX;
  a[1] := acc div MAX;
  a[2] := c[2] - a[0] - a[1];
  if a[0] = 0 then ans[a[2]] := true;
  for i := 0 to 2 do
    for j := 0 to 2 do
      if i <> j then
      begin
        for k := 0 to 2 do b[k] := a[k];
        m := min(b[i], c[j] - b[j]);
        b[i] -= m;
        b[j] += m;
        nacc := b[0] + b[1] * MAX;
        Rec(nacc);
      end;

end;
begin
  for i := 0 to 2 do read(c[i]);
  fillchar(chk, sizeof(chk), false);
  fillchar(ans, sizeof(ans), false);
  Rec(0);
  for i := 0 to MAX do
    if (ans[i]) then write(i, ' ');
end.
