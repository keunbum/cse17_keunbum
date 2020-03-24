#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

int ans = 11;

bool Cmp(int dir, int rx, int ry, int bx, int by) {
  if (dir == 0) return rx < bx;
  if (dir == 1) return ry < by;
  if (dir == 2) return rx > bx;
  if (dir == 3) return ry > by;
  assert(0);
  return false;
}

void Move(vector<string>& g, int dir, int& x, int& y, int type) {
  g[x][y] = '.';
  while (g[x][y] == '.') {
    x += DX[dir];
    y += DY[dir];
  }
  if (g[x][y] != 'O') {
    x -= DX[dir];
    y -= DY[dir];
    g[x][y] = "RB"[type];
  }
}

void Dfs(const vector<string>& s, int depth, int _rx, int _ry, int _bx, int _by) {
  for (int dir = 0; dir < 4; dir++) {
    vector<string> g = s;
    int rx = _rx;
    int ry = _ry;
    int bx = _bx;
    int by = _by;
    if (Cmp(dir, rx, ry, bx, by)) {
      Move(g, dir, bx, by, 1);
      Move(g, dir, rx, ry, 0);
    } else {
      Move(g, dir, rx, ry, 0);
      Move(g, dir, bx, by, 1);
    }
    if (g[bx][by] == 'O') {
      continue;
    }
    if (g[rx][ry] == 'O') {
      ans = min(ans, depth);
      return;
    }
    if (depth + 1 < ans) {
      Dfs(g, depth + 1, rx, ry, bx, by);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int rx = -1, ry = -1;
  int bx = -1, by = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'R') {
        rx = i;
        ry = j;
      }
      if (s[i][j] == 'B') {
        bx = i;
        by = j;
      }
    }
  }
  Dfs(s, 1, rx, ry, bx, by);
  if (ans == 11) ans = -1;
  cout << ans << '\n';
  return 0;
}
