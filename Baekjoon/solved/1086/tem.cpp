#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
#define Vt vector
#define Pb push_back
#define Sz size
const int N = 1005,INF = 1<<28;

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline void swap(int &a,int &b){int tmp;tmp=a;a=b;b=tmp;}
#define MP(A,B) make_pair((A),(B))
template<class T> void getmin(T&a,T b){a>b?a=b:a;}
template<class T> void getmax(T&a,T b){a<b?a=b:a;}
int n,m;
int64 g[1<<15][101];
class WickedTeacher
{
public:
    Vt<int> f,f2;

    string cheatProbability(vector <string> num, int K)
    {
        n=num.Sz();
        f.clear();f2.clear();
        for(int i=0;i<n;i++)
        {
            int tmp = 0,t2=1;
            int k =num[i].Sz();
            for(int j=0;j<k;j++)
            {
                tmp=tmp*10+(num[i][j]-'0'),tmp%=K;
                t2=t2*10;
                t2%=K;
            }
            f.Pb(tmp);
            f2.Pb(t2);
        }
        for(int i=0;i<n;i++)
            cout<<f[i]<<' '<<f2[i]<<endl;
        memset(g,0,sizeof(g));
        g[0][0]=1;
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
                if(!(i&(1<<j)))
                {
                    for(int k=0;k<K;k++)
                    {
                        g[i|(1<<j)][(k*f2[j]+f[j])%K]+=g[i][k];
                        //cout<<i<<' '<<k<<' '<<g[i][k]<<endl;
                    }
                }
        }
        int64 a1,a2;
        a1=a2=0;
        for(int i=0;i<K;i++)
            a2+=g[(1<<n)-1][i];
        a1=g[(1<<n)-1][0];
        cout<<a1<<' '<<a2<<endl;
        int64 a3=gcd(a1,a2);
        if(a3)
        {
            a1/=a3;//cout<<n<<endl;
            a2/=a3;
        }

        string ans;
        ans.clear();
        if(a1==0)return "0/1";
        if(a2==0LL)ans+='0';
        else
            while(a2)ans+=a2%10+'0',a2/=10;

        ans+='/';
        if(a1==0LL)ans+='0';
        else
            while(a1)ans+=a1%10+'0',a1/=10;
        string res;
        int ln = ans.Sz();
        for(int i=ln-1;i>=0;i--)
            res+=ans[i];
        return res;
    }
    int64 gcd(int64 a,int64 b)
    {
        if(a==0LL)return b;
        if(b==0LL)return a;
        while(b!=0LL)
        {
            int64 c = b;
            b = a%b;
            a = c;
        }
        return a;
    }
};