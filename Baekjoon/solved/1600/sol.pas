{$R-,S-,Q-,I-,O+}

uses math;

const inf = round(1e9);
const DX: array[0..3] of longint = (1,0,-1,0);
const DY: array[0..3] of longint = (0,1,0,-1);
const KX: array[0..7] of longint = (2,1,-1,-2,-2,-1,1,2);
const KY: array[0..7] of longint = (1,2,2,1,-1,-2,-2,-1);

var
  k,w,h,i,j,r,b,e,dir,nx,ny,ans: longint;
  qx,qy,qk: array[0..1300000] of longint;
  a: array[0..202,0..202] of longint;
  dist: array[0..202,0..202,0..30] of longint;
  
function isin(x,y: longint): boolean;
begin
  isin:=(x > 0) and (y > 0) and (x <= h) and (y <= w);
end;
begin
  read(k,w,h);
  for i:= 1 to h do
    for j:=1 to w do
    begin
      read(a[i,j]);
      for r:=0 to 30 do
      dist[i,j,r]:=inf;
    end;
  b:=0; e:= 1;
  qx[0]:=1;
  qy[0]:=1;
  qk[0]:=k;
  dist[1][1][k]:=0;
  while b < e do
  begin
    for dir:=0 to 3 do
    begin
      nx:=qx[b] + DX[dir];
      ny:=qy[b] + DY[dir];
      if isin(nx,ny) and (a[nx][ny] = 0) and (dist[nx][ny][qk[b]] = inf) then
      begin
        qx[e]:=nx;
        qy[e]:=ny;
        qk[e]:=qk[b];
        dist[nx][ny][qk[b]]:=dist[qx[b]][qy[b]][qk[b]] + 1;
        inc(e);
      end;
    end;
    if qk[b] > 0 then
      for dir:=0 to 7 do
      begin
        nx:=qx[b] + KX[dir];
        ny:=qy[b] + KY[dir];
        if isin(nx,ny) and (a[nx][ny] = 0) and (dist[nx][ny][qk[b] - 1] = inf) then
        begin
          qx[e]:=nx;
          qy[e]:=ny;
          qk[e]:=qk[b] - 1;
          dist[nx][ny][qk[b] - 1]:=dist[qx[b]][qy[b]][qk[b]] + 1;
          inc(e);
        end;        
      end;
    inc(b);
  end;
  ans:=inf;
  for i:=0 to k do ans:=min(ans,dist[h][w][i]);
  if ans = inf then ans:=-1;
  writeln(ans);
end.
