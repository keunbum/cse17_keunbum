{$R-,S-,Q-,I-,O+}
var
  i,n,l,w,sum,p,b,e,ans: longint;
  a,q: array [0..1010] of longint;
begin
  read(n,l,w);
  for i:=1 to n do read(a[i]);
  b:=1; e:=1;
  sum:=0;
  p:=1;
  i:=1;
  ans:=0;
  while p <= n do
  begin
    if (b < e) and (ans - q[b] = l) then
    begin
      dec(sum,a[p]);
      inc(p);
      inc(b);
    end;
    if (i <= n) and (sum + a[i] <= w) then
    begin
      inc(sum,a[i]);
      inc(i);
      q[e]:=ans;
      inc(e);
    end;
    inc(ans);
  end;
  writeln(ans);
end.
