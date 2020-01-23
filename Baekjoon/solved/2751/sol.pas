{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const MAXN = round(1e6);
var
  i, n: longint;
  a: array[0..MAXN] of longint;

procedure swap(var a, b: longint); inline;
begin
  a := a xor b;
  b := a xor b;
  a := a xor b;
end;

function partition(l, r: longint): longint; inline;
var
  p: longint;
begin
  p := a[l + ((r - l) shr 1)];
  dec(r);
  while true do
  begin
    while a[l] < p do inc(l);
    while a[r] > p do dec(r);
    if l >= r then break;
    swap(a[l], a[r]);
    inc(l);
    dec(r);
  end;
  partition := l;
end;

procedure sort(l, r: longint);
var
  p: longint;
begin
  if l >= r - 1 then exit;
  p := partition(l, r);
  sort(l, p);
  sort(p, r);
end;

begin
  readln(n);
  for i := 1 to n do readln(a[i]);
  sort(1, n + 1);
  for i := 1 to n do writeln(a[i]);
end.
