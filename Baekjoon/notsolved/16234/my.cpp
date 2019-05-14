#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, L, R;
int a[56][56];
bool dis[56][56];
vector< vector< pair<int, int> > > v;

void dfs(int r, int c, bool first) {
  if (dis[r][c]) return;
  dis[r][c] = true;
  if (first) v.push_back(vector< pair<int, int> >());
  int nn = v.size();
  v[nn - 1].emplace_back(r, c);
  for (int i = 0; i < 4; i++) {
    int x = r + "2101"[i] - '1';
    int y = c + "1210"[i] - '1';
    if (x < 0 || x >= n || y < 0 || y >= n || abs(a[r][c] - a[x][y]) < L || abs(a[r][c] - a[x][y]) > R || dis[x][y]) continue;
    dfs(x, y, false);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> L >> R;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  while (1) {
    memset(dis, false, sizeof(dis));
    v.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dfs(i, j, true);
      }
    }
    int nn = v.size();
    bool ok = false;
    for (int i = 0; i < nn; i++) {
      int ss = v[i].size();
      if (ss != 1) ok = true;
      int sum = 0;
      for (int j = 0; j < ss; j++) {
        sum += a[v[i][j].first][v[i][j].second];
      }
      sum /= ss;
      for (int j = 0; j < ss; j++) {
        a[v[i][j].first][v[i][j].second] = sum;
      }
    }
    if (!ok) break;
    ans++;
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
