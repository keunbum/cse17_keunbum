#include <stdio.h>

#define N 123123

int dp[N][3], a[2][N];

inline int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int t = 0; t < 2; t++) {
      for (int i = 1; i <= n; i++) {
        scanf("%d", a[t] + i);
      }
    }
    for (int i = 0; i < n; i++) {
      dp[i + 1][0] = max(dp[i][1], dp[i][2]);
      dp[i + 1][1] = max(dp[i][0], dp[i][2]) + a[0][i + 1];
      dp[i + 1][2] = max(dp[i][0], dp[i][1]) + a[1][i + 1];
    }
    printf("%d\n", max(dp[n][1], dp[n][2]));
  }
  return 0;
}