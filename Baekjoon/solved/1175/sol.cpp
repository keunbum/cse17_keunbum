#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9;
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int sx = -1, sy = -1;
  vector<int> fx;
  vector<int> fy;
  for (int i = 0; i < h; i++) { 
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (s[i][j] == 'C') {
        fx.push_back(i);
        fy.push_back(j);
      }
    }
  }
  auto RunBfs = [&](int sx, int sy, int sdir, vector<vector<vector<int>>>& dist) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dist[i][j][0] = -1;
        dist[i][j][1] = -1;
        dist[i][j][2] = -1;
        dist[i][j][3] = -1;
      }
    }
    vector<tuple<int, int, int>> que;
    que.emplace_back(sx, sy, sdir);
    for (int pdir = 0; pdir < 4; pdir++) {
      dist[sx][sy][pdir] = 0;
    }
    for (int i = 0; i < (int) que.size(); i++) {
      int x, y, pdir;
      tie(x, y, pdir) = que[i];
      for (int ndir = 0; ndir < 4; ndir++) {
        if (ndir == pdir) {
          continue;
        }
        int nx = x + DX[ndir];
        int ny = y + DY[ndir];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] != '#' && dist[nx][ny][ndir] == -1) {
          dist[nx][ny][ndir] = dist[x][y][pdir] + 1;
          que.emplace_back(nx, ny, ndir);
        }
      }
    }
  };
  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4)));
  RunBfs(sx, sy, -1, dist);
  vector<vector<vector<int>>> start_dist = dist;
  int ans = inf;
  for (int id = 0; id < 2; id++) {
    for (int sdir = 0; sdir < 4; sdir++) {
      if (start_dist[fx[id]][fy[id]][sdir] != -1) {
        RunBfs(fx[id], fy[id], sdir, dist);
        for (int fdir = 0; fdir < 4; fdir++) {
          if (dist[fx[id ^ 1]][fy[id ^ 1]][fdir] != -1) {
            ans = min(ans, start_dist[fx[id]][fy[id]][sdir] + dist[fx[id ^ 1]][fy[id ^ 1]][fdir]);
          }
        }
      }
    } 
  }
  cout << (ans < inf ? ans : -1) << '\n';
  return 0;
}
