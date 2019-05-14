#include <iostream>

using namespace std;

int n, m, x, y, d, ans = 0;
int a[55][55];

// north, east, south, west

inline int dx(int d) {
  return "0121"[d] - '1';
}
inline int dy(int d) {
  return "1210"[d] - '1';
}
inline void clean() {
  a[x][y] = 2;
  ans++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> x >> y >> d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j]; // wall -> 1, empty -> 0
    }
  }
  clean();
  while (true) {
    int i;
    for (i = 3; i >= 0; i--) {
      int td = (d + i) % 4;
      int nx = x + dx(td);
      int ny = y + dy(td);
      if (!a[nx][ny]) break;
    }
    if (i >= 0) {
      d = (d + i) % 4;
      x = x + dx(d);
      y = y + dy(d);
      clean();
      continue;
    }
    x = x - dx(d);
    y = y - dy(d);
    if (a[x][y] == 1) break;
  }
  cout << ans << '\n';
  return 0;
}                                   