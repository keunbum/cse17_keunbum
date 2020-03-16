#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool a[50][50];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      if (c == 'L') a[i][j] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!a[i][j]) continue;
      int tmp[50][50];
      memset(tmp, 0xff, sizeof(tmp));
      vector< pair<int, int> > que;
      tmp[i][j] = 0;
      que.emplace_back(i, j);
      int k;
      for (k = 0; k < que.size(); k++) {
        for (int l = 0; l < 4; l++) {
          int nx = que[k].first + "2101"[l] - '1';
          int ny = que[k].second + "1210"[l] - '1';
          if (nx < 0 || nx >= h || ny < 0 || ny >= w || !a[nx][ny] || tmp[nx][ny] != -1) continue;
          tmp[nx][ny] = tmp[que[k].first][que[k].second] + 1;
          que.emplace_back(nx, ny);
        }
      }
      ans = max(ans, tmp[que[k - 1].first][que[k - 1].second]);
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
