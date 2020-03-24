#include <bits/stdc++.h>

using namespace std;

inline int GetDis(int xa, int ya, int xb, int yb) {
  return abs(xa - xb) + abs(ya - yb);
}

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
  int srx = -1, sry = -1;
  int sbx = -1, sby = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != 'R' && s[i][j] != 'B') continue;
      if (s[i][j] == 'R') {
        srx = i;
        sry = j;
      }
      if (s[i][j] == 'B') {
        sbx = i;
        sby = j;
      }
      s[i][j] = '.';
    }
  }
  vector<vector<vector<pair<int, int>>>> nxt(h, vector<vector<pair<int, int>>>(w, vector<pair<int, int>>(4)));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '.') continue;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + DX[dir];
        int ny = j + DY[dir];
        while (s[nx][ny] == '.') {
          nx += DX[dir];
          ny += DY[dir];
        }
        if (s[nx][ny] == '#') {
          nx -= DX[dir];
          ny -= DY[dir];
        }
        nxt[i][j][dir] = {nx, ny};
      }
    }
  }
  vector<tuple<int, int, int, int>> que;
  que.emplace_back(srx, sry, sbx, sby);
  set<tuple<int, int, int, int>> was;
  was.emplace(srx, sry, sbx, sby);
  for (int rot = 1; rot <= 10; rot++) {
    vector<tuple<int, int, int, int>> nque;
    for (int i = 0; i < (int) que.size(); i++) {
      int rx, ry, bx, by;
      tie(rx, ry, bx, by) = que[i];
      for (int dir = 0; dir < 4; dir++) {
        int nrx, nry, nbx, nby;
        tie(nrx, nry) = nxt[rx][ry][dir];
        tie(nbx, nby) = nxt[bx][by][dir];
        if (s[nbx][nby] == 'O') continue;
        if (s[nrx][nry] == 'O') {
          cout << rot << '\n';
          return 0;
        }
        if (nrx == nbx && nry == nby) {
          nbx -= DX[dir];
          nby -= DY[dir];
          if (GetDis(nrx, nry, rx, ry) > GetDis(nrx, nry, bx, by)) {
            swap(nrx, nbx);
            swap(nry, nby);
          }
        }
        if (was.find({nrx, nry, nbx, nby}) == was.end()) {
          was.emplace(nrx, nry, nbx, nby);
          nque.emplace_back(nrx, nry, nbx, nby);
        }
      }
    }
    que = nque;
  }
  cout << -1 << '\n';
  return 0;
}
