#include <stdio.h>
#include <string.h>
          
int dp[1234][1234];

inline max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  char A[1234], B[1234];
  scanf("%s %s", A, B);
  int n = strlen(A);
  int m = strlen(B);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  printf("%d\n", dp[n][m]);
  return 0;
}