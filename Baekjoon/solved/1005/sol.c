#include <stdio.h>
#include <string.h>

#define N 1010
#define K 100010

int max(int a, int b) { return a > b ? a : b; }

int c[N];
int dp[N];
int a[K], b[K];
int last[N];
int pre[K];

int Dfs(int v) {
  if (~dp[v]) {
    return dp[v];
  }
  int res = 0;
  int id = last[v];
  while (~id) {
    int to = a[id];
    res = max(res, Dfs(to));
    id = pre[id];
  }
  return dp[v] = res + c[v];
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", c + i);
    memset(last, -1, sizeof(last));
    for (int id = 0; id < k; id++) {
      scanf("%d%d", a + id, b + id);
      --a[id]; --b[id];
      pre[id] = last[b[id]];
      last[b[id]] = id;
    }
    int w;
    scanf("%d", &w);
    --w;
    memset(dp, -1, sizeof(dp));
    printf("%d\n", Dfs(w));
  }
  return 0;
}