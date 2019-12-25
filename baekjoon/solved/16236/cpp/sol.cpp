#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[23][23];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 9) {
        x = i;
        y = j;
        a[i][j] = 0;
      }
    }
  }
  int time = 0, me = 2, cnt = 0;
  while (1) {
    int dis[23][23];
    memset(dis, -1, sizeof(dis));
    vector< pair<int, int> > que(1, make_pair(x, y));
    dis[x][y] = 0;
    for (int i = 0; i < que.size(); i++) {
      for (int j = 0; j < 4; j++) {
        int nx = que[i].first + "2101"[j] - '1';
        int ny = que[i].second + "1210"[j] - '1';
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] > me || dis[nx][ny] != -1) continue;
        dis[nx][ny] = dis[que[i].first][que[i].second] + 1;
        que.emplace_back(nx, ny);
      }
    }
    int mn = 1 << 30;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dis[i][j] != -1 && a[i][j] > 0 && a[i][j] < me) {
          if (mn > dis[i][j]) {
            mn = dis[i][j];
            x = i;
            y = j;
          }
        }
      }
    }
    if (mn == (1 << 30)) break;
    a[x][y] = 0;
    if (++cnt == me) {
      me++;
      cnt = 0;
    }
    time += mn;  
  }
  cout << time << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
