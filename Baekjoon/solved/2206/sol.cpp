#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int N = 1000;
const int inf = (int) 1e9;

int n, m;
string a[N];
int dis[N][N][2];

int bfs(int x, int y) {
  vector<tuple<int, int, bool>> q;
  fill_n(dis[0][0], N * N * 2, inf);
  q.emplace_back(x, y, false);
  dis[x][y][0] = 1;
  for (int i = 0; i < (int) q.size(); i++) {
    bool dig;
    tie(x, y, dig) = q[i];
    for (int j = 0; j < 4; j++) {
      int u = x + "2101"[j] - '1';
      int v = y + "1210"[j] - '1';
      if (u < 0 || u >= n || v < 0 || v >= m) continue;
      int type = a[u][v] - '0' + dig;
      if (type == 2 || dis[u][v][type] < inf) continue;
      dis[u][v][type] = dis[x][y][dig] + 1;
      q.emplace_back(u, v, (bool) type);
    }
  }
  return min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = bfs(0, 0);
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}