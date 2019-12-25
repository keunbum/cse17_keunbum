#include <iostream>
#include <vector>

using namespace std;

const int N = 123;

struct Point {
  int x, y, z;
  Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

int to, ripe;
int a[N][N][N];
vector<Point> que;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, h;
  cin >> m >> n >> h;
  for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) a[k][i][j] = -1;
  for (int k = 1; k <= h; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int t;
        cin >> t;
        a[k][i][j] = t;
        if (t != -1) to++;
        if (t == 1) {
          ripe++;
          que.emplace_back(i, j, k);
        }
      }
    }
  }
  if (to == ripe) { cout << 0 << '\n'; return 0; }
  int ans = 1;
  for (int i = 0; i < (int) que.size(); i++) {
    Point c = que[i];
    for (int j = 0; j < 6; j++) {
      int x = c.x + "111102"[j] - '1';
      int y = c.y + "110211"[j] - '1';
      int z = c.z + "201111"[j] - '1';
      if (a[z][x][y] != 0) continue;
      ripe++;
      a[z][x][y] = a[c.z][c.x][c.y] + 1;
      ans = a[z][x][y];
      que.emplace_back(x, y, z);
    }
  }
  if (to == ripe) { cout << ans - 1 << '\n'; }
  else cout << -1 << '\n';
  return 0;
}