#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  const int inf = (int) 1e9;
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(w + 1, -1)));
  function<int(int, int, int)> Dfs = [&](int i, int j, int w) {
    if (w < 0) {
      return -inf;
    }
    if (i == n) {
      return 0;
    }
    if (dp[i][j][w] >= 0) {
      return dp[i][j][w];
    }
    return dp[i][j][w] = max(Dfs(i + 1, j, w) + (a[i] == j), Dfs(i + 1, j ^ 1, w - 1) + (a[i] == (j ^ 1)));
  };
  cout << Dfs(0, 0, w) << '\n';
  return 0;
}
