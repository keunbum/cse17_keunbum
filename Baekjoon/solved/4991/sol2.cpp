#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int inf = (int) 1e9;
const int MAXV = 410;

int qx[MAXV];
int qy[MAXV];

int RunBfs(vector<string>& s, int sx, int sy, int ex, int ey) {
  int h = (int) s.size();
  int w = (int) s[0].size();
  vector<vector<int>> dist(h, vector<int>(w, -1));
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
  return dist[ex][ey] == -1 ? inf : dist[ex][ey];
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
      for (int j = 0; j < n; j++) {
        cost[i][j] = cost[j][i] = RunBfs(s, a[i].first, a[i].second, a[j].first, a[j].second);
      }
    }
    vector<vector<int>> dp(n, vector<int>(1 << n, inf));
    for (int i = 0; i < n; i++) {
      dp[i][1 << i] = RunBfs(s, sx, sy, a[i].first, a[i].second);
    }
    for (int t = 0; t < (1 << n); t++) {
      for (int i = 0; i < n; i++) {
        if (dp[i][t] < inf) {
          for (int j = 0; j < n; j++) {
            if ((t & (1 << j)) == 0) {
              dp[j][t | (1 << j)] = min(dp[j][t | (1 << j)], dp[i][t] + cost[j][i]);
            }
          }
        }
      }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
      ans = min(ans, dp[i][(1 << n) - 1]);
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
