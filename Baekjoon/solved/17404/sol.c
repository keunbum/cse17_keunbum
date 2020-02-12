#include <stdio.h>

#define INF 0x3f3f3f3f
#define N 1000

#define min(a, b) (a < b ? a : b)

int a[N][3];
int dp[N][3];

int main() {
  int n, i, j, t, ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) for (j = 0; j < 3; j++) scanf("%d", a[i] + j);
  ans = INF;
  for (t = 0; t < 3; t++) {
    for (i = 0; i < 3; i++) dp[0][i] = a[0][i];
    dp[0][t] = INF;
    for (i = 1; i < n; i++) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    }
    ans = min(ans, dp[n - 1][t]);
  }
  printf("%d\n", ans);
  return 0;
}