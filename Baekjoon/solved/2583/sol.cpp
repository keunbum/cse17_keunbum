#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>

using namespace std;

bool a[123][123];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
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
  vector<int> v;
  function<void(int, int, bool)> dfs = [&](int x, int y, bool first) {
    a[x][y] = true;
    if (first) {
      v.push_back(1);
    } else {
      v.back()++;
    }
    for (int i = 0; i < 4; i++) {
      int c = x + "2101"[i] - '1';
      int d = y + "1210"[i] - '1';
      if (c < 0 || c >= n || d < 0 || d >= m || a[c][d]) continue;
      a[c][d] = true;
      dfs(c, d, false);
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!a[i][j]) dfs(i, j, true);
    }
  }
  sort(v.begin(), v.end());
  assert(v.size());
  cout << v.size() << '\n';
  for (int x : v) {
    cout << x << ' ';
  }
  return 0;
}