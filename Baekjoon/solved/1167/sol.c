#include <stdio.h>
#include <string.h>

#define N 100010

#define max(a, b) (a > b ? a : b)

int to[N + N];
int cost[N + N];
int pre[N + N];
int last[N];
int max_leaf[N];
int dia[N];

void Dfs(int v, int p) {
  int id = last[v];
  max_leaf[v] = 0;
  while (~id) {
    if (to[id] != p) {
      Dfs(to[id], v);
      max_leaf[v] = max(max_leaf[v], max_leaf[to[id]] + cost[id]);
    }
    id = pre[id];
  }
  id = last[v];
  dia[v] = max_leaf[v];
  while (~id) {
    if (to[id] != p) {
      int id2 = pre[id];
      while (~id2) {
        if (to[id2] != p) {
          dia[v] = max(dia[v], max_leaf[to[id]] + max_leaf[to[id2]] + cost[id] + cost[id2]);
        }
        id2 = pre[id2];
      }
    }
    id = pre[id];
  }
}

int main() {
  memset(last, -1, sizeof(last));
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    --v;
    while (1) {
      int u;
      scanf("%d", &u);
      if (u == -1) {
        break;
      }
      --u;
      to[cnt] = u;
      scanf("%d", cost + cnt);
      pre[cnt] = last[v];
      last[v] = cnt;
      ++cnt;
    }
  }
  Dfs(0, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dia[i]);
  }
  printf("%d\n", ans); 
  return 0;
}