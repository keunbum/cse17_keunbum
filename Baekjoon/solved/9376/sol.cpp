#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int HW = 110;
const int MAX = 20200;

char s[HW][HW];
int qx[MAX];
int qy[MAX];

void RunBfs(const char[HW][HW], int sx, int sy, vector<vector<int>>& dist) {
  int h = dist.size();
  int w = dist[0].size();
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dist[i][j] = -1;
    }
  }
  int b = MAX / 2, e = MAX / 2 + 1;
  qx[b] = sx;
  qy[b] = sy;
  dist[sx][sy] = 0;
  while (b < e) {
    int x = qx[b];
    int y = qy[b];
    ++b;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] != '*' && dist[nx][ny] == -1) {
        if (s[nx][ny] == '#') {
          dist[nx][ny] = dist[x][y] + 1;
          qx[e] = nx;
          qy[e] = ny;
          ++e;
        } else {
          dist[nx][ny] = dist[x][y];
          --b;
          qx[b] = nx;
          qy[b] = ny;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
      cin >> (s[i] + 1);
    }
    {
      for (int j = 0; j < w + 2; j++) {
        s[0][j] = '.';
        s[h + 1][j] = '.';
      }
      for (int i = 0; i < h + 2; i++) {
        s[i][0] = '.';
        s[i][w + 1] = '.';
      }
    }
    int sx[2] = {-1, -1}, sy[2] = {-1, -1};
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (s[i][j] == '$') {
          if (sx[0] == -1) {
            sx[0] = i;
            sy[0] = j;
          } else {
            sx[1] = i;
            sy[1] = j;
          }
        }
      }
    }
    vector<vector<int>> dist(h + 2, vector<int>(w + 2));
    RunBfs(s, sx[0], sy[0], dist);
    vector<vector<int>> dist_a = dist;
    RunBfs(s, sx[1], sy[1], dist);
    vector<vector<int>> dist_b = dist;
    RunBfs(s, 0, 0, dist);
    vector<vector<int>> dist_c = dist;
    int ans = dist_a[0][0] + dist_b[0][0] + dist_c[0][0];
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (s[i][j] == '*') {
          continue;
        }
        ans = min(ans, dist_a[i][j] + dist_b[i][j] + dist_c[i][j] - 2 * (int) (s[i][j] == '#')); 
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
