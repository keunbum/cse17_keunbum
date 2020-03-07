#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int inf = (int) 1e9;
const int MAXV = 410;

int qx[MAXV];
int qy[MAXV];

void RunBfs(vector<string>& s, int sx, int sy, vector<vector<int>>& dist) {
  int h = (int) s.size();
  int w = (int) s[0].size();
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dist[i][j] = -1;
    }
  }
  int b = 0;
  int e = 1;
  qx[b] = sx;
  qy[b] = sy;
  dist[sx][sy] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] != 'x' && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
        qx[e] = nx;
        qy[e] = ny;
        ++e;
      }
    }
    ++b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    vector<string> s(h);
    int sx = -1;
    int sy = -1;
    vector<pair<int, int>> a;
    for (int i = 0; i < h; i++) {
      cin >> s[i];
      for (int j = 0; j < w; j++) {
        if (s[i][j] == 'o') {
          sx = i;
          sy = j;
        }
        if (s[i][j] == '*') {
          a.emplace_back(i, j);
        }
      }
    }
    int n = (int) a.size();
    if (n == 0) {
      cout << "-1\n";
      continue;
    }
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      vector<vector<int>> dist(h, vector<int>(w));
      RunBfs(s, a[i].first, a[i].second, dist);
      for (int j = 0; j < n; j++) {
        cost[i][j] = dist[a[j].first][a[j].second];
      }
    }
    vector<int> init_dist(n);
    {
      vector<vector<int>> dist(h, vector<int>(w));
      RunBfs(s, sx, sy, dist);
      for (int i = 0; i < n; i++) {
        init_dist[i] = dist[a[i].first][a[i].second];
      }
    }
    int ans = inf;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
      int dist = init_dist[p[0]];
      for (int i = 0; i < n - 1; i++) {
        if (cost[p[i]][p[i + 1]] == -1) {
          dist = inf;
          break;
        }
        dist += cost[p[i]][p[i + 1]];
      }
      ans = min(ans, dist);
    } while (next_permutation(p.begin(), p.end()));
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
