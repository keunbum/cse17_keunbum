#include <stdio.h>
#include <string.h>

#define N 1010

#define max(a, b) (a > b ? a : b)

char a[N], b[N];
int dp[N][N];

void Trace(int x, int y) {
  if (x < 1 || y < 1) return;
  if (a[x] == b[y]) {
    Trace(x - 1, y - 1);
    putchar(a[x]);
  } else
  if (dp[x][y - 1] > dp[x - 1][y]) Trace(x, y - 1);
  else Trace(x - 1, y);
}

int main() {
  int i, j, n, m;
  memset(dp, 0, sizeof(dp));
  scanf("%s %s", a + 1, b + 1);
  for (n = 1; a[n]; n++) ;
  for (m = 1; b[m]; m++) ;
  --n; --m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      dp[i][j] = (a[i] == b[j]) ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  printf("%d\n", dp[n][m]);
  Trace(n, m);
  return 0;
}