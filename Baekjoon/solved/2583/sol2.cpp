#include <bits/stdc++.h>

using namespace std;

int a[123][123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  while (k--) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    for (int i = xa; i < xb; i++) {
      for (int j = ya; j < yb; j++) {
        a[i][j] = true;
      }
    }
  }
  vector<int> ans;
  function<int(int, int)> dfs = [&](int x, int y) {
    int res = 1;
    for (int i = 0; i < 4; i++) {
      int c = x + "2101"[i] - '1';
      int d = y + "1210"[i] - '1';
      if (c < 0 || c >= n || d < 0 || d >= m || a[c][d]) continue;
      a[c][d] = true;
      res += dfs(c, d);
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!a[i][j]) {
        a[i][j] = true;
        ans.push_back(dfs(i, j));
      }
    }
  }
  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << ' ';
  }
  return 0;
}