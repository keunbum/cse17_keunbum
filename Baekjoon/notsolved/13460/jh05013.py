from collections import deque

n, m = map(int,input().split())
grid = []
redi = -1
redj = -1
bluei = -1
bluej = -1
visit = set()
for i in range(n):
    row = input()
    for j in range(m):
        if row[j] == "R": redi, redj = i, j
        if row[j] == "B": bluei, bluej = i, j
    grid.append(list(row))

def move(i, j, di, dj, redi, redj, bluei, bluej):
    while 1:
        if grid[i+di][j+dj] == "#" or \
           (i+di,j+dj) in ((redi, redj), (bluei, bluej)): return (i,j)
        if grid[i+di][j+dj] == "O": return (-1,-1)
        i+= di
        j+= dj

Q = deque()
Q.append((redi, redj, bluei, bluej))
visit.add((redi, redj, bluei, bluej))
for MOVE in range(10):
    for QLEN in range(len(Q)):
        redi, redj, bluei, bluej = Q.popleft()
        for di, dj in (-1,0), (1,0), (0,-1), (0,1):
            ri, rj = move(redi, redj, di, dj, redi, redj, bluei, bluej)
            bi, bj = move(bluei, bluej, di, dj, ri, rj, bluei, bluej)
            ri, rj = move(ri, rj, di, dj, ri, rj, bi, bj)
            if bi == -1: continue
            if ri == -1: print(MOVE+1); exit()
            if (ri,rj,bi,bj) in visit: continue
            visit.add((ri,rj,bi,bj))
            Q.append((ri,rj,bi,bj))
print(-1)