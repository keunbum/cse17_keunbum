#include <stdio.h>
#include <string.h>

#define N 567

int max(int a, int b) {
  return a > b ? a : b;
}

int a[N][N], dp[N][N];

int dfs(int x, int y) {
  if (dp[x][y]) return dp[x][y];
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int u = x + "2101"[i] - '1';
    int v = y + "1210"[i] - '1';
    if (a[u][v] > a[x][y]) {
      res = max(res, dfs(u, v));
    }
  }
  return dp[x][y] = res + 1;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", a[i] + j);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = max(ans, dfs(i, j));
    }
  }
  printf("%d\n", ans);
  return 0;
}