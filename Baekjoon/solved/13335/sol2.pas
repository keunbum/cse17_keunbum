{$R-,S-,Q-,I-,O+}
uses math;

const inf = round(1e9);
  
var
  n,l,w,i,j: int32;
  a,sum,ans: array [0..1010] of int32;
  
begin
  read(n,l,w);
  fillchar(sum,sizeof(sum),0);
  fillchar(ans,sizeof(ans),0);
  for i:=1 to n do
  begin
    read(a[i]);
    sum[i]:=sum[i-1] + a[i];
  end;
  ans[0]:=-inf;
  for i:=2 to n do
  begin
    for j:=i-1 downto 1 do
    begin
      if sum[i] - sum[j-1] > w then break;
    end;
    ans[i]:=max(ans[i-1] + 1, ans[j] + l);
  end;
  writeln(ans[n] + l + 1);
end.
