#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

struct Edge {
  int from;
  int to;
  int cost;

  bool operator<(const Edge& o) {
    return cost < o.cost;
  }
};

int IsIn(int x, int y, int h, int w) {
  return x >= 0 && y >= 0 && x < h && y < w;
}

int Get(int v, vector<int>& p) {
  return v == p[v] ? v : (p[v] = Get(p[v], p));
}

void Bfs(vector<vector<int>>& a, int sx, int sy) {
  int h = (int) a.size();
  int w = (int) a[0].size();
  vector<pair<int, int>> q;
  q.emplace_back(sx, sy);
  for (int i = 0; i < (int) q.size(); i++) {
    int x, y;
    tie(x, y) = q[i];
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      if (IsIn(nx, ny, h, w) && a[nx][ny] == -1) {
        a[nx][ny] = a[sx][sy];
        q.emplace_back(nx, ny);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      a[i][j] -= 2;
    }
  }
  int v_cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == -1) {
        a[i][j] = v_cnt++;
        Bfs(a, i, j);
      }
    }
  }
  vector<Edge> edges;
  for (int sx = 0; sx < h; sx++) {
    for (int sy = 0; sy < w; sy++) {
      if (a[sx][sy] == -2) {
        continue;
      }
      for (int dir = 0; dir < 2; dir++) {
        int cx = sx + DX[dir];
        int cy = sy + DY[dir];
        int len = 0;
        while (IsIn(cx, cy, h, w) && a[cx][cy] == -2) {
          ++len;
          cx += DX[dir];
          cy += DY[dir];
        }
        if (IsIn(cx, cy, h, w) && len >= 2) {
          edges.push_back({a[sx][sy], a[cx][cy], len});
        }
      }
    }
  }
  sort(edges.begin(), edges.end());
  vector<int> p(v_cnt);
  iota(p.begin(), p.end(), 0);
  int ans = 0;
  for (const Edge& e : edges) {
    int x = Get(e.from, p);
    int y = Get(e.to, p);
    if (x != y) {
      p[x] = y;
      ans += e.cost;
    }
  }
  bool ok = true;
  int root = Get(0, p);
  for (int i = 1; i < v_cnt; i++) {
    if (Get(i, p) != root) {
      ok = false;
      break;
    }
  }
  cout << (ok ? ans : -1) << '\n';
  return 0;
}
