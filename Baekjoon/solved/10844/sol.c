#include <stdio.h>

#define md ((int) 1e9)

int dp[123][123];

int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < 10; i++) {
    dp[1][i] = 1;
  }
  for (int i = 2; i < n + 1; i++) {
    dp[i][0] = dp[i - 1][1];
    dp[i][9] = dp[i - 1][8];
    for (int j = 1; j < 9; j++) {
      dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j + 1]); 
    }
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    ans = add(ans, dp[n][i]);
  }
  printf("%d\n", ans);
//fprintf(stderr, "%f seconds.\n", (float)clock()/CLOCKS_PER_SEC);
  return 0;
}