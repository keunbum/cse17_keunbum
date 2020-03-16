#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int sx = 0; sx < h; sx++) {
    for (int sy = 0; sy < w; sy++) {
      if (s[sx][sy] == 'W') {
        continue;
      }
      vector<pair<int, int>> que;
      que.emplace_back(sx, sy);
      vector<vector<int>> dist(h, vector<int>(w, -1));
      dist[sx][sy] = 0;
      for (int ptr = 0; ptr < (int) que.size(); ptr++) {
        int x, y;
        tie(x, y) = que[ptr];
        for (int dir = 0; dir < 4; dir++) {
          int nx = x + "2101"[dir] - '1';
          int ny = y + "1210"[dir] - '1';
          if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] == 'L' && dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            que.emplace_back(nx, ny);
          }
        }
      }
      ans = max(ans, dist[que.back().first][que.back().second]);
    }
  }
  cout << ans << '\n';
  return 0;
}
