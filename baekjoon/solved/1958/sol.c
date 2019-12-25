#include <stdio.h>
#include <string.h>

#define L 123

int dp[L][L][L];

inline int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  char A[L], B[L], C[L];
  scanf("%s %s %s", A, B, C);
  int a = strlen(A);
  int b = strlen(B);
  int c = strlen(C);
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) { dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1; }
        else { dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i][j - 1][k], dp[i - 1][j][k])); }
      }
    }
  }
  printf("%d\n", dp[a][b][c]);
  return 0;
}