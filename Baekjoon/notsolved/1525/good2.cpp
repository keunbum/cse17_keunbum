#include <cstdio>
#include <map>
#include <queue>
using namespace std;

map<int,bool> vis;

int pw[9] = {1,10,100,1000,10000,100000,1000000,10000000};

struct pan{
    int a[3][3];
    void get(int** b){
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) a[i][j] = b[i][j];
    }
    void init(){
        for(int i=0; i<9; i++) a[i/3][i%3] = 0;
    }
    int to_int(){
        int ret = 0;
        for(int i=0; i<8; i++){
            ret += pw[i] * a[i/3][i%3];
        }
        return ret;
    }
    int get_zero(){
        for(int i=0; i<9; i++) if(a[i/3][i%3] == 0) return i;
        return -1;
    }
};

queue<pan> q;
queue<int> d;
int main(){
    pan p;
    pan dest;
    dest.a[0][0] = 1;
    dest.a[0][1] = 2;
    dest.a[0][2] = 3;
    dest.a[1][0] = 4;
    dest.a[1][1] = 5;
    dest.a[1][2] = 6;
    dest.a[2][0] = 7;
    dest.a[2][1] = 8;
    dest.a[2][2] = 0;
    for(int i=0; i<9; i++) scanf("%d",&p.a[i/3][i%3]);
    vis[p.to_int()] = 1;
    q.push(p);
    d.push(0);
    while (!q.empty()) {
        pan qf;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                qf.a[i][j] = q.front().a[i][j];
            }
        }
        q.pop();
        int df = d.front();
        d.pop();
        if(dest.to_int() == qf.to_int()){
            printf("%d",df);
            return 0;
        }
        int t = qf.get_zero();
        if(t%3 != 2){
            swap(qf.a[t/3][t%3],qf.a[t/3][t%3+1]);
            if(!vis[qf.to_int()]){
                vis[qf.to_int()] = 1;
                q.push(qf);
                d.push(df+1);
            }
            swap(qf.a[t/3][t%3],qf.a[t/3][t%3+1]);
        }
        if(t%3 != 0){
            swap(qf.a[t/3][t%3],qf.a[t/3][t%3-1]);
            if(!vis[qf.to_int()]){
                vis[qf.to_int()] = 1;
                q.push(qf);
                d.push(df+1);
            }
            swap(qf.a[t/3][t%3],qf.a[t/3][t%3-1]);
        }
        if(t/3 != 2){
            swap(qf.a[t/3][t%3],qf.a[t/3+1][t%3]);
            if(!vis[qf.to_int()]){
                vis[qf.to_int()] = 1;
                q.push(qf);
                d.push(df+1);
            }
            swap(qf.a[t/3][t%3],qf.a[t/3+1][t%3]);
        }
        if(t/3 != 0){
            swap(qf.a[t/3][t%3],qf.a[t/3-1][t%3]);
            if(!vis[qf.to_int()]){
                vis[qf.to_int()] = 1;
                q.push(qf);
                d.push(df+1);
            }
            swap(qf.a[t/3][t%3],qf.a[t/3-1][t%3]);
        }
    }
    puts("-1");
}
