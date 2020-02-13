#include <stdio.h>

#define N 10010
#define INF 0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int a[2][N];
int dp[N][4];
int init_a[4][4] = {
  { 0, 1, 1, 0},
  { INF, 0, INF, 1},
  { INF, INF, 0, 1},
  { INF, INF, INF, 0}
};

int Solve(int type, int n, int w) {
  for (int i = 0; i < 4; i++) {
    dp[0][i] = init_a[type][i];
  }
  for (int i = 0; i < n - 1; i++) {
    int flag_a = a[0][i] + a[0][i + 1] <= w;
    int flag_b = a[1][i] + a[1][i + 1] <= w;
    dp[i + 1][0] = dp[i][3];
    dp[i + 1][1] = dp[i][3] + 1;
    if (flag_a) dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
    dp[i + 1][2] = dp[i][3] + 1;
    if (flag_b) dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + 1);
    dp[i + 1][3] = min(dp[i + 1][1], dp[i + 1][2]) + 1;
    if (flag_a && flag_b) dp[i + 1][3] = min(dp[i + 1][3], dp[i][0] + 2);
    if (a[0][i + 1] + a[1][i + 1] <= w) dp[i + 1][3] = min(dp[i + 1][3], dp[i][3] + 1);
  }
  return dp[n - 1][3 - type];
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, w;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", a[i] + j);
      }
    }
    if (n == 1) { printf("%d\n", a[0][0] + a[1][0] <= w ? 1 : 2); continue; }
    init_a[0][3] = a[0][0] + a[1][0] <= w ? 1 : 2;
    int ans = Solve(0, n, w);
    int flag_a = a[0][0] + a[0][n - 1] <= w;
    int flag_b = a[1][0] + a[1][n - 1] <= w;
    if (flag_a) ans = min(ans, Solve(1, n, w) + 1);
    if (flag_b) ans = min(ans, Solve(2, n, w) + 1);
    if (flag_a && flag_b) ans = min(ans, Solve(3, n, w) + 2);
    printf("%d\n", ans);
  }
  return 0;
}