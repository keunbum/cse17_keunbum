#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  auto IsIn = [&](int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < c;
  };
  vector<string> s(r);
  for (int i = 0; i < r; i++) { 
    cin >> s[i];
  }
  auto IsSym = [&](int x, int y, int n) {
    int px = x;
    int py = y;
    int qx = x + n - 1;
    int qy = y + n - 1;
    if (!IsIn(qx, qy)) {
      return false;
    }
    while (py < y + n) {
      if (s[px][py] != s[qx][qy]) {
        return false;
      }
      ++py;
      --qy;
    }
    py = y;
    qy = y + n - 1;
    while (px < x + n) {
      if (s[px][py] != s[qx][qy]) {
        return false;
      }
      ++px;
      --qx;
    }
    return true;
  };
  int ans = -1;
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int x = rot ? i - 1 : i;
        int y = rot ? j - 1 : j;
        int n = rot + 2;
        while (true) {
          if (!IsIn(x, y) || !IsSym(x, y, n)) {
            break;
          }
          ans = max(ans, n);
          --x;
          --y;
          n += 2;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}