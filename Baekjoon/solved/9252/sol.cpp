#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

const int N = 1010;

int n, m, cnt;
int p[N * N];
int dp[N][N];
char a[N], b[N], ans[N];

inline int T(int x, int y) {
  int r = x * (m + 1) + y;
  return r;
}

void Trace(int x, int y) {
  int q = p[T(x, y)];
  int nx = q / (m + 1);
  int ny = q % (m + 1);
  if (nx >= 1 && ny >= 1) Trace(nx, ny);
  if (a[x] == b[y]) {
    cout << a[x];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> (a + 1) >> (b + 1);
  for (n = 1; a[n]; n++) ;
  for (m = 1; b[m]; m++) ;
  --n; --m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        p[T(i, j)] = T(i - 1, j - 1);
      } else
      if (dp[i][j - 1] > dp[i - 1][j]) {
        dp[i][j] = dp[i][j - 1];
        p[T(i, j)] = T(i, j - 1);
      } else {
        dp[i][j] = dp[i - 1][j];
        p[T(i, j)] = T(i - 1, j);
      }
    }
  }
  cout << dp[n][m] << '\n';
  Trace(n, m);
  cout << '\n';
  return 0;
}
