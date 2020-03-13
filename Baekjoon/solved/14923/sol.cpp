#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  --sx; --sy; --fx; --fy;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<tuple<int, int, int>> que;
  que.emplace_back(sx, sy, 0);
  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, -1)));
  dist[sx][sy][0] = 0;
  for (int i = 0; i < (int) que.size(); i++) {
    int x, y, type;
    tie(x, y, type) = que[i];
    if (x == fx && y == fy) {
      cout << dist[x][y][type] << '\n';
      return 0;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      int ntype = type;
      if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
        if (a[nx][ny] == 1) {
          if (ntype == 1) {
            continue;
          }
          ntype = 1;
        }
        if (dist[nx][ny][ntype] == -1) {
          dist[nx][ny][ntype] = dist[x][y][type] + 1;
          que.emplace_back(nx, ny, ntype);
        }
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
