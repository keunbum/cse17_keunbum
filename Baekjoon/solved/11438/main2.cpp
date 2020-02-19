#include <cstdio>
#include <vector>
using namespace std;

int par[100005][17];
int dep[100005];
vector<int> graph[100005];
int n;

void dfs(int x, int pa){
    par[x][0] = pa;
    for (int i=1; i<17; i++) {
        par[x][i] = par[par[x][i-1]][i-1];
    }
    for (int i=0; i<graph[x].size(); i++) {
        if(graph[x][i] == pa) continue;
        dep[graph[x][i]] = dep[x] + 1;
        dfs(graph[x][i],x);
    }
}

int main(){
    int q;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int s,e;
        scanf("%d %d",&s,&e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    scanf("%d",&q);
    dfs(1,0);
    while (q--) {
        int x,y;
        scanf("%d %d",&x,&y);
        if(dep[x] > dep[y]) swap(x,y);
        int diff = dep[y] - dep[x];
        for (int i=0; i<17; i++) {
            if((diff>>i) & 1){
                y= par[y][i];
            }
        }
        for (int i=16; i>=0; i--) {
            if(par[x][i] != par[y][i]){
                x = par[x][i];
                y = par[y][i];
            }
        }
        if(x != y) x = par[x][0];
        printf("%d\n",x);
    }
}