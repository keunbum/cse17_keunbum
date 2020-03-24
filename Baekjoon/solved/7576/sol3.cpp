#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  cin >> w >> h;
  vector<vector<int>> a(h, vector<int>(w));
  int cnt = 0;
  vector<pair<int, int>> que;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] != -1) {
        ++cnt;
        if (a[i][j] == 1) {
          que.emplace_back(i, j);
        }
      }
    }
  }
  int ripe = (int) que.size();
  if (ripe == cnt) {
    cout << 0 << '\n';
    return 0;
  }
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  for (int rot = 1; !que.empty(); rot++) {
    vector<pair<int, int>> nque;
    for (int i = 0; i < (int) que.size(); i++) {
      for (int dir = 0; dir < 4; dir++) {
        int nx = que[i].first + DX[dir];
        int ny = que[i].second + DY[dir];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
          if (a[nx][ny] == 0) {
            nque.emplace_back(nx, ny);
            a[nx][ny] = 1;
          }
        }
      }
    }
    ripe += (int) nque.size();
    if (ripe == cnt) {
      cout << rot << '\n';
      return 0;
    }
    que = nque;
  }
  cout << -1 << '\n';
  return 0;
}
