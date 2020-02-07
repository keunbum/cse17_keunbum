{$R-,S-,Q-,I-,O+}
var
  ok: boolean;
  n, i, t: longint;
  L, R, K, E, high: int64;
  ans: array[0..9] of int64;
begin
  read(n);
  if n < 10 then
  begin
    write(0);
    for i := 1 to 9 do
    begin
      if i <= n then t := 1
      else t := 0;
      write(' ', t);
    end;
    exit;
  end;
  fillchar(ans, sizeof(ans), 0);
  E := 10;
  ok := true;
  while ok do
  begin
    L := n div E;
    R := n mod (E div 10);
    K := (n div (E div 10)) mod 10;
    if l = 0 then ok := false;
//    writeln('E, L, R, K : ', E, ' ', L, ' ', R, ' ', K);
    for i := 0 to 9 do
    begin
      if i < K then high := L * (E div 10) + E div 10 - 1 else
      if i = K then high := L * (E div 10) + R
      else high := (L - 1) * (E div 10) + (E div 10) - 1;
      inc(ans[i], high + 1);
    end;
    dec(ans[0], E div 10);
    E := E * 10;
  end;
  write(ans[0]);
  for i := 1 to 9 do write(' ', ans[i]);
end.
