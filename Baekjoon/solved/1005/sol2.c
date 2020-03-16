#include <stdio.h>
#include <string.h>

#define N 1010
#define K 100010

int max(int a, int b) { return a > b ? a : b; }

int c[N];
int last[N];
int to[K];
int pre[K];
int deg[N];
int q[N];
int dp[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", c + i);
    }
    memset(last, -1, sizeof(last));
    memset(deg, 0, sizeof(deg));
    for (int id = 0; id < k; id++) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x; --y;
      ++deg[y];
      to[id] = y;
      pre[id] = last[x];
      last[x] = id;
    }
    memset(dp, 0, sizeof(dp));
    int b = 0, e = 0;
    for (int v = 0; v < n; v++) {
      if (deg[v] == 0) {
        dp[v] = c[v];
        q[e++] = v;
      }
    }
    while (b < e) {
      int id = last[q[b]];
      while (~id) {
        dp[to[id]] = max(dp[to[id]], dp[q[b]] + c[to[id]]);
        if (--deg[to[id]] == 0) {
          q[e++] = to[id];
        }
        id = pre[id];
      }
      ++b;
    }
    int w;
    scanf("%d", &w);
    --w;
    printf("%d\n", dp[w]);
  }
  return 0;
}