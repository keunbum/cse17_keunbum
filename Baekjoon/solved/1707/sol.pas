var
  ok: boolean;
  tt,qq,n,m,i,id,u,b,e: int32;
  c,q,last: array [0..20020] of int32;
  aa,bb,pre: array [0..400040] of int32;
begin
  read(tt);
  for qq:=1 to tt do
  begin
    read(n,m);
    for i:=1 to m do
    begin
      read(aa[i],bb[i]);
      aa[i+m]:=bb[i];
      bb[i+m]:=aa[i];
    end;
    fillchar(last,sizeof(last),0);
    for i:=1 to m+m do
    begin
      pre[i]:=last[aa[i]];
      last[aa[i]]:=i;
    end;
    fillchar(c,sizeof(c),-1);
    ok:=True;
    for i:=1 to n do
    begin
      if c[i] <> -1 then continue;
      b:=0; e:=1;
      q[0]:=i;
      c[i]:=0;
      while b < e do
      begin
        id:=last[q[b]];
        while id <> 0 do
        begin
          u:=bb[id];
          if c[u] = -1 then
          begin
            c[u]:=c[q[b]] xor 1;
            q[e]:=u;
            inc(e);
          end else
          if c[u] = c[q[b]] then
          begin
            ok:=False;
            break;
          end;
          id:=pre[id];
        end;
        if not ok then break;
        inc(b);
      end;
      if not ok then break;
    end;
    if ok then writeln('YES')
    else writeln('NO');
  end;
end.
