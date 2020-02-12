#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f
#define N 16

#define min(a, b) a < b ? a : b

int cost[N][N];
int dp[N][1 << N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int t;
      scanf("%d", &t);
      if (t == 0) t = inf;
      cost[i][j] = t;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  // dp(i, j) : the cost of from i-th node to 0-th node with set j.
  dp[0][1] = 0;
  for (int t = 1; t < (1 << n); t++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][t] == inf) continue;
      for (int j = 0; j < n; j++) {
        if ((t & (1 << j)) == 0) {
          dp[j][t | (1 << j)] = min(dp[j][t | (1 << j)], cost[j][i] + dp[i][t]);
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < n; i++) {
    ans = min(ans, dp[i][(1 << n) - 1] + cost[0][i]);
  }
  printf("%d\n", ans); 
  return 0;
}