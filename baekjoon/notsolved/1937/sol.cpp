#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 567;

int a[N][N], dp[N][N];
vector<pair<int, int>> b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      b.emplace_back(i, j);
    }
  }
  sort(b.begin(), b.end(), [&](const auto &x, const auto &y) { return a[x.first][x.second] < a[y.first][y.second]; });
  int ans = 1;
  for (auto &t : b) {
    int x = t.first;
    int y = t.second;
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int u = x + "2101"[i] - '1';
      int v = y + "1210"[i] - '1';
      if (a[u][v] < a[x][y]) {
        dp[x][y] = max(dp[x][y], dp[u][v] + 1);
        ans = max(ans, dp[x][y]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}