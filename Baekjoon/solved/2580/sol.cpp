#include <bits/stdc++.h>

using namespace std;

int a[9][9];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<pair<int, int>> q;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        q.emplace_back(i, j);
      }
    }
  }
  function<void(int)> Dfs = [&](int d) {
    if (d == (int) q.size()) {
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (j > 0) {
            cout << ' ';
          }
          cout << a[i][j];
        }
        cout << '\n';
      }
      exit(0);
    }
    int x = q[d].first;
    int y = q[d].second;
    vector<bool> chk(10, false);
    for (int i = 0; i < 9; i++) {
      chk[a[x][i]] = true;
      chk[a[i][y]] = true;
    }
    int X = x / 3;
    int Y = y / 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        chk[a[3 * X + i][3 * Y + j]] = true;
      }
    }
    for (int i = 1; i <= 9; i++) {
      if (!chk[i]) {
        a[x][y] = i;
        Dfs(d + 1);
      }
    }
    a[x][y] = 0;
  };
  Dfs(0);
  assert(0);
  return 0;
}
