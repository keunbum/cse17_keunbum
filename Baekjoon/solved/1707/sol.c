#include <stdio.h>
#include <string.h>

#define N 20020
#define M 400040

int tt,qq,n,m,ok,b,e,id,u,i;
int last[N],c[N],q[N];
int aa[M],bb[M],pre[M];

int main()
{
  scanf("%d",&tt);
  for (qq=1; qq <= tt; qq++)
  {
    scanf("%d %d",&n,&m);
    for (i=1; i <= m; i++)
    {
      scanf("%d %d",aa+i,bb+i);
      aa[i+m]=bb[i];
      bb[i+m]=aa[i];
    }
    memset(last,0,sizeof(last));
    for (i=1; i <= m+m; i++)
    {
      pre[i]=last[aa[i]];
      last[aa[i]]=i;
    }
    ok=1;
    memset(c,-1,sizeof(c));
    for (i=1; i <= n; i++)
    {
      if (c[i] != -1) continue;
      b=0; e=1;
      q[0]=i;
      c[i]=0;
      while (b < e)
      {
        id=last[q[b]];
        while (id)
        {
          u=bb[id];
          if (c[u] == -1)
          {
            c[u]=c[q[b]] ^ 1;
            q[e]=u;
            ++e;
          } else
          if (c[u] == c[q[b]])
          {
            ok=0;
            break;
          }
          id=pre[id];
        }
        if (!ok) break;
        ++b;
      }
      if (!ok) break;
    }
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}
