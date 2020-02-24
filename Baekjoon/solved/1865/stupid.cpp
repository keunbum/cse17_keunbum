#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int T;
int main()
{
    
    scanf("%d", &T);
    while(T--)
    {
        int n, m, w;
        vector<pair<int,int> > g[501];
        queue<int> q;
        int a, b, c, i, d[501]={0};
        scanf("%d %d %d", &n, &m, &w);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &a,&b,&c);
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        for(i=0; i<w; i++)
        {
            scanf("%d %d %d", &a,&b,&c);
            g[a].push_back({b,-c});
        }
        for(i=1; i<=n; i++) d[i]=10000000;
        d[1]=0;
        q.push(1);
        while(!q.empty())
        {
            a=q.front();
            if(a==1 && d[i]<0)  break;
            q.pop();
            for(i=0; i<g[a].size(); i++)
            {
                b=g[a][i].first;
                c=g[a][i].second;
                if(d[a]+c<d[b])
                {
                    d[b]=d[a]+c;
                    q.push(b);
                }
            }
        }
        printf(q.empty()? "NO\n": "YES\n");
    }

    return 0;
}
