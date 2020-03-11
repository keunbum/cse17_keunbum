#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int sx = -1, sy = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '0') {
        sx = i;
        sy = j;
      }
    }
  }
  vector<tuple<int, int, int>> que;
  que.emplace_back(sx, sy, 0);
  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(1 << 6, -1)));
  dist[sx][sy][0] = 0;
  for (int i = 0; i < (int) que.size(); i++) {
    int x, y, bs;
    tie(x, y, bs) = que[i];
//    cerr << x << ' ' << y << ' ' << bs << '\n';
    if (s[x][y] == '1') {
      cout << dist[x][y][bs] << '\n';
      return 0;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      int nbs = bs;
      if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
        char c = s[nx][ny];
        if (c == '#') {
          continue;
        }
        if ((c >= 'A' && c <= 'F') && (bs & (1 << (int) (c - 'A'))) == 0) {
          continue;
        }
        if (c >= 'a' && c <= 'f') {
          nbs = bs | (1 << (int) (c - 'a'));
        }
        if (dist[nx][ny][nbs] == -1) {
          dist[nx][ny][nbs] = dist[x][y][bs] + 1;
          que.emplace_back(nx, ny, nbs);
        }
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
