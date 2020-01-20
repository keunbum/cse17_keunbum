n=int(input())
a=list(map(int,input().split()))
d=[-1 for i in range(n)]
for i in range(n):
    for j in range(n):
        if d[j]<0:
            a[i]-=1
        if a[i]<0:
            break
    d[j]=i+1
print(' '.join(str(x) for x in d))