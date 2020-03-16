#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int sx = -1, sy = -1;
  int fx[2] = {-1, -1}, fy[2] = {-1, -1};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (s[i][j] == 'C') {
        if (fx[0] == -1) {
          fx[0] = i;
          fy[0] = j;
        } else {
          fx[1] = i;
          fy[1] = j;
        }
      }
    }
  }
  auto IsIn = [&](int x, int y) { return x >= 0 && y >= 0 && x < h && y < w; };
  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(1 << 4, -1)));
  vector<tuple<int, int, int>> que;
  auto Push = [&](int x, int y, int was, int ndir, int d) {
    int nx = x + DX[ndir];
    int ny = y + DY[ndir];
    if (!IsIn(nx, ny) || s[nx][ny] == '#') {
      return;
    }
    int nbs = (ndir << 2) | was;
    for (int k = 0; k < 2; k++) {
      if (nx == fx[k] && ny == fy[k]) {
        nbs |= (1 << k);
        break;
      }
    }
    if (dist[nx][ny][nbs] == -1) {
      dist[nx][ny][nbs] = d;
      que.emplace_back(nx, ny, nbs);
    }
  };
  {
    for (int ndir = 0; ndir < 4; ndir++) {
      Push(sx, sy, 0, ndir, 1); 
    }        
  }
  for (int ptr = 0; ptr < (int) que.size(); ptr++) {
    int x, y, bs;
    tie(x, y, bs) = que[ptr];
    int pdir = (bs >> 2);
    int was = (bs & 3);
//    cerr << x << ' ' << y << ' ' << pdir << ' ' << was << '\n';
    if (was == 3) {
      cout << dist[x][y][bs] << '\n';
      return 0;
    }
    for (int ndir = 0; ndir < 4; ndir++) {
      if (ndir != pdir) {
        Push(x, y, was, ndir, dist[x][y][bs] + 1);
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
