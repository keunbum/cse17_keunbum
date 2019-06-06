#include <iostream>
#include <functional>

using namespace std;

char a[23][23];
bool chk[128];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      cin >> a[i][j];
    }
  }
  function<int(int, int)> dfs = [&](int x, int y) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
      int u = x + "2101"[i] - '1';
      int v = y + "1210"[i] - '1';
      if (chk[a[u][v]] || !a[u][v]) continue;
      chk[a[u][v]] = true;
      res = max(res, dfs(u, v));
      chk[a[u][v]] = false;
    }
    return res + 1;
  };
  chk[a[1][1]] = true;
  cout << dfs(1, 1) << '\n';
  return 0;
}